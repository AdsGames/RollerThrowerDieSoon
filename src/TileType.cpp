#include "TileType.h"

TileType::TileType(int id, ALLEGRO_BITMAP* image)
{
  image = nullptr;

  this -> image = image;
  this -> id = id;
}

TileType::~TileType()
{
  al_destroy_bitmap( image );
}
