#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

#include "UI/UIElement.h"
#include "UI/UIHandler.h"
#include "UI/button.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "state.h"

#include "game.h"
#include "listeners/joystickListener.h"
#include "listeners/keyListener.h"
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"

class Options : public state {
 public:
  Options();
  virtual ~Options();

  void draw();
  void update();

 private:
  ALLEGRO_FONT* font;
  ALLEGRO_FONT* font_big;

  UIHandler OptionsUI;

  ALLEGRO_BITMAP* cursor;
  ALLEGRO_BITMAP* background;
  ALLEGRO_BITMAP* load;

  bool loading = false;
};

#endif  // OPTIONS_H
