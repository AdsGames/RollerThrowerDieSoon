#include "Cart.h"

Cart::Cart(int newx, int newy)
{
   cart = tools::load_bitmap_ex( "images/cart.png" );
   x=newx;
   y=newy;
   x_velocity=-40;
   y_velocity=-20;
}

Cart::~Cart()
{
  //dtor
}

void Cart::update(){
    x += x_velocity;
    y += y_velocity;

}

void Cart::draw(){
  al_draw_bitmap(cart, x, y, 0 );

}
