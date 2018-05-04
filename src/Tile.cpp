#include "Tile.h"

Tile::Tile(int newX, int newY)
{
    sprite = tools::load_bitmap_ex("images/tiles/Grass.png");
    grid = tools::load_bitmap_ex("images/tiles/EmptyGrid.png");

    x = newX;
    y = newY;

}

Tile::~Tile()
{
    //dtor
}

void Tile::draw(){
  int bigx=x*64;
  int bigy=y*64;
    int isoX = bigx - bigy;
   int isoY = (bigx + bigy) / 2;
   al_draw_bitmap(sprite,isoX,isoY,0);
   al_draw_bitmap(grid,isoX,isoY,0);



}
