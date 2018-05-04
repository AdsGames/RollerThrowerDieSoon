#include "Enemy.h"

Enemy::Enemy()
{
   sprite = tools::load_bitmap_ex("images/Enemy.png");
}

Enemy::~Enemy()
{
  //dtor
}

void Enemy::draw(){

  al_draw_bitmap(sprite,x,y,0);
}
