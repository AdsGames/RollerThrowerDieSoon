#include "game.h"
#include <allegro5/bitmap.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_native_dialog.h>

// Constructor
game::game(){

    for(int i=5; i<25; i++){
      for(int j=-15; j<15; j++){
        gameTiles.push_back(createTile(i,j,0));
      }
    }

     for(int i=0; i<1; i++){
      for(int j=0; j<1; j++){
        gameGuests.push_back(createGuest(i,j));
      }
    }
}

// Destructor
game::~game(){


}
void game::update(){
  for(int i=0; i<gameTiles.size(); i++){
      if(mouseListener::mouse_x>gameTiles.at(i) -> getIsoX()-16 && mouseListener::mouse_x<gameTiles.at(i) -> getIsoX()+16 && mouseListener::mouse_y<gameTiles.at(i) -> getIsoY()+16 && mouseListener::mouse_y>gameTiles.at(i) -> getIsoY()-16){
        gameTiles.at(i) = createTile(gameTiles.at(i) -> getX() ,gameTiles.at(i) -> getY(),1);
      }
    }

    int x=0;
    int y=7;
    int z=y/x;
    std::cout<<"shut ur butt\n";


}

Tile *game::createTile(int new_x, int new_y, int newType){
    Tile *newTile= new Tile(new_x,new_y,newType);
    return newTile;

}

Guest *game::createGuest(int new_x, int new_y){
    Guest *newGuest= new Guest(new_x,new_y);
    return newGuest;

}


// Draw to screen
void game::draw(){
  // Background
  al_clear_to_color( al_map_rgb(40,40,60));

    for(int i=0; i<gameTiles.size(); i++){
      gameTiles.at(i) -> draw();
    }

    for(int i=0; i<gameGuests.size(); i++){
      gameGuests.at(i) -> draw();
    }



}
