/**
 * MENU
 * A.D.S. Games
 * 06/05/2017
**/
#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "listeners/keyListener.h"
#include "listeners/joystickListener.h"
#include "tools.h"
#include "state.h"
#include "UI/button.h"
#include "Options.h"
#include "Sound.h"
#include "MusicManager.h"



// Menu
class menu : public state {
  public:
    menu();
    virtual ~menu() {};

    void update();
    void draw();

  private:


    // Images
    ALLEGRO_BITMAP *splash;
    ALLEGRO_BITMAP *loading;


    ALLEGRO_FONT *menu_font;

    bool loadingb = false;



};

#endif // MENU_H
