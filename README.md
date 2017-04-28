# Sprites
Atari Lynx programming tutorial working with sprites.

The sprites of the Lynx are data structures that describe how the sprite should be drawn. 

The pixel data is a compact format that holds the various pixels in the sprite, including their colors indexes, and some line and quadrant information.

The SCB holds the position, size, and manipulation data as well as the palette for the colors that correspond to the indexes in the sprite data, plus a pointer to the memory of the sprite pixel data.

The bitmap files are sources for pixel data files,

## Requirements

cc65

http://cc65.github.io/cc65

sprpck

https://github.com/kateflower/sprpck


## Editor

You need a pixel art editor.  

I used Pikopixel for the mac.

http://twilightedge.com/mac/pikopixel/

A commercial option I also use is Pixen

https://pixenapp.com/

However, we will have to use ImageMagik in order to convert the exported bitmaps to a format that the sprite packer likes.

Alternatively, you can use GIMP because we can export our images as windows bitmap 24 bit.  Which is what we need.  These work perfectly.


## Creating sprite pixel data

You need to create pixel data from our image.  The tool of chooce is sprpck (sprite packer).  The sprite packer only supports 4-, 8- or 24-bit-per-pixel bitmaps.  Which is problematic when using a modern editor.

Test your image first.

sprpck -v -t6 -p2 alien.bmp 

It has two parameters -t6 and -p2 that indicate a Windows Bitmap file and a LYXASS output file

With luck it will convert.

You might get an error like this: "Error (1):Only 4-, 8- or 24-bit-per-pixel bitmaps are supported"

This is because the sprite packer is old and does not support 32 bit images or compressed BMP files.  We can fix this using ImageMagik convert like:

convert alien.bmp -compress None  -depth 8 BMP3:alien_converted.bmp

This will give us a nice sprpck compatible bitmap.


The sprite packer will generate a number of files.

alien.spr (contains the sprite pixel data)
alien.pal (contains color palette information)
alien.s (assembler code)
alien.o (the final object file with the compiled pixel data and reference variables)


## Build

make clean<br />
make all

load the resultant sprite.lyx file into your emulator


### References:

Coding example are build using the Lynx Programming Tutorial:

https://atarilynxdeveloper.wordpress.com/2012/10/10/programming-tutorial-part-7the-basics-of-sprites/

