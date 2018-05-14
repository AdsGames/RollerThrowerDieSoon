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
    void update();
    int getType(){ return type; }

    // Check if x and y are in tile
    int colliding( int x, int y, int width = 0, int height = 0 );
    int colliding_tight( int x, int y, int width = 0, int height = 0 );
    int colliding_loose( int x, int y, int width = 0, int height = 0 );
    int colliding_water( int x, int y, int width = 0, int height = 0 );


  private:
    ALLEGRO_BITMAP *sprite;
    ALLEGRO_BITMAP *grid;
    ALLEGRO_BITMAP *spritesheet_Water[4];
    int frame = 0;
    int x;
    int y;
    int type;
    int iso_x;
    int iso_y;
};

#endif // TILE_H
