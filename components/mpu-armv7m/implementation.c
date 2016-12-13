/*| headers |*/
{{#memory_protection}}
{{#verbose_protection_faults}}
#include "debug.h"
{{/verbose_protection_faults}}
{{/memory_protection}}

/*| object_like_macros |*/
{{#memory_protection}}
/* MPU-related constants */
#define MPU_MAX_REGIONS             8
#define MPU_BUILTIN_REGIONS         2           /* Stack & flash regions           */
#define MPU_MAX_ASSOCIATED_DOMAINS  MPU_MAX_REGIONS-MPU_BUILTIN_REGIONS

/* MPU control registers */
#define MPU_TYPE                    0xE000ED90  /* MPU Type                        */
#define MPU_CTRL                    0xE000ED94  /* MPU Control                     */
#define MPU_NUMBER                  0xE000ED98  /* MPU Region Number               */
#define MPU_BASE                    0xE000ED9C  /* MPU Region Base Address         */
#define MPU_ATTR                    0xE000EDA0  /* MPU Region Attribute and Size   */
                                                /* We exclude the additional alias
                                                 * regions as they are unavailable
                                                 * on some processors */
/* MPU interrupt registers */
#define SYS_HND_CTRL                0xE000ED24  /* System Handler Control and State */
#define SYS_HND_CTRL_MEM            0x00010000  /* Memory Management Fault Enable   */

/* MPU fault status registers */
#define NVIC_FAULT_STAT             0xE000ED28  /* Configurable Fault Status        */
#define NVIC_MM_ADDR                0xE000ED34  /* Memory Management Fault Address  */

/* MPU type bitfields */
#define MPU_TYPE_DREGION_M          0x0000FF00  /* Number of D Regions             */
#define MPU_TYPE_SEPARATE           0x00000001  /* Separate or Unified MPU         */
#define MPU_TYPE_DREGION_S          8

/* MPU base bitfields */
#define MPU_BASE_ADDR_M             0xFFFFFFE0  /* Base Address Mask               */
#define MPU_BASE_VALID              0x00000010  /* Region Number Valid             */
#define MPU_BASE_REGION_M           0x00000007  /* Region Number                   */
#define MPU_BASE_ADDR_S             5
#define MPU_BASE_REGION_S           0

/* MPU control flags */
#define MPU_CTRL_ENABLE             0x00000001  /* MPU Enable                      */

/* MPU enable flags */
#define MPU_CONFIG_PRIV_DEFAULT     4
#define MPU_CONFIG_HARDFLT_NMI      2

/* MPU region enable flags */
#define MPU_RGN_ENABLE              1

/* MPU region permission flags */
#define MPU_P_EXEC                  0x00000000
#define MPU_P_NOEXEC                0x10000000
#define MPU_P_NO                    0x01000000  /* RW for priv, no access for user */
#define MPU_P_RO                    0x02000000  /* RW for priv, read-only for user access */
#define MPU_P_RW                    0x03000000  /* Read-Write for privileged and user access */

/* MPU memory type flags */
#define MPU_ATTR_TEX_M              0x00380000
#define MPU_ATTR_SHAREABLE          0x00040000
#define MPU_ATTR_CACHEABLE          0x00020000
#define MPU_ATTR_BUFFRABLE          0x00010000

/* MPU region attribute flags */
#define MPU_ATTR_SIZE_M             0x0000003E  /* Region Size Mask */
#define MPU_ATTR_ENABLE             0x00000001  /* Region Enable    */
{{/memory_protection}}

/*| types |*/

/*| structures |*/
{{#memory_protection}}
struct mpu_region {
    uint32_t base_addr;
    uint32_t flags;
};

static struct mpu_region mpu_regions[{{tasks.length}}][MPU_MAX_REGIONS-1];
{{/memory_protection}}

/*| extern_declarations |*/
{{#memory_protection}}
/* These declarations allow us to use symbols that were declared inside the
 * linker script. For flash & sram this is necessary as these parameters
 * are part of the vectable module. For protection domains, this is necessary
 * as the location of protection domains is computed at link-time.
 *
 * Note the *address* of these symbols must be taken to get their value.
 * This should always be through the 'linker_value' macro defined below.*/
extern uint32_t linker_flash_size;
extern uint32_t linker_sram_size;
extern uint32_t linker_code_start;
{{#protection_domains}}
extern uint32_t linker_domain_{{name}}_start;
extern uint32_t linker_domain_{{name}}_size;
{{/protection_domains}}
{{/memory_protection}}

/*| function_declarations |*/
{{#memory_protection}}
bool mpu_is_enabled(void);
void mpu_enable(void);
void mpu_disable(void);
uint32_t mpu_regions_supported_get(void);
void mpu_region_enable(uint32_t mpu_region);
void mpu_region_disable(uint32_t mpu_region);
void mpu_region_set(uint32_t mpu_region, uint32_t mpu_addr, uint32_t mpu_flags);
void mpu_memmanage_interrupt_enable(void);
uint32_t mpu_region_size_flag(uint32_t bytes);
void mpu_configure_for_task(const {{prefix_type}}TaskId to);
{{/memory_protection}}

/*| state |*/
uint32_t mpu_was_enabled = 0;

/*| function_like_macros |*/
{{#memory_protection}}
#define hardware_register(x) (*((volatile uint32_t *)(x)))
#define is_pow2(x) (x && !(x & (x - 1)))
#define linker_value(x) ((uint32_t)&x)
{{/memory_protection}}

/*| functions |*/
{{#memory_protection}}
bool
mpu_is_enabled(void)
{
    return (hardware_register(MPU_CTRL) & MPU_CTRL_ENABLE);
}

void
mpu_enable(void)
{
    internal_assert(!mpu_is_enabled(), ERROR_ID_MPU_ALREADY_ENABLED );

    /* Turn on the MPU */
    hardware_register(MPU_CTRL) |= MPU_CTRL_ENABLE;
}

void
mpu_disable(void)
{
    internal_assert(mpu_is_enabled(), ERROR_ID_MPU_ALREADY_DISABLED);

    hardware_register(MPU_CTRL) &= ~MPU_CTRL_ENABLE;
}

/* Gets the number of hardware regions supported by this MPU */
uint32_t
mpu_hardware_regions_supported(void)
{
    /* Read the DREGION field of the MPU type register and mask off   */
    /* the bits of interest to get the count of regions.              */
    return ((hardware_register(MPU_TYPE) & MPU_TYPE_DREGION_M) >> MPU_TYPE_DREGION_S);
}

/* Does our hardware have unified I & D regions? */
uint32_t
mpu_hardware_is_unified(void)
{
    return !(hardware_register(MPU_TYPE) & MPU_TYPE_SEPARATE);
}

void
mpu_region_enable(uint32_t mpu_region)
{
    internal_assert(mpu_region < MPU_MAX_REGIONS,
                    ERROR_ID_MPU_INTERNAL_INVALID_REGION_INDEX);

    /* Pick the region we want to modify */
    hardware_register(MPU_NUMBER) = mpu_region;

    /* Enable this region */
    hardware_register(MPU_ATTR) |= MPU_ATTR_ENABLE;
}

void
mpu_region_disable(uint32_t mpu_region)
{
    internal_assert(mpu_region < MPU_MAX_REGIONS,
                    ERROR_ID_MPU_INTERNAL_INVALID_REGION_INDEX);

    hardware_register(MPU_NUMBER) = mpu_region;
    hardware_register(MPU_ATTR) &= ~MPU_ATTR_ENABLE;
}

void
mpu_region_set(uint32_t mpu_region, uint32_t mpu_addr, uint32_t mpu_flags)
{
    internal_assert(mpu_region < MPU_MAX_REGIONS,
                    ERROR_ID_MPU_INTERNAL_INVALID_REGION_INDEX);

    /* Check that the address is size-aligned as required */
    internal_assert(mpu_addr == (mpu_addr & ~0 << (((mpu_flags & MPU_ATTR_SIZE_M) >> 1) + 1)),
                    ERROR_ID_MPU_INTERNAL_MISALIGNED_ADDR);

    /* Select the region and set the base address at the same time */
    hardware_register(MPU_BASE) = mpu_addr | mpu_region | MPU_BASE_VALID;

    /* Set region attributes, with fixed values for:
     * Type Extension Mask = 0
     * Cacheable = 0
     * Shareable = 1
     * Bufferable = 1
     * These options should be fine on most devices, with a small performance
     * penalty on armv7m processors that have a cache. This is rare though. */
    hardware_register(MPU_ATTR) = ((mpu_flags & ~(MPU_ATTR_TEX_M | MPU_ATTR_CACHEABLE)) |
                                  MPU_ATTR_SHAREABLE | MPU_ATTR_BUFFRABLE);
}

void
mpu_memmanage_interrupt_enable(void)
{
    /* Clear the NVIC FSR as it starts off as junk */
    uint32_t fault_stat = hardware_register(NVIC_FAULT_STAT);
    hardware_register(NVIC_FAULT_STAT) = fault_stat;

    /* Enable the interrupt */
    hardware_register(SYS_HND_CTRL) |= SYS_HND_CTRL_MEM;
}

void
mpu_populate_regions(void)
{
    /* Note: region 0 is always the RX-only flash protection region
     * as set up during MPU initialization, so we use index 0 to
     * actually store region 1 */

    /* We assume that mpu_regions has been initialized to zero
     * as it sits in the .bss section. This is important as
     * we use null regions to check whether to disable them
     * altogether when switching tasks. */

{{#tasks}}
    #if {{associated_domains.length}} > MPU_MAX_ASSOCIATED_DOMAINS
    #error "Too many associated domains for task: {{name}}"
    #endif

    /* Stack region for task: {{name}} */
    mpu_regions[{{idx}}][0].flags =
        mpu_region_size_flag({{stack_size}}*sizeof(uint32_t)) |
        MPU_P_NOEXEC | MPU_P_RW | MPU_RGN_ENABLE;
    mpu_regions[{{idx}}][0].base_addr = (uint32_t)&stack_{{idx}};

    /* Protection domains for task: {{name}} */
{{#associated_domains}}
{{#writeable}}{{^readable}}
    #error "Write-only permissions unsupported on armv7m. Domain: {{name}}"
{{/readable}}{{/writeable}}
    mpu_regions[{{idx}}][{{domx}}+1].base_addr = linker_value(linker_domain_{{name}}_start);
    mpu_regions[{{idx}}][{{domx}}+1].flags =
        mpu_region_size_flag(linker_value(linker_domain_{{name}}_size)) | MPU_RGN_ENABLE |
            {{#readable}}{{^writeable}}MPU_P_RO |{{/writeable}}{{/readable}} /* Read-only? */
            {{#writeable}}{{#readable}}MPU_P_RW |{{/readable}}{{/writeable}} /* Read-write? */
            {{^executable}}MPU_P_NOEXEC{{/executable}}; /* Executable? (no flag = executable) */

{{/associated_domains}}
{{/tasks}}
}


void
mpu_initialize(void)
{
    /* Check hardware registers to see if this processor actually has
     * any MPU hardware. We support MPUs with >= 8 regions and a unified
     * memory model. From the ARM TRM for the Cortex-M series, this
     * encompasses the Cortex M0+, M3, M4 & M7 series processors.
     *
     * The M7 is a bit of a special case in that it has a non-unified
     * option, however I have not found any silicon vendors that actually
     * manufacture a chip using a non-unified MPU. */

    internal_assert(mpu_hardware_regions_supported() >= MPU_MAX_REGIONS,
                    ERROR_ID_MPU_NON_STANDARD);

    internal_assert(mpu_hardware_is_unified(), ERROR_ID_MPU_NON_STANDARD);

    /* Make the MPU use a default region in privileged mode, disable it during a hard fault */
    hardware_register(MPU_CTRL) |= MPU_CONFIG_PRIV_DEFAULT;
    hardware_register(MPU_CTRL) &= ~(MPU_CONFIG_HARDFLT_NMI);

    /* Initially, we will only give tasks access to:
     * - Their own stack
     * - Any specifically annotated extra memory regions.
     * We make code read-only, however we do not protect tasks
     * from reading/executing code that is not theirs. This
     * model of protecting data but not the code is standard.
     * See SLOTH, or AUTOSAR OS specifications v5.0.0 */

    /* Create a read-only executable region for our FLASH */
    uint32_t flash_size = linker_value(linker_flash_size);
    mpu_region_set(0, linker_value(linker_code_start), mpu_region_size_flag(flash_size) |
                   MPU_P_EXEC | MPU_P_RO | MPU_RGN_ENABLE);

    /* fill up our region table for each task */
    mpu_populate_regions();

    /* Enable the memmanage interrupt */
    mpu_memmanage_interrupt_enable();

    /* The MPU itself will only enforce memory protection rules
     * in usermode. We leave it on for the lifetime of our system. */
    mpu_enable();
}

uint32_t
mpu_region_size_flag(uint32_t bytes)
{
    /* armv7m MPU only supports regions of 2^n size, above 32 bytes */
    internal_assert(is_pow2(bytes), ERROR_ID_MPU_INVALID_REGION_SIZE);
    internal_assert(bytes >= 32, ERROR_ID_MPU_INVALID_REGION_SIZE);

    /* MPU region size flag for 2^x bytes is (x-1)<<1
     * Count trailing zeros to get log2(x), valid as x is a power of 2 */
    return ((__builtin_ctz(bytes) - 1) << 1);
}


void
mpu_configure_for_current_task(void)
{
    /* Note: region 0 is always the RX-only flash protection region
     * as set up during MPU initialization, so we do not touch that.
     * To save space, mpu_regions[x][0] corresponds to MPU region 1.*/

    /* We simply enable and set parameters for the regions we are using
     * and then disable all the regions that we aren't */

    {{prefix_type}}TaskId to = rtos_internal_current_task;
    int i = 0;
    for(; i != MPU_MAX_REGIONS-1; ++i) {
        if(mpu_regions[to][i].flags) {
            mpu_region_set(i+1,
                    mpu_regions[to][i].base_addr,
                    mpu_regions[to][i].flags);
        } else {
            mpu_region_disable(i+1);
        }
    }
}

bool
rtos_internal_memmanage_handler(void)
{
    uint32_t fault_status  = hardware_register(NVIC_FAULT_STAT);

{{#verbose_protection_faults}}
    uint32_t fault_address = hardware_register(NVIC_MM_ADDR);
    debug_print("protection fault: [address=");
    debug_printhex32(fault_address);
    debug_print(", status=");
    debug_printhex32(fault_status);
    debug_print("]\n");
{{/verbose_protection_faults}}

    /* Clear the fault status register */
    hardware_register(NVIC_FAULT_STAT) = fault_status;

    /* Turn off the MPU in case we managed to block ourselves
     * from doing memory accesses in privileged mode */
    mpu_disable();

    /* An MPU policy violation is a fatal error (for now) */
    {{fatal_error}}(ERROR_ID_MPU_VIOLATION);

    return true;
}
{{/memory_protection}}

/*| public_functions |*/

/*| public_privileged_functions |*/
