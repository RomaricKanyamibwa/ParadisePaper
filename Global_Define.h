#ifndef GLOBAL_DEFINE_H_INCLUDED
#define GLOBAL_DEFINE_H_INCLUDED

#define NAME_MALE "Ross"
#define NAME_FEMALE "Rania"
#define IMAGE_MALE "images/Male.png"
#define IMAGE_MALE_NAME "images/Ross.png"
#define IMAGE_MALE_GlOBE "images/Ross_Continents-of-the-World.png"
#define IMAGE_FEMALE "images/Female.png"
#define IMAGE_FEMALE_Name "images/Rania.png"
#define IMAGE_FEMALE_GLOBE "images/Rania_Continents-of-the-World.png"
#define IMAGE_EUROPE "images/Europe.png"
#define IMAGE_EARTH "images/Continents-of-the-World.jpg"
#define STARTS_CREEN "images/StartScreen.jpg"
#define PLAYER_SCREEN "images/PlayerScreen.png"
#define GlOBE_WIDTH 1362
#define GlOBE_HEIGHT 629

#include "Continent.h"

extern std::ostream& operator<<(std::ostream & out, Country p);
extern std::vector<Country> get_Europe();
extern std::string get_country(int X,int Y,Continent continent);
extern sf::Sprite getSprite(sf::Texture& texture2,Display p);
#endif // GLOBAL_DEFINE_H_INCLUDED
