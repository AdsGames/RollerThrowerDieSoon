#include "game.h"
#include <allegro5/bitmap.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_native_dialog.h>

// Constructor
game::game(){
  for( int i = 5; i < 25; i++ ){
    for( int j =- 15; j < 15; j++ ){
      if( i == 15 && j == 14 )
        gameTiles.push_back( createTile( i, j, 2 ) );
      else
        gameTiles.push_back( createTile( i, j, 0 ) );
    }
  }

  gameEnemies.push_back(new Enemy());

  entrance_back = tools::load_bitmap_ex( "images/tiles/EntranceBack.png" );
  entrance_front = tools::load_bitmap_ex( "images/tiles/EntranceFront.png" );

  cursor_open = tools::load_bitmap_ex( "images/tweezersOpen.png" );
  cursor_closed = tools::load_bitmap_ex( "images/tweezersClosed.png" );
}

// Destructor
game::~game(){

}

// Update
void game::update(){
  x_velocity = -1.3 * ( old_mouse_x - mouseListener::mouse_x );
  y_velocity = -1.3 * ( old_mouse_y - mouseListener::mouse_y );

  old_mouse_x = mouseListener::mouse_x;
  old_mouse_y = mouseListener::mouse_y;

  if( selectedGuest != nullptr )
    selectedGuest -> update();

  for( int i = 0; i < gameTiles.size(); i++ ){
    int mxo = mouseListener::mouse_x-64;
    int myo = mouseListener::mouse_y-32;
    int to = 24;
    //    if(mouseListener::mouse_button & 1)
    //      if(mxo>gameTiles.at(i) -> getIsoX()-24 && mxo<gameTiles.at(i) -> getIsoX()+24 && myo<gameTiles.at(i) -> getIsoY()+24 && myo>gameTiles.at(i) -> getIsoY()-24){
    //        gameTiles.at(i) = createTile(gameTiles.at(i) -> getX() ,gameTiles.at(i) -> getY(),1);
    //      }
    //    }
  }

  if( selectedGuest != nullptr )
    std::cout << selectedGuest -> getX() << "," << selectedGuest -> getY() << "\n";

  //gameGuests.push_back(createGuest(200,900));
  if( (mouseListener::mouse_released & 1) && selectedGuest){
    selectedGuest -> setCaptured( false );
    selectedGuest -> setVelocityX( x_velocity );
    selectedGuest -> setVelocityY( y_velocity );

    gameGuests.push_back(selectedGuest);
    selectedGuest=nullptr;
  }

  for( int i = 0; i < gameEnemies.size(); i++ ){
    gameEnemies.at(i) -> update();
  }


  for( int i = 0; i < gameGuests.size(); i++ ){
    gameGuests.at(i) -> update();

    if( tools::clicked( gameGuests.at(i) -> getX() - 25,
                        gameGuests.at(i) -> getX() + 25,
                        gameGuests.at(i) -> getY() - 45,
                        gameGuests.at(i) -> getY() + 45) && !selectedGuest){
      selectedGuest = gameGuests.at(i);
      selectedGuest -> setCaptured( true );
      gameGuests.erase( gameGuests.begin() + i );
      break;
    }

    for( int j = 0; j < gameEnemies.size(); j++){
      if( tools::collision( gameGuests.at(i) -> getX(),
                            gameGuests.at(i) -> getX() + 16,
                            gameEnemies.at(j) -> getX() + 100,
                            gameEnemies.at(j) -> getX() + 400,
                            gameGuests.at(i) -> getY(),
                            gameGuests.at(i) -> getY() + 54,
                            gameEnemies.at(j) -> getY() + 100,
                            gameEnemies.at(j) -> getY() + 200)){
        gameGuests.erase( gameGuests.begin() + i );
      }
    }
  }

  for( int i = 0; i < gameTiles.size(); i++ ){
    if( gameTiles.at(i) -> getType() == 2 ){
      if( tools::random_int( 1, 100 ) == 1 )
      gameGuests.push_back( createGuest( gameTiles.at(i) -> getIsoX() + 64,
                                         gameTiles.at(i) -> getIsoY() + 32 ));
    }
  }
}

// Creates a tile at screen coordinate
Tile *game::createTile( int x, int y, int type ){
  Tile *newTile = new Tile( x, y, type );
  return newTile;
}

// Creates a guest at screen coordinate
Guest *game::createGuest( int x, int y ){
  Guest *newGuest = new Guest( x, y );
  return newGuest;
}

// Draw to screen
void game::draw(){
  // Background
  al_clear_to_color( al_map_rgb( 40, 40, 60 ) );

  for( int i = 0; i < gameTiles.size(); i++ )
    gameTiles.at(i) -> draw();

  al_draw_bitmap( entrance_back, 129, 640, 0 );

  for( int i = 0; i < gameGuests.size(); i++ )
    gameGuests.at(i) -> draw();

  al_draw_bitmap( entrance_front, 255, 767, 0 );

  for( int i = 0; i < gameEnemies.size(); i++ )
    gameEnemies.at(i) -> draw();

  if( selectedGuest != nullptr ){
    selectedGuest -> setX(mouseListener::mouse_x);
    selectedGuest -> setY(mouseListener::mouse_y);
    selectedGuest -> draw();
    al_draw_bitmap(cursor_closed,mouseListener::mouse_x-8,mouseListener::mouse_y-56,0);
  }
  else{
    al_draw_bitmap(cursor_open,mouseListener::mouse_x-8,mouseListener::mouse_y-56,0);
  }
}
