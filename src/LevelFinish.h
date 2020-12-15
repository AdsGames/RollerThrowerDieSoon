#ifndef LEVELFINISH_H
#define LEVELFINISH_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "tools.h"

#include "UI/UIElement.h"
#include "UI/UIHandler.h"
#include "UI/button.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

#include "game.h"
#include "listeners/joystickListener.h"
#include "listeners/keyListener.h"
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "state.h"

class LevelFinish : public state {
 public:
  LevelFinish();
  virtual ~LevelFinish();

  void draw();
  void update();

 protected:
 private:
  UIHandler LevelFinishUI;

  ALLEGRO_BITMAP* cursor;
  ALLEGRO_FONT* font;
  ALLEGRO_FONT* font_big;
  ALLEGRO_FONT* font_extra_thicc;
};

#endif  // LEVELFINISH_H
