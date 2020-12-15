#ifndef ENEMY_H
#define ENEMY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include "tools.h"

class Enemy {
 public:
  Enemy(int x, int y);
  virtual ~Enemy();

  // Run any logic needed by enemy
  void update();

  // Draw enemy to screen
  void draw();

  // Applys a variable amount of damage
  // to enemy
  void applyDamage(int);

  // Getters for position
  int getX() { return x; }
  int getY() { return y; }
  int getHealth() { return health; }

 private:
  // Images
  ALLEGRO_BITMAP* sprite;
  ALLEGRO_BITMAP* spritesheet[62];
  ALLEGRO_FONT* font;

  // Position
  int x;
  int y;

  // Animation
  int frame = 0;

  // Hit points
  int health = 1000;
};

#endif  // ENEMY_H
