#pragma once 
#include <stdint.h>
#include "types.h"


void display_init(i32 width, i32 height);
void display_clear(void);
void display_flush(void);

u8 window_should_close(void);

void display_begin(void);
void display_end(void);

void set_pixel(i32 x, i32 y);
void unset_pixel(i32 x, i32 y);
void draw_circle(i32 x, i32 y, f32 radius);
void fill_circle(i32 x, i32 y, f32 radius); void draw_line(i32 start_x, i32 start_y,i32 end_x, i32 end_y); 
//void draw_image();

void draw_rectangle(i32 x, i32 y, i32 width, i32 height);
void fill_rectangle(i32 x, i32 y, i32 width, i32 height);
//void draw_rectangle_rec();

void draw_text(const char *text, i32 posX, i32 posY, i32 fontSize);       // Draw text (using default font)



u16 get_proximity(void);


