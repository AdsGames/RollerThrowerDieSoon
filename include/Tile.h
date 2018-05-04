#ifndef TILE_H
#define TILE_H

#include "allegro5/allegro.h"
#include "tools.h"
class Tile
{
    public:
        Tile();
        virtual ~Tile();
        void draw();

    protected:

    private:
        ALLEGRO_BITMAP *sprite;
};

#endif // TILE_H
