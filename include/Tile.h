#ifndef TILE_H
#define TILE_H

#include "allegro5/allegro.h"
#include "tools.h"
class Tile
{
    public:
        Tile(int,int);
        virtual ~Tile();
        void draw();

    protected:

    private:
        ALLEGRO_BITMAP *sprite;
        ALLEGRO_BITMAP *grid;
        int x;
        int y;
};

#endif // TILE_H
