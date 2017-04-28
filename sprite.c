#include <stdlib.h>
#include <6502.h>
#include <lynx.h>
#include <tgi.h>
//#include <sprites.h>
#include <_suzy.h>

#define BPP_4		      0xC0
#define TYPE_NORMAL	  0x04

// enable Mikeys interrupt response
//#define CLI asm("\tcli")

// These header files are related to the processor family, the Lynx and the TGI libraries.


// The code will first clear the screen, display a header, then print the hex values twice: once against 
// a black background and another time against a white background.

//  this array will contain a string “tgi” that indicates that the loading of the driver was successful.
extern char lynxtgi[]; 

extern unsigned char alien[];

// This will draw the alien as a normal sprite with 4 bits per pixel color depth, without specifying a palette 
// has a collision depository of 0x01 
// The sprite will draw at the (x,y) coordinates of (20,50).
SCB_RENONE aliensprite =  {
  BPP_4 | TYPE_NORMAL, 
  REUSEPAL, 0x01,
  0x0000,
  alien,      //  uses the address of &robot to get to the pixel data
  20, 50
};

void initialize()
{
	// driver for the Tiny Graphics Interface (TGI)
	// allows for 2D graphics primitives like drawing and text 
  	// Lynx file is called lynx-160-102-16.tgi and is part of the Lynx specific CC65 files
	// function call to tgi_install will install the Lynx specific TGI driver
	// Lynx does not have the ability to load a driver dynamically it needs to be linked statically when the game is built.   
	tgi_install(&lynxtgi);

	// performs the initialization of the loaded drivers of which the TGI graphics driver is just one
	// There are two additional drivers (joystick and comlynx) that you can load as well. 
  tgi_init();

	// represents the CLI assembly instruction for the 65SC02 processor
	// allows you to clear the Interrupt Disable flag of the processor,   
  CLI();
	
  while (tgi_busy())  {  };
 
  tgi_setpalette(tgi_getdefpalette());
  tgi_setcolor(COLOR_WHITE);
  tgi_setbgcolor(COLOR_BLACK);
  tgi_clear();
}

// The code will first clear the screen, display a header, 
// then print the hex values twice: once against a black background and another 
// time against a white background.
void show()
{
  tgi_clear();
  // screen is cleared and gets the text “Sprite basics”
  tgi_setcolor(COLOR_WHITE);
  tgi_outtextxy(0, 0, "Sprite basics");
  // he tgi_sprite call, that will accept a pointer address of a SCB
  tgi_sprite(&aliensprite);
  tgi_updatedisplay();
  while (tgi_busy());
}



// The entry point is the main function
void main(void)  {	
  	initialize();
	  
	// An infinite loop where we remain forever  
  while (1) {
    //  a call to setpalette is needed, passing in the array of palette color values.
    // After that all is done. The palette has changed.
    //setpalette(rawpalette);
    show();
  };

}