#include "Guest.h"

Guest::Guest(int newX, int newY)
{
    sprite = tools::load_bitmap_ex("images/Guest.png");

    x = newX;
    y = newY;


  //ctor
}

Guest::~Guest()
{
  //dtor
}
void Guest::update(){
  x+=1;
  y-=0.5;
}

void Guest::draw(){

  al_draw_bitmap(sprite,x,y,0);
}

