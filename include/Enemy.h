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
    void applyDamage(int);

    int getX(){return x;}
    int getY(){return y;}

  protected:

  private:
    ALLEGRO_BITMAP *sprite;
    ALLEGRO_BITMAP *spritesheet[62];
    int x=1000;
    int y=200;
    int frame=0;
    int health=1000;
};

#endif // ENEMY_H
