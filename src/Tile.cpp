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
    case 9:
      sprite = tools::load_bitmap_ex("images/tiles/Umbrella.png");
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

// Check if x and y are in tile
int Tile::colliding( int x, int y, int width, int height){
  return tools::collision( x, x + width, iso_x + 32, iso_x + 96, y, y + height, iso_y + 0, iso_y + 64 );
}

int Tile::colliding_loose( int x, int y, int width, int height){
  return tools::collision( x, x + width, iso_x + 32-128, iso_x + 96+128, y, y + height, iso_y + 0-64, iso_y + 64+64 );
}

// Check if x and y are in tile (tight)
int Tile::colliding_tight( int x, int y, int width, int height){
  return tools::collision( x, x + width, iso_x + 48, iso_x + 80, y, y + height, iso_y + 16, iso_y + 48 );
}

void Tile::draw(){
  if( sprite != nullptr )
    al_draw_bitmap( sprite, iso_x, iso_y, 0);
  if( grid != nullptr )
    al_draw_bitmap( grid, iso_x, iso_y, 0);
}
