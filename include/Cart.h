#ifndef CART_H
#define CART_H

#include "Guest.h"


class Cart : public Guest
{
  public:
    Cart(int,int);
    virtual ~Cart();
    void update();
    void draw();

  protected:

  private:

      ALLEGRO_BITMAP *cart;

};

#endif // CART_H
