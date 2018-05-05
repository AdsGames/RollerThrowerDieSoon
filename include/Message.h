#ifndef MESSAGE_H
#define MESSAGE_H

#include "string"
#include "allegro5/allegro.h"
#include "tools.h"
#include "allegro5/allegro_ttf.h"
#include "vector"

class Message{
  public:
    Message();
    virtual ~Message();
    static void update();
    static void draw();
    static void load();
    static int message_count;
    static void sendMessage(std::string newMessage);
    static ALLEGRO_FONT *font;
    static int time;
    static std::vector<std::string> messageList;
  protected:

  private:
};

#endif // MESSAGE_H
