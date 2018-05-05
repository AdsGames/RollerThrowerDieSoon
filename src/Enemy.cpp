#include "Enemy.h"

Enemy::Enemy()
{
   sprite = tools::load_bitmap_ex("images/flail.png");

  for( int i = 0; i < 62; i++)
    spritesheet[i] = al_create_sub_bitmap( sprite, 0, i*297, 498, 297);


}
void Enemy::applyDamage(int newDamage){
  health-=newDamage;
  if(health<0)
    health=0;


}


Enemy::~Enemy()
{
  //dtor
}

void Enemy::update(){
  frame++;
  if(frame>=62)
    frame=0;


}

void Enemy::draw(){

    al_draw_bitmap(spritesheet[frame],x,y,0);
    //textp

}
