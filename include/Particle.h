#ifndef PARTICLE_H
#define PARTICLE_H

#include "allegro.h"
#include "tools.h"

class Particle
{
  public:
    Particle(int,int,int);
    virtual ~Particle();
    bool update();
    void draw();

  protected:

  private:
    ALLEGRO_BITMAP *sprite;
    int x;
    int y;
    int lifetime=0;
};

#endif // PARTICLE_H
