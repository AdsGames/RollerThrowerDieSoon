#include "game.h"
#include <allegro5/bitmap.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_native_dialog.h>

// Constructor
game::game(){

    for(int i=5; i<25; i++){
      for(int j=-15; j<15; j++){
        gameTiles.push_back(createTile(i,j));
      }
    }
}

// Destructor
game::~game(){


}
void game::update(){

}

Tile *game::createTile(int new_x, int new_y){
    Tile *newTile= new Tile(new_x,new_y);
    return newTile;

}

// Draw to screen
void game::draw(){
  // Background
  al_clear_to_color( al_map_rgb(40,40,60));

    for(int i=0; i<gameTiles.size(); i++){
      gameTiles.at(i) -> draw();
    }



}
