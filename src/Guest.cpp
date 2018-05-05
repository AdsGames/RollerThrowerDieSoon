#include "Guest.h"

Guest::Guest(int newX, int newY)
{
    sprite = tools::load_bitmap_ex("images/walk.png");

  for( int i = 0; i < 43; i++)
    spritesheet[i] = al_create_sub_bitmap( sprite, 0, i*38, 17, 38);


  sprite = tools::load_bitmap_ex("images/panic.png");

  for( int i = 0; i <25; i++)
    spritesheet_panic[i] = al_create_sub_bitmap( sprite, 0, i*36, 17, 36);

    //fricking spritesheets

    x = newX;
    y = newY;


  //ctor
}

Guest::~Guest()
{
  //dtor
}
void Guest::update(){

  int threshold=1.0;
  float decel=1.2f;

  if(x_velocity>-threshold && x_velocity<threshold)
    x_velocity=0;

  if(y_velocity>-threshold && y_velocity<threshold)
    y_velocity=0;

   if(y_velocity>threshold)
    y_velocity/=decel;

   if(y_velocity<-threshold)
    y_velocity/=decel;

  if(x_velocity>threshold)
    x_velocity/=decel;

   if(x_velocity<-threshold)
    x_velocity/=decel;





  if(y_velocity==0 && x_velocity==0){
    if(direction==0){
      x+=1;
      y-=0.5;
    }
    if(direction==1){
      x+=1;
      y+=0.5;
    }
    if(direction==2){
      x-=1;
      y+=0.5;
    }
    if(direction==3){
      x-=1;
      y-=0.5;
    }
  }else{

    x+=x_velocity;
    y+=y_velocity;
  }

  frame++;
  if(frame>42)
    frame=0;

  frame_panic++;
  if(frame_panic>=25)
    frame_panic=0;
}

void Guest::draw(){


  if(!captured)al_draw_bitmap(spritesheet[frame],x-8,y-18,0);
    else
  al_draw_bitmap(spritesheet_panic[frame_panic],x-10,y-18,0);

}

