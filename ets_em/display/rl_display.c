#include "display.h"
#include "types.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define SLIDER_HEIGHT 128
#define SLIDER_WIDTH 50

void display_init(i32 width,i32 height){
  InitWindow(width+SLIDER_WIDTH,height,"Simulation Window");
  SetTargetFPS(30);
};

void display_flush(){
  CloseWindow();
};

void display_clear(){
  ClearBackground(BLACK); 
};

u8 window_should_close(){
  return WindowShouldClose() ? 1 : 0;
}

void display_begin(){
  BeginDrawing();
};

void display_end(){
  EndDrawing();
};

void set_pixel(i32 x, i32 y){
  DrawPixel(x+SLIDER_WIDTH,y,WHITE);
}

void unset_pixel(i32 x, i32 y) {
  DrawPixel(x+SLIDER_WIDTH,y,BLACK);
}

void draw_circle(i32 x, i32 y, f32 radius){
  DrawCircle(x+SLIDER_WIDTH,y,radius,WHITE);
};

void draw_text(const char *text,i32 x, i32 y, i32 font_size){
  DrawText(text,x,y,font_size,WHITE);
}

static float slider_value = 300.0f;

f32 get_proximity(){
  slider_value = GuiSlider((Rectangle){0,0,SLIDER_WIDTH,SLIDER_HEIGHT},NULL,NULL,&slider_value,0.0f,1023.0f);
  return slider_value;
};


//void fill_circle(i32 x, i32 y, f32 radius); void draw_line(i32 start_x, i32 start_y,i32 end_x, i32 end_y); //void draw_image();
//void draw_rectangle(i32 x, i32 y, i32 width, i32 height);
//void fill_rectangle(i32 x, i32 y, i32 width, i32 height);









