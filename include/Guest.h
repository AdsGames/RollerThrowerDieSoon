#ifndef GUEST_H
#define GUEST_H


#include "tools.h"
#include "allegro5/allegro.h"

class Guest
{
  public:
    Guest(int,int);
    virtual ~Guest() {};
    void draw();
    void update();

    int getX(){return x;}
    int getY(){return y;}
    void setX(int d){x=d;}//XD loL
    void setY(int d){y=d;}
    void setDirection(int d){direction=d;}
    void setVelocityX(float bx){x_velocity=bx;}
    void setVelocityY(float by){y_velocity=by;}
    int getVelocityX(){return x_velocity;}
    int getVelocityY(){return y_velocity;}

    void setCaptured(bool b){captured=b;}
    bool giveUmbrella(){if(!has_umbrella){has_umbrella=true;return true;}return false;}

  private:
    ALLEGRO_BITMAP *sprite;
    ALLEGRO_BITMAP *umbrella;
    ALLEGRO_BITMAP *spritesheet[43];
    ALLEGRO_BITMAP *spritesheet_panic[25];

    float x = 0;
    float y = 0;
    float x_velocity = 0;
    float y_velocity = 0;
    int frame = 0;
    int frame_panic = 0;
    int direction = 0;
    bool captured = false;
    bool has_umbrella=false;

};

#endif // GUEST_H
