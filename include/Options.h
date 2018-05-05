#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

#include "state.h"
#include "UI/UIHandler.h"
#include "UI/UIElement.h"
#include "UI/button.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "listeners/keyListener.h"
#include "listeners/joystickListener.h"

class Options : public state
{
  public:
    Options();
    virtual ~Options();

    void draw();
    void update();
    void updateUI();

    static void read_data();
    void write_data();

    static bool sfx_enabled;
    static bool music_enabled;
    static int graphics_mode;
    static bool draw_cursor;
    static std::string joystick_data;
    static void updateJoysticks(std::string newJoyData);
    static bool joystick_mode;

  private:
    std::string graphics_data="";

    ALLEGRO_FONT *options_font;
    ALLEGRO_FONT *title_font;

    UIHandler OptionsUI;

    ALLEGRO_BITMAP *cursor;
    ALLEGRO_BITMAP *highlight;

    int highlight_y=100;;
    int highlight_y_destination=100;
    bool joystick_direction_hit=false;
};

#endif // OPTIONS_H
