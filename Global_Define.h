#ifndef GLOBAL_DEFINE_H_INCLUDED
#define GLOBAL_DEFINE_H_INCLUDED

#define NAME_MALE "Ross"
#define MALE_WIDTH 180.0
#define MALE_HEIGHT 394.0
#define NAME_FEMALE "Rania"
#define FEMALE_WIDTH 154.0
#define FEMALE_HEIGHT 394.0
#define IMAGE_MALE "images/Male.png"
#define IMAGE_MALE_NAME "images/Ross.png"
#define IMAGE_MALE_WORLD "images/Ross_Continents-of-the-World.png"
#define IMAGE_FEMALE "images/Female.png"
#define IMAGE_FEMALE_Name "images/Rania.png"
#define IMAGE_FEMALE_WORLD "images/Rania_Continents-of-the-World.png"
#define IMAGE_EUROPE "images/Europe.png"
#define IMAGE_WORLD "images/Continents-of-the-World.jpg"
#define IMAGE_DIALOG "images/Dialog.png"
#define DIALOG_WIDTH 260
#define DIALOG_HEIGHT 261
#define IMAGE_DIALOG2 "images/Dialog2.png"
#define DIALOG2_WIDTH 346
#define DIALOG2_HEIGHT 145
#define IMAGE_DIALOG3 "images/Dialog3.png"
#define DIALOG3_WIDTH 846
#define DIALOG3_HEIGHT 180
#define IMAGE_MONEY "images/Money.png"
#define MONEY_WIDTH 260
#define MONEY_HEIGHT 330
#define IMAGE_MISSIONS "images/Missions.png"
#define MISSIONS_WIDTH 140
#define MISSIONS_HEIGHT 134
#define START_SCREEN "images/StartScreen.jpg"
#define PLAYER_SCREEN "images/PlayerScreen.png"
#define WORLD_WIDTH 1362.0
#define EUROPE_WIDTH 2200.0
#define WORLD_HEIGHT 629.0
#define EUROPE_HEIGHT 1790.0
#define EUROPE "Europe"
#define WORLD "WORLD"
#define ASIA "Asia"
#define OCEANIA "Oceania"
#define AFRICA "Africa"
#define SOUTH_AMERICA "South America"
#define NORTH_AMERICA "North America"
#define AMERICA "America"
#define REPORTER_1 "Nadia et Pete"
#define REPORTER_1_WIDTH 198.0
#define REPORTER_1_HEIGTH 384.0
#define IMAGE_REPORTER_1 "images/Reporter.png"
#define REPORTER_2 "Dacid"
#define REPORTER_3 "Colette"
#define REPORTER_4 "James"


#include "Continent.h"

extern std::ostream& operator<<(std::ostream & out, Country p);
extern std::vector<Country> get_Europe();
extern std::string get_country(int X,int Y,Continent continent);
extern sf::Sprite getSprite(sf::Texture& texture2,Display p);
#endif // GLOBAL_DEFINE_H_INCLUDED
