#include "Sound.h"

Sound::Sound() {
  sample = nullptr;
  is_wav = false;
  is_playing = false;
}

Sound::~Sound() {
  al_destroy_sample(sample);
}

void Sound::load_wav(std::string newPath) {
  is_wav = true;
  sample = tools::load_sample_ex(newPath);
}

void Sound::load_ogg(std::string newPath) {
  sample = tools::load_sample_ex(newPath);
}

void Sound::play() {
  al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, nullptr);
}

void Sound::stop() {
  is_playing = false;

  if (!is_wav) {
    // well frick you too future self
    al_stop_samples();
  }
}

void Sound::play_random_frequency(int newMin, int newMax) {
  al_play_sample(sample, 1.0, 0.0,
                 (float)tools::random_int(newMin, newMax) / 100,
                 ALLEGRO_PLAYMODE_ONCE, nullptr);
}

void Sound::play_at_volume(float newVolume) {
  al_play_sample(sample, newVolume, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, nullptr);
}
