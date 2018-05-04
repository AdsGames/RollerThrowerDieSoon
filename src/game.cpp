#include "game.h"
#include <allegro5/bitmap.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_native_dialog.h>

// Constructor
game::game(){

    for(int i=5; i<25; i++){
      for(int j=-15; j<15; j++){
        if(i==15 && j == 14)
          gameTiles.push_back(createTile(i,j,2));
        else
          gameTiles.push_back(createTile(i,j,0));

      }
    }
  gameEnemies.push_back(new Enemy());

  entrance_back =  tools::load_bitmap_ex("images/tiles/EntranceBack.png");
  entrance_front =  tools::load_bitmap_ex("images/tiles/EntranceFront.png");



}

// Destructor
game::~game(){


}
void game::update(){
  for(int i=0; i<gameTiles.size(); i++){
    int mxo=mouseListener::mouse_x-64;
    int myo=mouseListener::mouse_y-32;
    int to=24;
//    if(mouseListener::mouse_button & 1)
//      if(mxo>gameTiles.at(i) -> getIsoX()-24 && mxo<gameTiles.at(i) -> getIsoX()+24 && myo<gameTiles.at(i) -> getIsoY()+24 && myo>gameTiles.at(i) -> getIsoY()-24){
//        gameTiles.at(i) = createTile(gameTiles.at(i) -> getX() ,gameTiles.at(i) -> getY(),1);
//      }
//    }



}
  if(selectedGuest!=nullptr)
    std::cout<<selectedGuest -> getX() <<","<<selectedGuest -> getY()<<"\n";


  //gameGuests.push_back(createGuest(200,900));
    if(mouseListener::mouse_released & 1 && selectedGuest!=nullptr){
      gameGuests.push_back(selectedGuest);
      selectedGuest=nullptr;
    }


    for(int i=0; i<gameGuests.size(); i++){
      gameGuests.at(i) -> update();

      if(tools::clicked(gameGuests.at(i) -> getX()-8,gameGuests.at(i) -> getX()+8,gameGuests.at(i) -> getY()-16,gameGuests.at(i) -> getY()+16) && selectedGuest==nullptr){
        selectedGuest=gameGuests.at(i);
        gameGuests.erase(gameGuests.begin()+i);

      }
    }


    for(int i=0; i<gameTiles.size(); i++){
      if(gameTiles.at(i) -> getType()==2){
        if(tools::random_int(1,100)==1)
        gameGuests.push_back(createGuest(gameTiles.at(i) -> getIsoX()+64 ,gameTiles.at(i) -> getIsoY()+32 ));

      }
    }

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

    al_draw_bitmap(entrance_back,129,640,0);



    for(int i=0; i<gameGuests.size(); i++){
      gameGuests.at(i) -> draw();
    }

    al_draw_bitmap(entrance_front,255,767,0);


     for(int i=0; i<gameEnemies.size(); i++){
      gameEnemies.at(i) -> draw();
    }

    if(selectedGuest!=nullptr){
      selectedGuest -> setX(mouseListener::mouse_x);
      selectedGuest -> setY(mouseListener::mouse_y);
      selectedGuest -> draw();

  }




}
