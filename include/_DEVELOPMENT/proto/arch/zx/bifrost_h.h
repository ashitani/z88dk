include(__link__.m4)

#ifndef __BIFROST_H_H__
#define __BIFROST_H_H__

/* ----------------------------------------------------------------
 * Z88DK INTERFACE LIBRARY FOR THE BIFROST* ENGINE - RELEASE 1.2/H
 *
 * If you use this interface library, you must load afterwards the
 * BIFROST* ENGINE and a multicolor tile set. For a detailed sample
 * see file "bifrostdem.c".
 *
 * Original version and further information is available at
 * http://www.worldofspectrum.org/infoseekid.cgi?id=0027405
 *
 * Copyleft (k) Einar Saukas, Timmy
 * Additional improvements provided by Alcoholics Anonymous
 * ----------------------------------------------------------------
 */

// ----------------------------------------------------------------
// Constants
// ----------------------------------------------------------------

extern unsigned char BIFROSTH_tilemap[81];

#define BIFROSTH_STATIC    128
#define BIFROSTH_DISABLED  255

// ----------------------------------------------------------------
// Activate multicolor rendering with BIFROST* ENGINE
// ----------------------------------------------------------------

__OPROTO(,,void,,BIFROSTH_start,void)

// ----------------------------------------------------------------
// Deactivate multicolor rendering with BIFROST* ENGINE
// ----------------------------------------------------------------

__OPROTO(,,void,,BIFROSTH_stop,void)

// ----------------------------------------------------------------
// Execute HALT (wait for next frame).
//
// If an interrupt occurs while certain routines (BIFROSTH_drawTileH,
// BIFROSTH_showTilePosH, BIFROSTH_showNextTile, etc) are under
// execution, the program may crash.
//
// Routine BIFROSTH_halt can be used to avoid these problems.
// Immediately after calling it, your program will have some time
// (about 20K T) to execute a few other routines without any
// interruption.
// ----------------------------------------------------------------

#ifdef __SDCC

#define BIFROSTH_halt()  __asm__("halt\n")

#else

#define BIFROSTH_halt()  asm("halt\n")

#endif

// ----------------------------------------------------------------
// Place a multicolor tile index into the tile map. Add value
// BIFROSTH_STATIC for static tile, otherwise it will be animated
//
// Parameters:
//     px: tile vertical position (0-8)
//     py: tile horizontal position (0-8)
//     tile: tile index (0-255)
//
// Obs: Also available as inline macro (for constant parameters)
// ----------------------------------------------------------------

__DPROTO(,,void,,BIFROSTH_setTile,unsigned int px, unsigned int py, unsigned int tile)

#define M_BIFROSTH_SETTILE(px, py, tile)  BIFROSTH_tilemap[(px)*9+(py)] = (tile)

// ----------------------------------------------------------------
// Obtain a multicolor tile index from the tile map
//
// Parameters:
//     px: tile vertical position (0-8)
//     py: tile horizontal position (0-8)
//
// Returns:
//     Tile index currently stored in this position
//
// Obs: Also available as inline macro (for constant parameters)
// ----------------------------------------------------------------

__DPROTO(,,unsigned char,,BIFROSTH_getTile,unsigned int px, unsigned int py)

#define M_BIFROSTH_GETTILE(px, py)   BIFROSTH_tilemap[(px)*9+(py)]

// ----------------------------------------------------------------
// Convert multicolor tile index into the equivalent animation group
//
// Parameters:
//     tile: tile index (0-255)
//
// Returns:
//     Animation group for animated tile, otherwise the same tile index
// ----------------------------------------------------------------

__DPROTO(,,unsigned char,,BIFROSTH_getAnimGroup,unsigned int tile)

// ----------------------------------------------------------------
// Locate memory address that stores the multicolor attribute of a
// certain screen position inside the multicolor area
//
// Parameters:
//     lin: pixel line (16-159)
//     col: char column (1-18)
//
// Returns:
//     Memory address of the multicolor attribute
// ----------------------------------------------------------------

__DPROTO(,,unsigned char,*,BIFROSTH_findAttrH,unsigned int lin, unsigned int col)

// ----------------------------------------------------------------
// Reconfigure BIFROST* ENGINE to read tile images from another address
//
// Parameters:
//     addr: New tile images address
// ----------------------------------------------------------------

__DPROTO(,,void,,BIFROSTH_resetTileImages,void *addr)

// ----------------------------------------------------------------
// Reconfigure BIFROST* ENGINE to animate at 2 frames per second
// ----------------------------------------------------------------

#define BIFROSTH_resetAnimSlow()  *((unsigned char*)59035)=254

// ----------------------------------------------------------------
// Reconfigure BIFROST* ENGINE to animate at 4 frames per second
// ----------------------------------------------------------------

#define BIFROSTH_resetAnimFast()  *((unsigned char*)59035)=198

// ----------------------------------------------------------------
// Reconfigure BIFROST* ENGINE to use 2 frames per animation group
// ----------------------------------------------------------------

__OPROTO(,,void,,BIFROSTH_resetAnim2Frames,void)

// ----------------------------------------------------------------
// Reconfigure BIFROST* ENGINE to use 4 frames per animation group
// ----------------------------------------------------------------

__OPROTO(,,void,,BIFROSTH_resetAnim4Frames,void)

// ----------------------------------------------------------------
// Advanced conversions
// ----------------------------------------------------------------

#define PX2LIN(px)              (((px)+1)<<4)
#define PX2ROW(px)              (((px)<<1)+1)

