#include "display/display.h"
#include "sprites/sprites.h"
#include "sprites/palettes.h"
#include "stddef.h"
#include <math.h>

i32 proximity_to_y(f32 proximity, u8 maxY){
  f32 ratio = (f32)maxY/1023.0f;
	return (i32)round(proximity * ratio);
};

int main(){
	display_init_lcd();
  f32 proximity;
  f32 proximity_old;
	i32 sprite_y = 0;
  
	set_palette(0);
	
	TextureHandle potato_texture_handle = load_texture_from_sprite(potato_sprite.height,potato_sprite.width,potato_sprite.data);
	TextureHandle mman_texture_handle = load_texture_from_sprite(mman_sprite.height,mman_sprite.width,mman_sprite.data);
  TextureHandle wdf1_texture_handle = load_texture_from_sprite(wdf1_sprite.height,wdf1_sprite.width,wdf1_sprite.data);
  TextureHandle wdf2_texture_handle = load_texture_from_sprite(wdf2_sprite.height,wdf2_sprite.width,wdf2_sprite.data);
  TextureHandle wuf1_texture_handle = load_texture_from_sprite(wuf1_sprite.height,wuf1_sprite.width,wuf1_sprite.data);
  TextureHandle wuf2_texture_handle = load_texture_from_sprite(wuf2_sprite.height,wuf2_sprite.width,wuf2_sprite.data);

  TextureHandle wd_anim[2][2] = {{wdf1_texture_handle,wdf2_texture_handle},{wuf1_texture_handle,wuf2_texture_handle}};
  i32 counter = 0;
  i32 counter2 = 0;
  i32 direction = 0;

  u8 max_height = 128-wdf1_sprite.height;

  while(!window_should_close()){
    display_begin();
		proximity = get_proximity();


    if(counter2 == 7){
      counter = (counter==0 ? 1 : 0);
      counter2 = 0;
    }

    if(proximity != proximity_old){
      counter2++;

      if(proximity > proximity_old) direction = 0;
      if(proximity < proximity_old) direction = 1;
    } 


    sprite_y = proximity_to_y(proximity,max_height);

    clear_screen();

		draw_texture(40,sprite_y,wd_anim[direction][counter%2]);
    proximity_old = proximity;
    display_end();
  }


  display_close();
}

