#ifndef LEVELFINISH_H
#define LEVELFINISH_H

#include <state.h>
#include "allegro5/allegro.h"//ctor
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "tools.h"

#include "UI/UIHandler.h"
#include "UI/UIElement.h"
#include "UI/button.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "listeners/keyListener.h"
#include "listeners/joystickListener.h"
#include "game.h"

class LevelFinish : public state
{
  public:
    LevelFinish();
    virtual ~LevelFinish();

     void draw();
     void update();

  protected:

  private:
    UIHandler LevelFinishUI;

    ALLEGRO_BITMAP *cursor;
    ALLEGRO_FONT *font;
};

#endif // LEVELFINISH_H
