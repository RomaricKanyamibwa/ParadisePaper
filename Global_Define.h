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
#define IMAGE_EUROPE "images/Europe2.png"
#define IMAGE_NORTH_AMERICA "images/North_America.jpg"
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
#define GO_BACK "images/goback.jpg"
#define GO_BACK_WIDTH 150
#define GO_BACK_HEIGHT 69
#define WORLD_WIDTH 1362.0
#define EUROPE_WIDTH 900.0
#define NORTH_AMERICA_WIDTH 1047.0
#define WORLD_HEIGHT 629.0
#define EUROPE_HEIGHT 720.0
#define NORTH_AMERICA_HEIGHT 720.0
#define EUROPE "Europe"
#define EUROPE_FILE "data/Europe.txt"
#define WORLD "WORLD"
#define WORLD_FILE "data/continents.txt"
#define ASIA "Asia"
#define ASIA_FILE "data/asia.txt"
#define OCEANIA "Oceania"
#define AFRICA "Africa"
#define SOUTH_AMERICA "South America"
#define NORTH_AMERICA "Amerique du Nord"
#define AMERICA "America"
#define REPORTER_1 "Nadia et Pete"
#define REPORTER_1_WIDTH 198.0
#define REPORTER_1_HEIGTH 384.0
#define IMAGE_REPORTER_1 "images/Reporter.png"
#define REPORTER_Europe_WIDTH 187.0
#define REPORTER_Europe_HEIGTH 394.0
#define REPORTER_NAMERICA_WIDTH 146.0
#define REPORTER_NAMERICA_HEIGTH 351.0
#define IMAGE_REPORTER_Europe "images/Reporter2.png"
#define IMAGE_REPORTER_NAMERICA "images/Reporter3.png"
#define REPORTER_2 "Leon"
#define REPORTER_3 "Colette"
#define REPORTER_4 "James"

#define MUSIC_MAIN "sounds/TheChain.ogg"

#define FONT_FILE "data/Belgrano-Regular.ttf"
#define MULTINATIONALS "data/MultiNational.txt"

#define PHRASE_EXPLORE "Vous devez trouver le pays ou se situe le siege social de _ .Pour cela choisissez d'abord un continent puis vous pourrez proposer un pays."

#include "Continent.h"
#include "Multinational.h"

//
//extern sf::Font font;
//extern sf::Music music;
extern std::string::size_type MAX_DIALOG_PHRASE_LENGTH;
extern short int MAX_PHRASES;
extern std::vector<Country> europe;
extern std::ostream& operator<<(std::ostream & out, Country p);
extern std::vector<Country> get_Europe();
extern std::vector<Continent> read_Continents();
extern Country get_country(int X,int Y,Continent continent);
extern Continent get_continent(int X,int Y,std::vector<Continent> world);
extern std::string fit_string_in_dialog_box(std::string& str);
extern Multinational create_Multinational(std::string Name);
extern std::vector<Multinational> get_Multinationals();
extern sf::Sprite getSprite(sf::Texture& texture2,Display p);
extern Continent Europe;
extern Continent North_America;
extern void load_multinational();
#endif // GLOBAL_DEFINE_H_INCLUDED
