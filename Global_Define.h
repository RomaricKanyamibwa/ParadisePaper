#ifndef GLOBAL_DEFINE_H_INCLUDED
#define GLOBAL_DEFINE_H_INCLUDED

//Character Sprites and characteristics
#define NAME_MALE "Ross"
#define MALE_WIDTH 180.0
#define MALE_HEIGHT 394.0
#define NAME_FEMALE "Rania"
#define FEMALE_WIDTH 154.0
#define FEMALE_HEIGHT 394.0

#define IMAGE_MALE "images/Male.png"
#define IMAGE_MALE_NAME "images/Ross2.png"
#define IMAGE_MALE_WORLD "images/Ross_Continents-of-the-World.png"
#define IMAGE_FEMALE "images/Female.png"
#define IMAGE_FEMALE_Name "images/Rania2.png"
#define IMAGE_FEMALE_WORLD "images/Rania_Continents-of-the-World.png"

//Places Images
#define IMAGE_EUROPE "images/Europe3.png"
#define IMAGE_SOUTH_EUROPE "images/Europe_south.png"
#define IMAGE_NORTH_AMERICA "images/North_America.jpg"
#define IMAGE_SOUTH_AMERICA "images/map-of-central-and-south-america.png"
#define IMAGE_CENTRAL_AMERICA "images/central-america-with-countries.png"
#define IMAGE_ASIA "images/asia-political-map.png"
#define IMAGE_OCEANIA "images/political-map-of-australia-and-oceania.png"
#define IMAGE_AFRICA "images/Africa.jpg"
#define IMAGE_WORLD "images/Continents-of-the-World.jpg"

#define COUNTRY_IMAGE "images/country_screen.png"
#define COUNTRY_WIDTH 1080
#define COUNTRY_HEIGHT 720

#define IMAGE_DIALOG "images/Dialog.png"
#define IMAGE_DIALOG2 "images/Dialog2.png"
#define IMAGE_DIALOG3 "images/Dialog3.png"

#define DIALOG_WIDTH 260
#define DIALOG_HEIGHT 261
#define DIALOG2_WIDTH 346
#define DIALOG2_HEIGHT 145
#define DIALOG3_WIDTH 846
#define DIALOG3_HEIGHT 180

#define START_SCREEN "images/StartScreen.jpg"
#define PRESS_ANY "images/Press_any.png"
#define PLAYER_SCREEN "images/PlayerScreen.png"

#define IMAGE_MONEY "images/Money.png"
#define IMAGE_MISSIONS "images/Missions.png"
#define GO_BACK "images/goback.jpg"
#define MONEY_WIDTH 260.0
#define MONEY_HEIGHT 330.0
#define MISSIONS_WIDTH 140.0
#define MISSIONS_HEIGHT 134.0
#define GO_BACK_WIDTH 150.0
#define GO_BACK_HEIGHT 69.0
#define GO_SOUTH_WIDTH 256
#define GO_SOUTH_HEIGTH 256

#define WORLD_WIDTH 1362.0
#define WORLD_HEIGHT 629.0

#define SOUTH_EUROPE_WIDTH 1362.0
#define SOUTH_EUROPE_HEIGHT 644.0

#define NORTH_AMERICA_WIDTH 1047.0
#define NORTH_AMERICA_HEIGHT 720.0

#define SOUTH_AMERICA_WIDTH 680.0
#define SOUTH_AMERICA_HEIGHT 720.0

#define CENTRAL_AMERICA_WIDTH 1362.0
#define CENTRAL_AMERICA_HEIGHT 603.0

#define EUROPE_WIDTH 1362.0
#define EUROPE_HEIGHT 693.0

#define AFRICA_WIDTH 1024.0
#define AFRICA_HEIGHT 768.0

#define ASIA_WIDTH 1195.0
#define ASIA_HEIGHT 720.0

#define OCEANIA_WIDTH 917.0
#define OCEANIA_HEIGHT 720.0

#define EUROPE "Europe"
#define SOUTH_EUROPE "Europe du Sud"
#define WORLD "WORLD"
#define ASIA "Asie"
#define OCEANIA "Oceanie"
#define AFRICA "Afrique"
#define SOUTH_AMERICA "Amerique du Sud"
#define NORTH_AMERICA "Amerique du Nord"
#define CENTRAL_AMERICA "Amerique Centrale"
#define AMERICA "America"


#define WORLD_FILE "data/continents.txt"
#define EUROPE_FILE "data/Europe.txt"
#define SOUTH_EUROPE_FILE "data/south_europe.txt"
#define ASIA_FILE "data/asia.txt"
#define NORTH_AMERICA_FILE "data/north_america.txt"
#define CENTRAL_AMERICA_FILE "data/central_america.txt"
#define SOUTH_AMERICA_FILE "data/south_america.txt"
#define AFRICA_FILE "data/africa.txt"
#define OCEANIA_FILE "data/oceania.txt"

#define REPORTER_1_WIDTH 198.0
#define REPORTER_1_HEIGTH 384.0
#define REPORTER_Europe_WIDTH 187.0
#define REPORTER_Europe_HEIGTH 394.0
#define REPORTER_NAMERICA_WIDTH 146.0
#define REPORTER_NAMERICA_HEIGTH 351.0
#define REPORTER_OCEANIA_WIDTH 176.0
#define REPORTER_OCEANIA_HEIGTH 351.0
#define REPORTER_AFRICA_WIDTH 178.0
#define REPORTER_AFRICA_HEIGTH 398.0
#define REPORTER_ASIA_WIDTH 196.0
#define REPORTER_ASIA_HEIGTH 400.0


#define IMAGE_REPORTER_1 "images/Reporter.png"
#define IMAGE_REPORTER_Europe "images/Reporter2.png"
#define IMAGE_REPORTER_NAMERICA "images/Reporter3.png"
#define IMAGE_REPORTER_OCEANIA "images/Reporter5.png"
#define IMAGE_REPORTER_AFRICA "images/Reporter4.png"
#define IMAGE_REPORTER_ASIA "images/Reporter6.png"
#define IMAGE_GO_SOUTH "images/arrow-down.png"
#define IMAGE_GO_NORTH "images/arrow-up.png"

#define REPORTER_1 "Nadia et Pete"
#define REPORTER_2 "Leon"
#define REPORTER_3 "Colette"
#define REPORTER_4 "James"
#define REPORTER_5 "Natasa"
#define REPORTER_6 "Harry"

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
extern std::vector<Country> create_continent(std::string file_name);
extern std::vector<Continent> read_Continents();
extern Country get_country(int X,int Y,Continent continent);
extern Continent get_continent(int X,int Y,std::vector<Continent> world);
extern std::string fit_string_in_dialog_box(std::string& str);
extern Multinational create_Multinational(std::string Name);
extern std::vector<Multinational> get_Multinationals();
extern sf::Sprite getSprite(sf::Texture& texture2,Display p);
extern Continent Europe;
extern Continent North_America;
extern Continent Africa;
extern Continent South_America;
extern Continent Asia;
extern Continent Oceania;
extern void load_multinational();
#endif // GLOBAL_DEFINE_H_INCLUDED
