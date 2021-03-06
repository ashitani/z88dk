/*
 *      Graphics Routines
 *
 *      This file holds the declarations for the generic (multi target) graphics routines.
 *
 *	$Id: graphics.h $
 */

#ifndef __GFX_H__
#define __GFX_H__

#include <sys/compiler.h>
#include <stdint.h>

#pragma output graphics


/* Structure to use when opening a window - as per usual, if graph <> 0
 * then open graphics window number with width (pixels) width 
 */

struct window {
        uint8_t number;
        uint8_t x;
        uint8_t y;
        uint8_t width;
        uint8_t depth;
        uint8_t type;
        uint8_t graph;
} ;


/* Fills an area */
extern void __LIB__ fill(int x, int y) __smallc;
/* Plot a pixel to screen */
extern void __LIB__ plot(int x, int y) __smallc;
/* Unplot a pixel */
extern void __LIB__ unplot(int x, int y) __smallc;
/* XORs a pixel on screen */
extern void __LIB__ xorplot(int x, int y) __smallc;
/* Get pixel status */
extern int __LIB__ point(int x, int y) __smallc;
/* Get horizontal or vertical pixel bar, up to 16 pixel long */
extern int __LIB__ multipoint(int hv, int length, int x, int y) __smallc;
/* Draw a line */
extern void __LIB__ draw(int x1, int y1, int x2, int y2) __smallc;
/* Draw a line in 'XOR' mode */
extern void __LIB__ xordraw(int x1, int y1, int x2, int y2) __smallc;
/* Remove a line */
extern void __LIB__ undraw(int x1, int y1, int x2, int y2) __smallc;
/* Relative draw */
extern void __LIB__ drawr(int px, int py) __smallc;
/* Relative draw in XOR mode*/
extern void __LIB__ xordrawr(int px, int py) __smallc;
/* Remove a relative draw */
extern void __LIB__ undrawr(int px, int py) __smallc;
/* Pen up for 'move' */
extern void __LIB__ pen_up(void);
/* Pen down for 'move' */
extern void __LIB__ pen_down(void);
/* Relative draw (keeping pen up or down) */
extern void __LIB__ move(int px, int py) __smallc;
/* Draw up to a sprcified point */
extern void __LIB__ drawto(int x2, int y2) __smallc;
/* Draw up to a sprcified point in XOR mode*/
extern void __LIB__ xordrawto(int x2, int y2) __smallc;
/* Undraw up to a sprcified point */
extern void __LIB__ undrawto(int x2, int y2) __smallc;
/* Draw a box */
extern void __LIB__ drawb(int tlx, int tly, int width, int height) __smallc;
/* Undraw a box */
extern void __LIB__ undrawb(int tlx, int tly, int width, int height) __smallc;
/* Draw a dotted border */
extern void __LIB__ xorborder(int tlx, int tly, int width, int height) __smallc;
/* Draw a circle */
extern void __LIB__ circle(int x, int y, int radius, int skip) __smallc;
/* Undraw a circle */
extern void __LIB__ uncircle(int x, int y, int radius, int skip) __smallc;
/* Init GFX mode and clear map */
extern void __LIB__ clg(void);
/* Clear area of map */
extern void __LIB__ clga(int tlx, int tly, int width, int height) __smallc;

/* pseudo text console support, 4x6 font */
/* when used to replace fputc_cons: -pragma-redirect=fputc_cons=putc4x6 */
extern int __LIB__ putc4x6(char c);
extern int x_4x6;
extern int y_4x6;

/* Get MAX x and y coordinates */
extern int __LIB__ getmaxx(void);
extern int __LIB__ getmaxy(void);

/* The "stencil" object is an evolution of a base concept introduced 
 * by Rafael de Oliveira Jannone in his gfx library: 
 * a convex area is defined by two byte vectors, pointing 
 * respectivelty to the leftmost and the rightmost X coordinates.
 * They're stuffed in a single byte vector, long at least twice the 
 * resolution of the Y axis (getmaxy might be used).
 */
 
/* Set/Reset the couple of vectors being part of a "stencil" */
extern void __LIB__  stencil_init(unsigned char *stencil) __z88dk_fastcall;
/* Add a pixel to a figure defined inside a stencil object */
extern void __LIB__ stencil_add_point(int x, int y, unsigned char *stencil) __smallc;
/* Trace a relative line into a stencil object (extend shape) */
extern void __LIB__ stencil_add_liner(int dx, int dy, unsigned char *stencil) __smallc;
/* Trace a line into a stencil object up to a given coordinate (extend shape) */
extern void __LIB__ stencil_add_lineto(int x2, int y2, unsigned char *stencil) __smallc;
/* Add a side to a figure defined inside a stencil object */
extern void __LIB__ stencil_add_side(int x1, int y1, int x2, int y2, unsigned char *stencil) __smallc;
/* Add a circular shape to a figure defined inside a stencil object */
extern void __LIB__ stencil_add_circle(int x, int y, int radius, int skip, unsigned char *stencil) __smallc;
/* Render an area delimited by a stencil object, with the specified dither intensity (0..11) */
extern void __LIB__ stencil_render(unsigned char *stencil, unsigned char intensity) __smallc;

/* 'Graphic Profiles' are byte streams containing vector and surface descriptions
   they are detailed in <gfxprofile.h> */
extern void __LIB__ draw_profile(int dx, int dy, int scale, unsigned char *metapic) __smallc;

#ifdef Z88
/* Open a z88 window..either graphics or text */
extern int __LIB__ window(struct window *) __smallc;
/* Scroll map left by one pixel */
extern void __LIB__ lscroll(int x, int y, int width, int height, int pixels) __smallc;
/* Scroll map right by one pixel (unwritten) */
extern void __LIB__ rscroll(int x, int y, int width, int height, int pixels) __smallc;
/* Close the map */
extern void __LIB__ closegfx(struct window *) __smallc;
#endif

/* Chunk 4x4 pixel */
extern void __LIB__ c_plot(int x, int y) __smallc;
/* Unplot a pixel */
extern void __LIB__ c_unplot(int x, int y) __smallc;
/* XORs a pixel on screen */
extern void __LIB__ c_xorplot(int x, int y) __smallc;
/* Get pixel status */
extern int __LIB__ c_point(int x, int y) __smallc;

/* Colour graphics, only few targets are supported */
/* ZX Spectrum has its own implementation aside */
/* Init GFX mode and clear map */
extern void __LIB__ cclg(void) __smallc;

/* Plot a pixel to screen */
extern void __LIB__           cplot(int x, int y, int c) __smallc;
extern void __LIB__    cplot_callee(int x, int y, int c) __smallc __z88dk_callee;
#define cplot(a,b,c)           cplot_callee(a,b,c)

/* Get a pixel from screen */
extern char __LIB__           cpoint(int x, int y) __smallc;
extern char __LIB__    cpoint_callee(int x, int y) __smallc __z88dk_callee;
#define cpoint(a,b)            cpoint_callee(a,b)


#endif

