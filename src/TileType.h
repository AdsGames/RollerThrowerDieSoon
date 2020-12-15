#ifndef TILETYPE_H
#define TILETYPE_H

#include <allegro5/allegro.h>

class TileType {
 public:
  TileType(int id, ALLEGRO_BITMAP* image);
  virtual ~TileType();

  ALLEGRO_BITMAP* image;
  int id;
};

#endif  // TILETYPE_H
