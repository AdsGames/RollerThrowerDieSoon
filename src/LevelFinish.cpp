#include "LevelFinish.h"

LevelFinish::LevelFinish()
{
    font = al_load_ttf_font( "font/font.ttf", 18, 0);
    font_big = al_load_ttf_font( "font/font.ttf", 56, 0);
    font_extra_thicc = al_load_ttf_font( "font/font.ttf", 100, 0);



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

  if(LevelFinishUI.getElementByText("Continue") -> clicked()){
   game::level=4;
    set_next_state(STATE_OPTIONS);
  }
}

void LevelFinish::draw(){

    al_clear_to_color( al_map_rgb(50,50,50));

    LevelFinishUI.draw();

    al_draw_textf( font_extra_thicc, al_map_rgb( 200, 0, 0), 700, 20, 0, "Carnage Report");

    int total_guests=123;
    if(game::level==1)
      total_guests=10;
    if(game::level==2)
      total_guests=15;
    if(game::level==3)
      total_guests=50;
     if(game::level==4)
      total_guests=150;

    al_draw_textf( font_big, al_map_rgb( 150, 150, 150), 200, 200, 0, "Total guests:%i",total_guests);
    al_draw_textf( font_big, al_map_rgb( 150, 0, 0), 200, 260, 0, "Total drowned:%i",game::guests_died_falling);
    al_draw_textf( font_big, al_map_rgb( 150, 0, 0), 200, 320, 0, "Total killed by octopi:%i",game::guests_died_enemies);
    al_draw_textf( font_big, al_map_rgb( 0, 150, 0), 200, 380, 0, "Total rescued:%i",game::guests_rescued);
    al_draw_textf( font_big, al_map_rgb( 0, 150, 0), 200, 440, 0, "Final cash:%i",game::money);

    float total_f=total_guests;
    float total_lived=game::guests_rescued;
    float percent = (total_lived/total_guests)*100;

    al_draw_textf( font_extra_thicc, al_map_rgb( 200, 50, 50), 1200, 300, 0, "%.1f%%",percent);
    al_draw_textf( font, al_map_rgb( 200, 50, 50), 1250, 420, 0, "of guests survived.");






    al_draw_bitmap(cursor,mouseListener::mouse_x-8,mouseListener::mouse_y-56,0);


}
