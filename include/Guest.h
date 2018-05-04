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

  protected:

  private:
    ALLEGRO_BITMAP *sprite;
    int x=0;
    int y=0;
};

#endif // GUEST_H
