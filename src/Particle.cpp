#include "Particle.h"

Particle::Particle(int nx, int ny, int ntype)
{
  if(ntype==0)
    sprite = tools::load_bitmap_ex("images/money.png");
  if(ntype==1)
    sprite = tools::load_bitmap_ex("images/skull.png");
  if(ntype==2)
    sprite = tools::load_bitmap_ex("images/check.png");
  if(ntype==3)
    sprite = tools::load_bitmap_ex("images/hit.png");
  if(ntype==4)
    sprite = tools::load_bitmap_ex("images/skullBig.png");

  x=nx;
  y=ny;
  type=ntype;
}

Particle::~Particle()
{
  //dtor
}

void Particle::draw(){

  if(type==4)
    al_draw_bitmap( sprite, x+128, y+64, 0 );
  else
    al_draw_bitmap( sprite, x-8, y-8, 0 );

}

bool Particle::update(){

  y-=5;
  lifetime++;
  if(lifetime>60)
    return true;
  return false;
}
