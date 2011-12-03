/**
 * @file   st7565.h
 * @author David <david@edeca.net>
 * @date   November, 2011
 * @brief  Header for ST7565 graphic LCD library.
 * @sa     <a href="http://XXXXX">ST7565 command reference</a>
 * @sa     <a href="http://www.ladyada.net/learn/lcd/st7565.html">Adafruit tutorial</a>
 * @details
 *
 * A library for using the ST7565 graphic LCD in serial (software SPI) mode.
 *
 * This library is a low-level interface to the screen only.  Graphics functions (text, images
 * etc) are separate.
 *
 * In serial mode it is not possible to read data back from the screen, meaning we
 * need a local array to hold the current data.  For a 128*64 screen, this will require
 * 1KiB of RAM.
 *
 * This code has been tested on a PIC 18F26K20 at 64Mhz using the internal PLL.  No
 * adverse effects were noticed at this speed.
 *
 * Example Usage:
 * @code
 *    // TODO
 * @endcode
 *
 * @todo Check timings compared to datasheet, supply a max recommended Fosc.
 */
#ifndef _ST7565_H_
#define _ST7565_H_

// Setup for ST7565R in SPI mode
/** The chip select pin */
#define GLCD_CS1 LATB0
/** The reset pin (this is required and should not be tied high) */
#define GLCD_RESET LATB1
/** The A0 pin, which selects command or data mode */
#define GLCD_A0 LATB2
/** The clock pin */
#define GLCD_SCL LATB3
/** The data pin (required) */
#define GLCD_SDA LATB4

/** Screen width in pixels, tested with 128 */
#define SCREEN_WIDTH 128
/** Screen height in pixels, tested with 64 */
#define SCREEN_HEIGHT 64

/** Command to turn the display on */
#define GLCD_CMD_DISPLAY_ON 	0b10101111
/** Command to turn the display off */
#define GLCD_CMD_DISPLAY_OFF 	0b10101110

/** Sets all points on the screen to normal. */
#define GLCD_CMD_ALL_NORMAL		0b10100100
/** Sets all points on the screen to "on", without affecting the internal screen buffer. */
#define GLCD_CMD_ALL_ON			0b10100101

// Sets LCD display normal or reverse ????
#define GLCD_CMD_DISPLAY_NORMAL	0b10100110
#define GLCD_CMD_DISPLAY_REVERSE	0b10100111

#define GLCD_CMD_ADC_NORMAL		0b10100000
#define GLCD_CMD_ADC_REVERSE	0b10100001

#define GLCD_CMD_BIAS_9			0b10100010
#define GLCD_CMD_BIAS_7			0b10100011

// COM output scan direction, normal or reversed.
#define GLCD_CMD_OUTPUT_NORMAL	0b11000000
#define GLCD_CMD_OUTPUT_REVERSE	0b11001000

#define GLCD_CMD_VOLUME_MODE	0b10000001

#define GLCD_CMD_POWER_CONTROL	0b00101000

#define GLCD_CMD_RESISTOR		0b00100000

#define GLCD_CMD_DISPLAY_START	0b01000000

#define GLCD_CMD_COLUMN_LOWER	0b00000000
#define GLCD_CMD_COLUMN_UPPER	0b00010000
#define GLCD_CMD_SET_PAGE		0b10110000

#define GLCD_CMD_RESET			0b11100010
#define	GLCD_CMD_NOP			0b11100011

/**
 * Initialise the screen.  This should be called first.
 */
void glcd_init();
/**
 * Send a command byte to the screen.  See GLCD_CMD_ constants for
 * a list of commands.
 */
void glcd_command(char);
/** 
 * Send a data byte to the screen. 
 */
void glcd_data(char);
/**
 * Update the screen with the contents of the buffer.
 */
void glcd_refresh();
/**
 * Clear the screen buffer.
 */
void glcd_blank();
/**
 * Set a single pixel 
 * 
 * @param x
 * @param y
 * @param colour 0 = OFF, any other value = ON
 */
void glcd_pixel(unsigned char x, unsigned char y, unsigned char colour);

/** Buffer to hold the current screen contents. */
unsigned char glcd_buffer[SCREEN_WIDTH * SCREEN_HEIGHT];

#endif // _ST7565_H_