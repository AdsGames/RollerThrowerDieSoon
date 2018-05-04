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
    int x=1000;
    int y=200;
};

#endif // ENEMY_H
