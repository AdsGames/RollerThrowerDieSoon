#include "game.h"

#include <allegro5/bitmap.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_native_dialog.h>

#include "mouseListener.h"
#include "keyListener.h"
#include "joystickListener.h"
#include "button.h"


// Constructor
game::game(){
  // Init vars
  old_mouse_x = 0;
  old_mouse_y = 0;

  x_velocity = 0;
  y_velocity = 0;

  // Create map
  for( int i = 5; i < 25; i++ ){
    for( int j =- 15; j < 15; j++ ){
      if( i == 17 && j == 7 )
        gameTiles.push_back( createTile( i, j, 2 ) );
      else
        gameTiles.push_back( createTile( i, j, 0 ) );
    }
  }
  path[0] = tools::load_bitmap_ex( "images/tiles/Path_0.png" );
  path[1] = tools::load_bitmap_ex( "images/tiles/Path_1.png" );
  path[2] = tools::load_bitmap_ex( "images/tiles/Path_2.png" );
  path[3] = tools::load_bitmap_ex( "images/tiles/Path_3.png" );


  gameUI.addElement(new Button(25,25,"path_0",path[0]));
  gameUI.addElement(new Button(25+128,25,"path_1",path[1]));
  gameUI.addElement(new Button(25+128*2,25,"path_2",path[2]));
  gameUI.addElement(new Button(25+128*3,25,"path_3",path[3]));
  gameUI.addElement(new Button(25+128*4,25,"tweezer",tools::load_bitmap_ex( "images/tweezersButton.png" )));


  // Add enemy
  gameEnemies.push_back( new Enemy() );

  // Load images for entrance
  entrance_back = tools::load_bitmap_ex( "images/tiles/EntranceBack.png" );
  entrance_front = tools::load_bitmap_ex( "images/tiles/EntranceFront.png" );

  path_hover = tools::load_bitmap_ex( "images/tiles/Path_Hover.png" );


  // Load grabber images
  cursor_open = tools::load_bitmap_ex( "images/tweezersOpen.png" );
  cursor_closed = tools::load_bitmap_ex( "images/tweezersClosed.png" );
}

// Update
void game::update(){

  gameUI.update();

  if(gameUI.getElementById("path_0") -> clicked()){
    editor_tool=0;
  }
  if(gameUI.getElementById("path_1") -> clicked()){
    editor_tool=1;
  }

  if(gameUI.getElementById("path_2") -> clicked()){
    editor_tool=2;
  }

  if(gameUI.getElementById("path_3") -> clicked()){
    editor_tool=3;
  }
  if(gameUI.getElementById("tweezer") -> clicked()){
    editor_tool=4;
  }


  // Velocity of mouse
  x_velocity = -1 * ( old_mouse_x - mouseListener::mouse_x );
  y_velocity = -1 * ( old_mouse_y - mouseListener::mouse_y );

  old_mouse_x = mouseListener::mouse_x;
  old_mouse_y = mouseListener::mouse_y;

  for( int i = 0; i < gameTiles.size(); i++ ){
    int mxo = mouseListener::mouse_x - 64;
    int myo = mouseListener::mouse_y - 32;
    int to = 24;
    if(mouseListener::mouse_pressed & 1 && editor_tool==0){
      if(mxo>gameTiles.at(i) -> getIsoX()-24 && mxo<gameTiles.at(i) -> getIsoX()+24 && myo<gameTiles.at(i) -> getIsoY()+24 && myo>gameTiles.at(i) -> getIsoY()-24){
        gameTiles.at(i) = createTile(gameTiles.at(i) -> getX() ,gameTiles.at(i) -> getY(),4);
      }
    }
    if(mouseListener::mouse_pressed & 1 && editor_tool==1){
      if(mxo>gameTiles.at(i) -> getIsoX()-24 && mxo<gameTiles.at(i) -> getIsoX()+24 && myo<gameTiles.at(i) -> getIsoY()+24 && myo>gameTiles.at(i) -> getIsoY()-24){
        gameTiles.at(i) = createTile(gameTiles.at(i) -> getX() ,gameTiles.at(i) -> getY(),5);
      }
    }
    if(mouseListener::mouse_pressed & 1 && editor_tool==2){
      if(mxo>gameTiles.at(i) -> getIsoX()-24 && mxo<gameTiles.at(i) -> getIsoX()+24 && myo<gameTiles.at(i) -> getIsoY()+24 && myo>gameTiles.at(i) -> getIsoY()-24){
        gameTiles.at(i) = createTile(gameTiles.at(i) -> getX() ,gameTiles.at(i) -> getY(),6);
      }
    }
    if(mouseListener::mouse_pressed & 1 && editor_tool==3){
      if(mxo>gameTiles.at(i) -> getIsoX()-24 && mxo<gameTiles.at(i) -> getIsoX()+24 && myo<gameTiles.at(i) -> getIsoY()+24 && myo>gameTiles.at(i) -> getIsoY()-24){
        gameTiles.at(i) = createTile(gameTiles.at(i) -> getX() ,gameTiles.at(i) -> getY(),7);
      }
    }



    ///mother flipping whitespace
    ///is so fricking nice

  }


  //if( selectedGuest != nullptr )
  //  std::cout << selectedGuest -> getX() << "," << selectedGuest -> getY() << "\n";

  // Release guest
  if( (mouseListener::mouse_released & 1) && selectedGuest){
    selectedGuest -> setCaptured( false );
    selectedGuest -> setVelocityX( x_velocity );
    selectedGuest -> setVelocityY( y_velocity );

    gameGuests.push_back(selectedGuest);
    selectedGuest = nullptr;
  }

  // Enemy logic
  for( int i = 0; i < gameEnemies.size(); i++ ){
    gameEnemies.at(i) -> update();
  }

  // Run guest logic
  // In grabber
  if( selectedGuest != nullptr )
    selectedGuest -> update();

  // Rest of guests
  for( int i = 0; i < gameGuests.size(); i++ ){
    gameGuests.at(i) -> update();

    // Pick up guest
    if( tools::clicked( gameGuests.at(i) -> getX() - 25,
                        gameGuests.at(i) -> getX() + 25,
                        gameGuests.at(i) -> getY() - 45,
                        gameGuests.at(i) -> getY() + 45) && !selectedGuest){
      selectedGuest = gameGuests.at(i);
      selectedGuest -> setCaptured( true );
      gameGuests.erase( gameGuests.begin() + i );
      break;
    }

    for( int j = 0; j < gameTiles.size(); j++ ){
      int guest_x=gameGuests.at(i) -> getX()-75;
      int guest_y=gameGuests.at(i) -> getY()-0;

      if(guest_x>gameTiles.at(j) -> getIsoX()-24 && guest_x<gameTiles.at(j) -> getIsoX()+24 && guest_y<gameTiles.at(j) -> getIsoY()+24 && guest_y>gameTiles.at(j) -> getIsoY()-24){
        if(gameTiles.at(j) -> getType() == 4)
          gameGuests.at(i) -> setDirection(3);
        if(gameTiles.at(j) -> getType() == 5)
          gameGuests.at(i) -> setDirection(0);
        if(gameTiles.at(j) -> getType() == 6)
          gameGuests.at(i) -> setDirection(1);
        if(gameTiles.at(j) -> getType() == 7)
          gameGuests.at(i) -> setDirection(2);

      }
    }

    // Guest with enemy collision
    for( int j = 0; j < gameEnemies.size(); j++){
      if( tools::collision( gameGuests.at(i) -> getX(),
                            gameGuests.at(i) -> getX() + 16,
                            gameEnemies.at(j) -> getX() + 100,
                            gameEnemies.at(j) -> getX() + 400,
                            gameGuests.at(i) -> getY(),
                            gameGuests.at(i) -> getY() + 54,
                            gameEnemies.at(j) -> getY() + 100,
                            gameEnemies.at(j) -> getY() + 200)){
        gameEnemies.at(j) -> applyDamage(abs(gameGuests.at(i) -> getVelocityX()) + abs(gameGuests.at(i) -> getVelocityY()));
        gameGuests.erase( gameGuests.begin() + i );
        break;
      }
    }

    //Guest and tile collision

  }

  // Spawn guests
  for( int i = 0; i < gameTiles.size(); i++ ){
    if( gameTiles.at(i) -> getType() == 2 ){
    std::cout<<gameTiles.at(i) -> getIsoX()<<","<<gameTiles.at(i) -> getIsoY()<<".\n";
      if( tools::random_int( 1, 100 ) == 1 )
      gameGuests.push_back( createGuest( gameTiles.at(i) -> getIsoX() + 64-8,
                                         gameTiles.at(i) -> getIsoY() + 32-20 ));
    }
  }
}

