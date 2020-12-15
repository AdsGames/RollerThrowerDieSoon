#ifndef CART_H
#define CART_H

#include "Guest.h"


class Cart : public Guest {
  public:
    Cart (int, int);
    virtual ~Cart();
    void update();
    void draw();

  protected:

  private:
    float accel;
    float spin;
    ALLEGRO_BITMAP *cart;

};

#endif // CART_H
