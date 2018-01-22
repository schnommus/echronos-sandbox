/**************************************************************************//**
 * @file image.h
 * @brief Pictures for memLCD

 * @version 5.0.0
 ******************************************************************************
 * @section License
 * <b>Copyright 2016 Silicon Labs, Inc. http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

static const char image_bits[] = {

/* Silicon Labs Logo */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xf0, 0xff, 0xff, 0xff, 0xf7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xcf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0x01, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x1f, 0xfc,
    0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x1f, 0xf8,
    0xff, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x1f, 0xf0,
    0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x1f, 0xe0,
    0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x0f, 0xc0,
    0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x07, 0xc0,
    0xff, 0xff, 0x1f, 0xf8, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x01, 0xc0,
    0xff, 0xff, 0x07, 0xfc, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x7f, 0x00, 0x80,
    0xff, 0xff, 0x01, 0xfe, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00, 0x80,
    0xff, 0x7f, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
    0xff, 0x3f, 0x80, 0xff, 0xff, 0xff, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xc0,
    0xff, 0x0f, 0x80, 0xff, 0xff, 0xff, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0xc0,
    0xff, 0x03, 0xc0, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xe0,
    0xff, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xe0,
    0xff, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xf0,
    0x7f, 0x00, 0x80, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0xf8,
    0x3f, 0x00, 0x80, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x0f, 0x00, 0xfc,
    0x1f, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xc0, 0xff, 0xff, 0xff, 0x0f, 0x00, 0xfe,
    0x0f, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0x1f, 0x00, 0xff,
    0x07, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0xff, 0xff, 0x1f, 0x80, 0xff,
    0x07, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf8, 0xff, 0xff, 0x1f, 0xc0, 0xff,
    0x03, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0xf0, 0xff,
    0x03, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x3f, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0xfc, 0xff,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x07, 0xfe, 0xff,
    0x01, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x83, 0xff, 0xff,
    0x01, 0x00, 0xc0, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xe1, 0xff, 0xff,
    0x03, 0x00, 0xf0, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xf8, 0xff, 0xff,
    0x03, 0x00, 0xf8, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff,
    0x03, 0x00, 0xfe, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff,
    0x07, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x0f, 0x80, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x1f, 0xc0, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x3f, 0xc0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x81, 0xff, 0xff, 0xff, 0x1f, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x03, 0x3e, 0x9f, 0x7f, 0x7e, 0xe0, 0x07, 0x3e, 0xcf, 0xff, 0x9f, 0xff, 0xe3, 0x0f, 0xf8, 0xc0,
    0x01, 0x3e, 0x9f, 0x7f, 0x3e, 0xc0, 0x03, 0x3c, 0xce, 0xff, 0x9f, 0xff, 0xe3, 0x0f, 0x70, 0x80,
    0x79, 0x3e, 0x9f, 0x7f, 0x3e, 0xcf, 0xf3, 0x3c, 0xce, 0xff, 0x9f, 0xff, 0xe3, 0xcf, 0x73, 0x9e,
    0x79, 0x3e, 0x9f, 0x7f, 0x3e, 0xcf, 0xf3, 0x3c, 0xcc, 0xff, 0x9f, 0xff, 0xe3, 0xcf, 0x73, 0x9e,
    0xf9, 0x3f, 0x9f, 0x7f, 0x3e, 0xff, 0xf3, 0x3c, 0xcc, 0xff, 0x9f, 0xff, 0xc9, 0xcf, 0x73, 0xfe,
    0xe1, 0x3f, 0x9f, 0x7f, 0x3e, 0xff, 0xf3, 0x3c, 0xcc, 0xff, 0x9f, 0xff, 0xc9, 0xcf, 0x73, 0xf8,
    0x87, 0x3f, 0x9f, 0x7f, 0x3e, 0xff, 0xf3, 0x3c, 0xc9, 0xff, 0x9f, 0xff, 0xc9, 0x0f, 0xf8, 0xe1,
    0x1f, 0x3e, 0x9f, 0x7f, 0x3e, 0xff, 0xf3, 0x3c, 0xc9, 0xff, 0x9f, 0xff, 0x9c, 0x0f, 0xf8, 0x87,
    0x7f, 0x3e, 0x9f, 0x7f, 0x3e, 0xff, 0xf3, 0x3c, 0xc3, 0xff, 0x9f, 0xff, 0x9c, 0xcf, 0xf3, 0x9f,
    0x7f, 0x3e, 0x9f, 0x7f, 0x3e, 0xff, 0xf3, 0x3c, 0xc3, 0xff, 0x9f, 0xff, 0x80, 0xcf, 0xf3, 0x9f,
    0x79, 0x3e, 0x9f, 0x7f, 0x3e, 0xcf, 0xf3, 0x3c, 0xc7, 0xff, 0x9f, 0x7f, 0x80, 0xcf, 0x73, 0x9e,
    0x79, 0x3e, 0x9f, 0x7f, 0x3e, 0xcf, 0xf3, 0x3c, 0xc7, 0xff, 0x9f, 0x7f, 0x3e, 0xcf, 0x73, 0x9e,
    0x01, 0x3e, 0x1f, 0x70, 0x3e, 0xc0, 0x03, 0x3c, 0xc7, 0xff, 0x1f, 0x70, 0x3e, 0x0f, 0x70, 0x80,
    0x03, 0x3f, 0x1f, 0x70, 0x7e, 0xe0, 0x07, 0x3e, 0xcf, 0xff, 0x1f, 0x70, 0x3e, 0x0f, 0xf8, 0xc0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

 };
