/**
 * GAME
 * A.D.S. Games
 * 05/05/2017
**/
#ifndef GAME_H
#define GAME_H

#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


#include <mouseListener.h>
#include <keyListener.h>
#include <joystickListener.h>

#include "state.h"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"



#include <tools.h>
#include <button.h>
#include "Sound.h"
#include "MusicManager.h"

class game : public state{
  public:
    // Construct / destruct
    game();
    ~game();

    // Override parent
    void update();
    void draw();
    bool level_complete();

    // Test mode
    static bool testing;
    static const char *testing_file_name;
    static int level_to_start;

  private:
    // Functions

};

#endif // GAME_H
