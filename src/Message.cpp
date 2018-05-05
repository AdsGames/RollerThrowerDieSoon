#include "Message.h"
int Message::message_count=0;
int Message::time=100;
ALLEGRO_FONT *Message::font;
std::vector<std::string> Message::messageList;

void Message::sendMessage(std::string newMessage){

messageList.push_back(newMessage);
time=120;
}

Message::Message()
{

}

void Message::load(){
    font = al_load_ttf_font( "font/font.ttf", 18, 0 );


}

Message::~Message()
{
  //dtor
}

void Message::update(){
  time--;
  if(time<=0){
    time=120;
    if(messageList.size()>0)
      messageList.erase(messageList.begin());
  }
}

void Message::draw(){

    if(messageList.size()>0){


      for(int i=messageList.size()-1; i>-1; i--)
      //for(int i=0; i<messageList.size(); i++)
        al_draw_textf( font, al_map_rgb( 255, 255, 255 ), 1500, -(1040+(i*20)), 0, messageList.at(i).c_str()  );
  }
}
