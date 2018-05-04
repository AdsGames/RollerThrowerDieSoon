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
    float x=0;
    float y=0;
};

#endif // GUEST_H
