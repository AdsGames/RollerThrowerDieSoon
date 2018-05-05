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
#include "Tile.h"
#include "Guest.h"
#include "Enemy.h"

class game : public state{
  public:
    // Construct / destruct
    game();
    ~game();

    // Override parent
    void update();
    void draw();

    Tile *createTile(int,int,int);
    Guest *createGuest(int,int);


    // Test mode
    std::vector <Tile*> gameTiles;
    std::vector <Guest*> gameGuests;
    std::vector <Enemy*> gameEnemies;

    Guest *selectedGuest = nullptr;



  private:
    ALLEGRO_BITMAP *tile;
    ALLEGRO_BITMAP *entrance_back;
    ALLEGRO_BITMAP *entrance_front;
    ALLEGRO_BITMAP *cursor_open;
    ALLEGRO_BITMAP *cursor_closed;

    int old_mouse_x=0;
    int old_mouse_y=0;

    float x_velocity=0;
    float y_velocity=0;
    // Functions

};

#endif // GAME_H
