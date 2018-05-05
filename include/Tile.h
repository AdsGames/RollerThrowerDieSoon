#ifndef TILE_H
#define TILE_H

#include "allegro5/allegro.h"
#include "tools.h"

class Tile
{
  public:
    Tile( int, int, int);
    virtual ~Tile(){}
    void draw();
    int getX(){ return x; }
    int getY(){ return y; }
    int getIsoX(){ return iso_x; }
    int getIsoY(){ return iso_y; }
    void setType( int type ){ this -> type = type; }
    int getType(){ return type; }

  private:
    ALLEGRO_BITMAP *sprite;
    ALLEGRO_BITMAP *grid;

    int x;
    int y;
    int type;
    int iso_x;
    int iso_y;
};

#endif // TILE_H