#define ROW2LIN(row)            (((row)+1)<<3)
#define ROW2PX_UP(row)          ((row)>>1)
#define ROW2PX_DOWN(row)        (((row)-1)>>1)

#define LIN2ROW_UP(lin)         (((lin)>>3)-1)
#define LIN2ROW_DOWN(lin)       (((lin)-1)>>3)
#define LIN2PX_UP(lin)          (((lin)>>4)-1)
#define LIN2PX_DOWN(lin)        (((lin)-1)>>4)

#define PY2COL(py)              (((py)<<1)+1)
#define COL2PY_LEFT(col)        (((col)-1)>>1)
#define COL2PY_RIGHT(col)       ((col)>>1)

// ----------------------------------------------------------------
// Instantly draw a multicolor tile at the specified screen position
//
// Parameters:
//     lin: pixel line (0-160)
//     col: char column (0-18)
//     tile: tile index (0-255)
//
// WARNING: If this routine is under execution when interrupt
//          occurs, program may crash!!! (see BIFROSTH_halt)
// ----------------------------------------------------------------

__DPROTO(,,void,,BIFROSTH_drawTileH,unsigned int lin, unsigned int col, unsigned int tile)

// ----------------------------------------------------------------
// Instantly show/animate the multicolor tile currently stored in
// the specified tile map position
//
// Parameters:
//     lin: pixel line (16,32,48..144)
//     col: char column (1,3,5..17)
//
// WARNING: If this routine is under execution when interrupt
//          occurs, program may crash!!! (see BIFROSTH_halt)
// ----------------------------------------------------------------

__DPROTO(,,void,,BIFROSTH_showTilePosH,unsigned int lin, unsigned int col)

// ----------------------------------------------------------------
// Instantly show/animate the next multicolor tile currently stored
// in the tile map position, according to a pre-established drawing
// order
//
// WARNING: If this routine is under execution when interrupt
//          occurs, program may crash!!! (see BIFROSTH_halt)
// ----------------------------------------------------------------

__OPROTO(,,void,,BIFROSTH_showNextTile,void)

// ----------------------------------------------------------------
// Instantly change the attributes in a tile area (16x16 pixels) to
// the specified value (use the same INK and PAPER values to "erase"
// a tile)
//
// Parameters:
//     lin: pixel line (0-160)
//     col: char column (0-18)
//     attr: attribute value (0-255), INK+8*PAPER+64*BRIGHT+128*FLASH
//
// WARNING: If this routine is under execution when interrupt
//          occurs, program may crash!!! (see BIFROSTH_halt)
// ----------------------------------------------------------------

__DPROTO(,,void,,BIFROSTH_fillTileAttrH,unsigned int lin, unsigned int col, unsigned int attr)

// ----------------------------------------------------------------
// Sprite addresses
// ----------------------------------------------------------------
#define BIFROSTHSPRITE1LIN   ((unsigned char *)58056)
#define BIFROSTHSPRITE1COL   ((unsigned char *)58055)
#define BIFROSTHSPRITE1TILE  ((unsigned char *)58058)
#define BIFROSTHSPRITE2LIN   ((unsigned char *)58065)
#define BIFROSTHSPRITE2COL   ((unsigned char *)58064)
#define BIFROSTHSPRITE2TILE  ((unsigned char *)58067)

// ----------------------------------------------------------------
// Reconfigure BIFROST* ENGINE to draw sprites at every frame
//
// NOTE: Regular tiles will be updated/animated at 2 frames per
// second (slow)
// ----------------------------------------------------------------

//#define BIFROSTH_enableSprites()   *((unsigned int*)59040)=58054

__OPROTO(,,void,,BIFROSTH_enableSprites,void)

// ----------------------------------------------------------------
// Reconfigure BIFROST* ENGINE to stop drawing sprites
// ----------------------------------------------------------------

//#define BIFROSTH_disableSprites()   *((unsigned int*)59040)=58636

__OPROTO(,,void,,BIFROSTH_disableSprites,void)

// ----------------------------------------------------------------
// Instantly redraw all multicolor tiles stored in tile map positions
// behind the specified screen position. Positions that store value
// BIFROSTDISABLED in the tile map are "erased" by filling the position
// with the specified attribute
//
// Parameters:
//     lin: pixel line (0-160)
//     col: char column (0-18)
//     attr: attribute value (0-255), INK+8*PAPER+64*BRIGHT+128*FLASH
//
// WARNING: If this routine is under execution when interrupt
//          occurs, program may crash!!! (see BIFROSTH_halt)
// ----------------------------------------------------------------

__DPROTO(,,void,,BIFROSTH_drawBackTilesH,unsigned int lin,unsigned int col,unsigned int attr)

// ----------------------------------------------------------------
// Instantly redraw the multicolor tile currently stored in the
// specified tile map position. If this position stores value
// BIFROSTH_DISABLED in the tile map, it will be "erased" by filling
// its position with the specified attribute
//
// Parameters:
//     lin: pixel line (0-160)
//     col: char column (0-18)
//     attr: attribute value (0-255), INK+8*PAPER+64*BRIGHT+128*FLASH
//
// WARNING: If this routine is under execution when interrupt
//          occurs, program may crash!!! (see BIFROSTH_halt)
// ----------------------------------------------------------------

__DPROTO(,,void,,BIFROSTH_drawTilePosH,unsigned int lin, unsigned int col, unsigned int attr)

#endif
