#ifndef ENEMY_H
#define ENEMY_H

#include "allegro5/allegro.h"
#include "tools.h"

class Enemy
{
  public:
    Enemy();
    virtual ~Enemy();
    void update();
    void draw();

  protected:

  private:
    ALLEGRO_BITMAP *sprite;
    ALLEGRO_BITMAP *spritesheet[62];
    int x=1000;
    int y=200;
    int frame=0;
};

#endif // ENEMY_H
