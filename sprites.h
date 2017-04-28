#define SPRCTL0_1_bit_per_pixel 0
#define SPRCTL0_2_bits_per_pixel 0x40
#define SPRCTL0_3_bits_per_pixel 0x80
#define SPRCTL0_4_bits_per_pixel 0xc0
#define SPRCTL0_h_flip 0x20
#define SPRCTL0_v_flip 0x10
#define SPRCTL0_shadow 7
#define SPRCTL0_xor_shadow 6
#define SPRCTL0_non_collide 5
#define SPRCTL0_normal 4
#define SPRCTL0_boundary 3
#define SPRCTL0_boundary_shadow 2
#define SPRCTL0_background_no_coll 1
#define SPRCTL0_background_shadow 0

#define SPRCTL1_literal 0x80
#define SPRCTL1_hsize_vsize_strech_tilt 0x30
#define SPRCTL1_hsize_vsize_strech 0x20
#define SPRCTL1_hsize_vsize 0x10
#define SPRCTL1_no_palette 0x08
#define SPRCTL1_skip_sprite 0x04
#define SPRCTL1_start_drawing_up 0x02
#define SPRCTL1_start_drawing_left 0x01

#define SPRCOLL_dont_collide 0x20
#define SPRCOLL_number_0_3 0x00

typedef struct {
	unsigned char b0;
	unsigned char b1;
	unsigned char b2;
	void *next;
	void *bitmap;
	int posx, posy;
} sprite_simple;

typedef struct {
	unsigned char b0;
	unsigned char b1;
	unsigned char b2;
	void *next;
	void *bitmap;
	int posx, posy, sizex, sizey;
	char palette[8];
} sprite_sizable;

typedef struct {
	unsigned char b0;
	unsigned char b1;
	unsigned char b2;
	void *next;
	void *bitmap;
	int posx, posy;
	int sizex, sizey;
	int stretch;
	int tilt;
	char palette[8];
} sprite_complete;