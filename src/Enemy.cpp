#include "Enemy.h"

Enemy::Enemy( int x, int y ){
  sprite = tools::load_bitmap_ex( "images/flail.png" );
  font = al_load_ttf_font( "font/font.ttf", 18, 0 );

  for( int i = 0; i < 62; i++)
    spritesheet[i] = al_create_sub_bitmap( sprite, 0, i * 297, 498, 297 );

  int bigx = x * 64;
  int bigy = y * 64;

  this -> x = (bigx - bigy);
  this -> y = (bigx + bigy) / 2;
}

void Enemy::applyDamage(int newDamage){
  health -= newDamage;
  if( health < 0)
    health = 0;
}

Enemy::~Enemy(){
  for( int i = 0; i < 62; i++)
    al_destroy_bitmap( spritesheet[i] );

  al_destroy_bitmap( sprite);
  al_destroy_font( font );
}

void Enemy::update(){
  frame = (frame + 1) % 62;
}

void Enemy::draw(){
  al_draw_bitmap( spritesheet[frame], x, y, 0 );
  al_draw_textf( font, al_map_rgb( 0, 0, 0 ), x + 300, y, 0, "%i", health );
}
