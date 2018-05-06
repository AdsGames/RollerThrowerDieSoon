#ifndef GUEST_H
#define GUEST_H


#include "tools.h"
#include "allegro5/allegro.h"
#include "Message.h"

class Guest
{
  public:
    Guest();
    Guest(int,int);
    virtual ~Guest() {};
    virtual void draw();
    virtual void update();

    int getX(){return x;}
    int getY(){return y;}
    void setX(int d){x=d;}//XD loL
    void setY(int d){y=d;}
    void setDirection(int d){direction=d;}
    void setVelocityX(float bx){x_velocity=bx;}
    void setVelocityY(float by){y_velocity=by;}
    int getVelocityX(){return x_velocity;}
    int getVelocityY(){return y_velocity;}
    bool getIsCart(){return is_cart;}
    void setCaptured(bool b){captured=b;}
    bool giveUmbrella(){if(!has_umbrella){has_umbrella=true;return true;}return false;}
    std::string getName();

    static float speed;

  protected:
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
    bool is_cart=false;
  private:
    std::string name;
    std::string inital;
    std::string genName();
    std::string genInital();

};

#endif // GUEST_H
