#include "Options.h"



Options::Options()
{

    font = al_load_ttf_font( "font/font.ttf", 18, 0);

    cursor = tools::load_bitmap_ex("images/tweezersOpen.png");

    OptionsUI.addElement( new UIElement(  10, 10, "Level Select", font));

    OptionsUI.addElement( new Button(  200, 200, "Level 1", font));




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

  if(OptionsUI.getElementByText("Level 1") -> clicked()){
    game::level=1;
    set_next_state(STATE_GAME);
  }



  OptionsUI.update();





}
