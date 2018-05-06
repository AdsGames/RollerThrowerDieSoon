#include "Options.h"



Options::Options()
{

    font = al_load_ttf_font( "font/font.ttf", 18, 0);

    cursor = tools::load_bitmap_ex("images/tweezersOpen.png");





}

Options::~Options()
{
  //dtor
}

void Options::draw(){

    al_clear_to_color( al_map_rgb(50,50,50));

    OptionsUI.draw();


    al_draw_bitmap(cursor,mouseListener::mouse_x,mouseListener::mouse_y,0);

    //al_draw_bitmap(highlight,100,highlight_y,0);


}

void Options::update(){



  OptionsUI.update();





}
