#include "LevelFinish.h"

LevelFinish::LevelFinish()
{
    font = al_load_ttf_font( "font/font.ttf", 18, 0);

    cursor = tools::load_bitmap_ex("images/tweezersOpen.png");

    LevelFinishUI.addElement( new Button(  200, 800, "Continue", font));
//
//    OptionsUI.addElement( new Button(  400, 200, "Level 2", font));
//
//    OptionsUI.addElement( new Button(  600, 200, "Level 3", font));
//
//    OptionsUI.addElement( new Button(  800, 200, "Level 4", font));


}

LevelFinish::~LevelFinish()
{
  //dtor
}

void LevelFinish::update(){
  LevelFinishUI.update();
}

void LevelFinish::draw(){

    al_clear_to_color( al_map_rgb(50,50,50));

    LevelFinishUI.draw();


    al_draw_bitmap(cursor,mouseListener::mouse_x,mouseListener::mouse_y,0);

//  if(LevelFinishUI().getElementByText("Level 4") -> clicked()){
//    game::level=4;
//    set_next_state(STATE_OPTIONS);
//  }
}