// Creates a tile at screen coordinate
Tile *game::createTile( int x, int y, int type ){
  Tile *newTile = new Tile( x, y, type );
  return newTile;
}

// Creates a guest at screen coordinate
Guest *game::createGuest( int newX, int newY ){
  Guest *newGuest = new Guest( newX, newY );
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

  gameUI.draw();

  bool over_tile=false;

  int mxo = mouseListener::mouse_x - 64;
  int myo = mouseListener::mouse_y - 32;

    for( int i = 0; i < gameTiles.size(); i++ ){
      if(editor_tool==0){
        if(mxo>gameTiles.at(i) -> getIsoX()-24 && mxo<gameTiles.at(i) -> getIsoX()+24 && myo<gameTiles.at(i) -> getIsoY()+24 && myo>gameTiles.at(i) -> getIsoY()-24){
          al_draw_bitmap(path_hover,gameTiles.at(i) -> getIsoX(),gameTiles.at(i) -> getIsoY(),0);
          over_tile=true;
        }
      }
    }

  if( selectedGuest != nullptr ){
    selectedGuest -> setX( mouseListener::mouse_x );
    selectedGuest -> setY( mouseListener::mouse_y );
    selectedGuest -> draw();
    al_draw_bitmap( cursor_closed, mouseListener::mouse_x - 8, mouseListener::mouse_y - 56, 0 );
  }
  else if(editor_tool==4){
    al_draw_bitmap( cursor_open, mouseListener::mouse_x - 8, mouseListener::mouse_y - 56, 0 );
  }

    if(editor_tool==0){
      al_draw_bitmap( path[0], mouseListener::mouse_x - 64, mouseListener::mouse_y - 32, 0 );
    }

    if(editor_tool==1){
      al_draw_bitmap( path[1], mouseListener::mouse_x - 64, mouseListener::mouse_y - 32, 0 );
    }

    if(editor_tool==2){
      al_draw_bitmap( path[2], mouseListener::mouse_x - 64, mouseListener::mouse_y - 32, 0 );
    }
    if(editor_tool==3){
      al_draw_bitmap( path[3], mouseListener::mouse_x - 64, mouseListener::mouse_y - 32, 0 );
    }






}
