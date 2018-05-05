#include "MusicManager.h"

Sound MusicManager::game_music;
Sound MusicManager::menu_music;

MusicManager::MusicManager(){

}

void MusicManager::load(){
  game_music.load_ogg("music/tojam.ogg");
  menu_music.load_ogg("music/menu.ogg");
}
