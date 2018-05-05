#include "Tile.h"

Tile::Tile(int x, int y, int type){
  // Nullify bitmaps
  sprite = nullptr;
  grid = nullptr;

  // Set type
  this -> type = type;

  // Set sprites
  switch( type ){
    case 0:
      sprite = tools::load_bitmap_ex("images/tiles/Grass.png");
      break;
    case 1:
      sprite = tools::load_bitmap_ex("images/tiles/Path.png");
      break;
    case 2:
      sprite = tools::load_bitmap_ex("images/tiles/Spawn.png");
      break;
    case 3:
      sprite = tools::load_bitmap_ex("images/tiles/Win.png");
      break;
    case 4:
      sprite = tools::load_bitmap_ex("images/tiles/Path_3.png");
      break;
    case 5:
      sprite = tools::load_bitmap_ex("images/tiles/Path_0.png");
      break;
    case 6:
      sprite = tools::load_bitmap_ex("images/tiles/Path_1.png");
      break;
    case 7:
      sprite = tools::load_bitmap_ex("images/tiles/Path_2.png");
      break;
    case 8:
      sprite = tools::load_bitmap_ex("images/tiles/Water.png");
      break;
    default:
      break;
  }

  // Load grid
  grid = tools::load_bitmap_ex("images/tiles/EmptyGrid.png");

  // Set position
  this -> x = x;
  this -> y = y;

  // Calculate isometric position
  int bigx = x * 64;
  int bigy = y * 64;
  iso_x = (bigx - bigy);
  iso_y = (bigx + bigy) / 2;
}

void Tile::draw(){
  if( sprite != nullptr )
    al_draw_bitmap( sprite, iso_x, iso_y, 0);
  if( grid != nullptr )
    al_draw_bitmap( grid, iso_x, iso_y, 0);
}
