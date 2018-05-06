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

  x=nx;
  y=ny;
}

Particle::~Particle()
{
  //dtor
}

void Particle::draw(){

  al_draw_bitmap( sprite, x-8, y-8, 0 );

}

bool Particle::update(){

  y-=5;
  lifetime++;
  if(lifetime>60)
    return true;
  return false;
}
