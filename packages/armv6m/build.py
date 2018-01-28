#
# eChronos Real-Time Operating System
# Copyright (c) 2017, Commonwealth Scientific and Industrial Research
# Organisation (CSIRO) ABN 41 687 119 230.
#
# All rights reserved. CSIRO is willing to grant you a licence to the eChronos
# real-time operating system under the terms of the CSIRO_BSD_MIT license. See
# the file "LICENSE_CSIRO_BSD_MIT.txt" for details.
#
# @TAG(CSIRO_BSD_MIT)
#

import os
from prj import execute, commonpath


def run(system, _=None):
    return system_build(system)


def system_build(system):
    inc_path_args = ['-I%s' % i for i in system.include_paths]
    common_flags = ['-mthumb', '-g3']

    if system.compiler_flags == []:
        common_flags += '-march=armv6-m'
    else:
        common_flags += system.compiler_flags

    a_flags = common_flags
    a_flags.remove('-msoft-float')

    c_flags = common_flags + ['-O0']

    for define in system.defines:
        c_flags += ['-D{}'.format(define)]

    all_input_files = system.c_files + system.asm_files
    all_input_files = [os.path.normpath(os.path.abspath(path)) for path in all_input_files]
    common_parent_path = commonpath(all_input_files)

    # Compile all C files.
    c_obj_files = [os.path.join(system.output, os.path.relpath(os.path.abspath(c_file_path.replace('.c', '.o')),
                                                               common_parent_path)) for c_file_path in system.c_files]

    for c_path, obj_path in zip(system.c_files, c_obj_files):
        os.makedirs(os.path.dirname(obj_path), exist_ok=True)
        execute(['arm-none-eabi-gcc', '-ffreestanding', '-c', c_path, '-o', obj_path, '-Wall', '-Werror'] +
                c_flags + inc_path_args)

    # Assemble all asm files.
    asm_obj_files = [os.path.join(system.output, os.path.relpath(os.path.abspath(asm_file_path.replace('.s', '.o')),
                                                                 common_parent_path))
                     for asm_file_path in system.asm_files]
    for asm_file_path, obj_file_path in zip(system.asm_files, asm_obj_files):
        os.makedirs(os.path.dirname(obj_file_path), exist_ok=True)
        execute(['arm-none-eabi-as', '-o', obj_file_path, asm_file_path] + a_flags + inc_path_args)

    library_paths = [os.path.normpath(os.path.abspath(path)) for path in system.libraries]

    # Perform final link
    obj_files = asm_obj_files + c_obj_files + library_paths
    linker_flags = common_flags + ["-ffreestanding", "-nostartfiles"]
    execute(['arm-none-eabi-gcc', '-T', system.linker_script, '-o', system.output_file] + linker_flags + obj_files)