#ifndef PARTICLE_H
#define PARTICLE_H


class Particle
{
  public:
    Particle(int,int,int);
    virtual ~Particle();
    void update();
    void draw();

  protected:

  private:
};

#endif // PARTICLE_H
