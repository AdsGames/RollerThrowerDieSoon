#include "Tile.h"

Tile::Tile(int newX, int newY, int newType)
{
    type=newType;

    if(type==0)
      sprite = tools::load_bitmap_ex("images/tiles/Grass.png");
     if(type==1)
      sprite = tools::load_bitmap_ex("images/tiles/Path.png");
     if(type==2)
      sprite = tools::load_bitmap_ex("images/tiles/Spawn.png");

    grid = tools::load_bitmap_ex("images/tiles/EmptyGrid.png");

    x = newX;
    y = newY;

  int bigx=x*64;
  int bigy=y*64;
  iso_x = bigx - bigy;
  iso_y = (bigx + bigy) / 2;

}

Tile::~Tile()
{
    //dtor
}

void Tile::draw(){

   al_draw_bitmap(sprite,iso_x,iso_y,0);
   al_draw_bitmap(grid,iso_x,iso_y,0);



}
