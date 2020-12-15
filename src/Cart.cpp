#include "Cart.h"

Cart::Cart(int newx, int newy) {
  cart = tools::load_bitmap_ex("images/tiles/car.png");
  x = newx;
  y = newy;
  /*
  x_velocity=-40;
  y_velocity=-20;
  */
  accel = 0.0f;
  spin = 0.0f;
  x_velocity = -0;
  y_velocity = -0;
  is_cart = true;
}

Cart::~Cart() {
  // dtor
}

void Cart::update() {
  accel += 0.02f;

  if (accel > 0.4f)
    spin += 0.1f + accel * 0.1f;

  x_velocity += accel * -4;
  y_velocity += accel * -4;
  x += x_velocity;
  y += y_velocity;
}

void Cart::draw() {
  // al_draw_bitmap(cart, x, y, 0 );
  al_draw_rotated_bitmap(cart, 24, 16, x, y, spin, 0);
}
