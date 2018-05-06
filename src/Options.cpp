#include "Options.h"



Options::Options()
{

    font = al_load_ttf_font( "font/font.ttf", 18, 0);

    cursor = tools::load_bitmap_ex("images/tweezersOpen.png");

    background = tools::load_bitmap_ex("images/levelSelecT.png");



    OptionsUI.addElement( new Button(  400, 550, "Level 1", font));

    OptionsUI.addElement( new Button(  600, 550, "Level 2", font));

    OptionsUI.addElement( new Button(  800, 550, "Level 3", font));

    OptionsUI.addElement( new Button(  1000, 550, "Level 4", font));






}

Options::~Options()
{
  //dtor
}

void Options::draw(){

    al_clear_to_color( al_map_rgb(50,50,50));

    al_draw_bitmap(background,0,0,0);


    OptionsUI.draw();


    al_draw_bitmap(cursor,mouseListener::mouse_x-8,mouseListener::mouse_y-56,0);

    //al_draw_bitmap(highlight,100,highlight_y,0);


}

void Options::update(){

  if(OptionsUI.getElementByText("Level 1") -> clicked()){
    game::level=1;
    set_next_state(STATE_GAME);
  }

  if(OptionsUI.getElementByText("Level 2") -> clicked()){
    game::level=2;
    set_next_state(STATE_GAME);
  }

   if(OptionsUI.getElementByText("Level 3") -> clicked()){
    game::level=3;
    set_next_state(STATE_GAME);
  }

  if(OptionsUI.getElementByText("Level 4") -> clicked()){
    game::level=4;
    set_next_state(STATE_GAME);
  }



  OptionsUI.update();





}
