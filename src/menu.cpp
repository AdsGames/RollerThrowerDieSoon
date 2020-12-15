#include "menu.h"

// Init menu

// ALLEGRO_SAMPLE *menu::menu_music = nullptr;

menu::menu() {
  menu_font = al_load_ttf_font("fonts/munro.ttf", 18, 0);

  splash = tools::load_bitmap_ex("images/splash.png");
  loading = tools::load_bitmap_ex("images/loading.png");
}

// Draw images to screen
void menu::draw() {
  al_draw_bitmap(splash, 0, 0, 0);

  if (loadingb) {
    // al_draw_bitmap(loading,0,0,0);
  }
}

void menu::update() {
  if (keyListener::keyReleased[ALLEGRO_KEY_ESCAPE])
    set_next_state(STATE_EXIT);

  if (loadingb)
    set_next_state(STATE_OPTIONS);

  if (keyListener::anyKeyPressed && !keyListener::key[ALLEGRO_KEY_ESCAPE]) {
    loadingb = true;
  }
}
