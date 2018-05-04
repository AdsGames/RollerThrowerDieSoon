#include "Tile.h"

Tile::Tile()
{
    sprite = tools::load_bitmap_ex("images/tiles/Grass.png");

}

Tile::~Tile()
{
    //dtor
}

void Tile::draw(){
   al_draw_bitmap(sprite,0,0,0);


}
