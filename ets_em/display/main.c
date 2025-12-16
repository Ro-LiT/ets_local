#include "display.h"

// proximity goes to 1023, we want to map that to 80 max
f32 proximity_to_radius(f32 proximity){
  return proximity / 12.7875f; 
}

int main(){

  display_init(128,128);
  f32 proximity = 500.0f;
  f32 circle_radius = 10.0f;
  
  while(!window_should_close()){
    display_begin();
    display_clear();

    draw_circle(64,64,circle_radius); 

    proximity = get_proximity();
    circle_radius = proximity_to_radius(proximity);

    display_end();
  }

  display_flush();
}

