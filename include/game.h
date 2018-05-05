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

#include "state.h"

#include "tools.h"
#include "Tile.h"
#include "Guest.h"
#include "Enemy.h"
#include "UI/UIHandler.h"

class game : public state{
  public:
    // Construct / destruct
    game();
    ~game(){ };

    // Override parent
    void update();
    void draw();

    // Create tile at coordinate
    Tile *createTile( int, int, int );

    // Create guest at coordinate
    Guest *createGuest( int, int );
    UIHandler gameUI;

    // Test mode
    std::vector <Tile*> gameTiles;
    std::vector <Guest*> gameGuests;
    std::vector <Enemy*> gameEnemies;

    // Guest selected by grabber
    Guest *selectedGuest = nullptr;

  private:
    // Images
    ALLEGRO_BITMAP *tile;
    ALLEGRO_BITMAP *path[4];
    ALLEGRO_BITMAP *entrance_back;
    ALLEGRO_BITMAP *entrance_front;
    ALLEGRO_BITMAP *cursor_open;
    ALLEGRO_BITMAP *cursor_closed;
    ALLEGRO_BITMAP *path_hover;

    // Grabber info
    int old_mouse_x;
    int old_mouse_y;

    int editor_tool=0;

    float x_velocity;
    float y_velocity;
};

#endif // GAME_H
