#include "Guest.h"

Guest::Guest(){int butts;};

Guest::Guest(int x, int y){

  sprite = tools::load_bitmap_ex( "images/walk.png" );
  umbrella = tools::load_bitmap_ex( "images/Umbrella.png" );

  name = genName();
  inital = genInital();

  for( int i = 0; i < 43; i++ )
    spritesheet[i] = al_create_sub_bitmap( sprite, 0, i * 38, 17, 38);

  sprite = tools::load_bitmap_ex( "images/panic.png" );

  for( int i = 0; i < 25; i++ )
    spritesheet_panic[i] = al_create_sub_bitmap( sprite, 0, i * 36, 17, 36);

  this -> x = x;
  this -> y = y;

}

void Guest::update(){
  int threshold = 1.0f;
  float decel = 1.2f;

  if(x_velocity > -threshold && x_velocity < threshold )
    x_velocity = 0;

  if( y_velocity > -threshold && y_velocity < threshold )
    y_velocity = 0;

    if( y_velocity > 0 )
      y_velocity /= decel;

    if( y_velocity < 0)
      y_velocity /= decel;

    if( x_velocity > 0 )
      x_velocity /= decel;

    if( x_velocity < 0 )
      x_velocity /= decel;

  float speed=0.8f;

  if( y_velocity == 0 && x_velocity == 0 ){
    if( direction == 0 ){
      x +=speed;
      y -= 0.5*speed;
    }
    if( direction == 1 ){
      x +=speed;
      y += 0.5*speed;
    }
    if( direction == 2 ){
      x -=speed;
      y += 0.5*speed;
    }
    if( direction == 3 ){
      x -=speed;
      y -= 0.5*speed;
    }
  }
  else{
    x += x_velocity;
    y += y_velocity;
  }

  frame = (frame + 1) % 42;
  frame_panic = (frame + 1) % 25;
}

void Guest::draw()
{
    if( !captured )
      al_draw_bitmap( spritesheet[frame], x - 8, y-18, 0 );
    else
      al_draw_bitmap( spritesheet_panic[frame_panic], x-10, y-18, 0 );

    if(has_umbrella)
      al_draw_bitmap( umbrella, x, y, 0 );

}

std::string Guest::genName()
{
  int nameInt = 49;

  std::string names [50] = {"Ethel","Chung","Fe","Brooke","Nicky","Gail","Andrea","Sigrid","Carmon","Marybelle","Racquel","Dottie","Wilson","Myra","Jackeline","Vonda","Stacey","Jacquelynn","Phebe","Madeline","Miguelina","Loretta","Malissa","Kandy","Nancee","Petronila","Madelaine","Shakira","Jamika","Quentin","Shanell","Adrian","Clement","Gus","Hung","Tamie","Elidia","Jeneva","Shantel","Sage","Susann","Coralie","Alphonso","Stephanie","Gena","Barbera","Jesusita","Donald","Danno","Allan"};
  return names[nameInt];
}

std::string Guest::genInital()
{
  //int initalInt = tools::random_int(0,25);
  int initalInt = 18;
  std::string initals [26] = {"Q.", "W.", "E.", "R.", "T.", "Y.", "U.", "I.", "O.", "P.", "A.", "S.", "D.", "F.", "G.", "H.", "J.", "K.", "L.", "Z.", "X.", "C.", "V.", "B.", "N.", "M."};

  return initals[initalInt];
}

std::string Guest::getName()
{
  return name + " " + inital;
}

