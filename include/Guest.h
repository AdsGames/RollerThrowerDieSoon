#ifndef GUEST_H
#define GUEST_H


#include "tools.h"
#include "allegro5/allegro.h"

class Guest
{
  public:
    Guest(int,int);
    virtual ~Guest();
    void draw();
    void update();

  protected:

  private:
    ALLEGRO_BITMAP *sprite;
    ALLEGRO_BITMAP *spritesheet[43];
    float x=0;
    float y=0;
    int frame=0;
};

#endif // GUEST_H
