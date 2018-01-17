#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Journalist.h"
#include "Game.h"
#include "StartScreen.h"
#include "Global_Define.h"
#include "MainMenu.h"
#include "iostream"
#include "GameInformation.h"
#include <sstream>      // std::stringstream
#include <SFML/Audio.hpp>


//Global Variables
//
Journalist Player;
int playing;
short int MAX_PHRASES=4;
std::string continent=WORLD;
std::string::size_type MAX_DIALOG_PHRASE_LENGTH=std::string("Please choose a Continent AAAAAAAAAAAAAAAAAAAAAAAAAAA.").size();
GameInformation DataPlayer;

std::vector<Country> europe=create_continent(EUROPE_FILE);
std::vector<Country> south_europe=create_continent(SOUTH_EUROPE_FILE);
std::vector<Country> north_america=create_continent(NORTH_AMERICA_FILE);
std::vector<Country> central_america=create_continent(CENTRAL_AMERICA_FILE);
std::vector<Country> south_america=create_continent(SOUTH_AMERICA_FILE);
std::vector<Country> africa=create_continent(AFRICA_FILE);
std::vector<Country> oceania=create_continent(OCEANIA_FILE);
std::vector<Country> asia=create_continent(ASIA_FILE);

Continent World(WORLD,0,0,0,0,IMAGE_WORLD);
Continent Europe(EUROPE,0,0,0,0,europe);
Continent South_Europe(SOUTH_EUROPE,0,0,0,0,south_europe);
Continent North_America(NORTH_AMERICA,0,0,0,0,north_america);
Continent Central_America(CENTRAL_AMERICA,0,0,0,0,central_america);
Continent South_America(SOUTH_AMERICA,0,0,0,0,south_america);
Continent Africa(AFRICA,0,0,0,0,africa);
Continent Asia(ASIA,0,0,0,0,asia);
Continent Oceania(OCEANIA,0,0,0,0,oceania);

std::vector<Continent> continents=read_Continents();
std::vector<Multinational> companies=get_Multinationals();
Journalist reporter1(REPORTER_1,IMAGE_REPORTER_1,REPORTER_1_WIDTH,REPORTER_1_HEIGTH);
std::string Dialog=PHRASE_EXPLORE;
/*static*/ sf::Texture Multinational_texture;
/*static*/ sf::Sprite Multinational_sprite;
sf::Texture Current_Place;
sf::Sprite Current_Place_spr;
sf::Texture Go_Back;
sf::Sprite Go_Back_spr;
float Go_Back_spr_scale;
sf::Texture Go_South;
sf::Sprite Go_South_spr;
float Go_Back_South_scale;
bool isSouth;
bool isCountry;
bool mission_accomplished;


sf::Sprite reporter_sprite;
sf::Sprite imageSprite;
sf::Sprite dialog_sprite;

float money_scale=0.2;
float mission_width_scale=MONEY_WIDTH/((float)MISSIONS_WIDTH)*money_scale;
float mission_height_scale=MONEY_HEIGHT/((float)MISSIONS_HEIGHT)*money_scale;
//sf::Music music;
//sf::Font font;

// A quirk of C++, static member variables need to be instantiated outside of the class
unsigned int Game::Game_HEIGHT=768;
unsigned int Game::Game_WIDTH=1024;
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
sf::Music Game::music;
sf::Font Game::font;
sf::Text Game::text;
void setDataPlayer();

 // Constructors/Destructors
//
Game::Game () {
initAttributes();
}

Game::~Game () { }

//
// Methods
//


// Accessor methods
//


// Other methods
//


void Game::Start(void)
{
    Game::initAttributes();
    Game::config_continent_images();
    playing=0;
	if(_gameState != Uninitialized)
		return;
    _mainWindow.clear();
	_mainWindow.create(sf::VideoMode(1024,667,32),"Paradise Papers");

	_gameState= Game::ShowingStart;

	while(!IsExiting())
	{
	    if(isCountry)
            GameLoop(DataPlayer.getCurrent_Country(),reporter1);
        else
            GameLoop(DataPlayer.getCurrent_Continent(),reporter1);
	}
	_mainWindow.close();
}

bool Game::IsExiting()
{
	if(_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::Playing_func(sf::Sprite& player_sprite,sf::Sprite& money_sprite,sf::Sprite& missions_sprite)
{
    if(playing)
    {
        std::stringstream ss;
        std::stringstream ss2;
        ss<<DataPlayer.getPlayer().getMoney();
        std::string money_string=ss.str();
        text.setString(money_string);
        // set the character size
        text.setCharacterSize(15);
        // set the color
        text.setColor(sf::Color::Black);
        text.setPosition(sf::Vector2f(Game_WIDTH-(MONEY_WIDTH*money_scale+text.getCharacterSize()/2.0*money_string.size()),MONEY_HEIGHT*money_scale/2.2));

        player_sprite.setPosition(sf::Vector2f(Game_WIDTH-Player.getWidth_image(),Game_HEIGHT-reporter1.getHeight_image()));
        money_sprite.setPosition(sf::Vector2f(Game_WIDTH-MONEY_WIDTH*money_scale,0));
        missions_sprite.setPosition(sf::Vector2f(Game_WIDTH-MISSIONS_WIDTH*mission_width_scale-10,MONEY_HEIGHT*money_scale+1));

        _mainWindow.draw(player_sprite);
        _mainWindow.draw(missions_sprite);
        _mainWindow.draw(money_sprite);
        _mainWindow.draw(text);
        ss2<<(int)DataPlayer.getCompleted_Missions()<<"/"<<(int)DataPlayer.getTotal_missions();
        money_string=ss2.str();
        //std::cout<<DataPlayer.getCompleted_Missions()<<std::endl;
        text.setString(money_string);
        text.setPosition(sf::Vector2f(Game_WIDTH-(/*MISSIONS_WIDTH*mission_width_scale+text.getCharacterSize()/2.0* */money_string.size()*15),(MONEY_HEIGHT*money_scale*2.1)));
        _mainWindow.draw(text);
    }
}

void Game::GameLoop(Place place,Person pers)
{
    std::string Name="";;
    sf::Texture texture;
    sf::Texture texture2;
    sf::Texture dialog_texture;
    sf::Texture money_texture;
    sf::Texture missions_texture;

    sf::Sprite player_sprite;
    reporter_sprite=getSprite(texture2,pers);
    sf::Sprite money_sprite;
    sf::Sprite missions_sprite;
    if(playing==1)
    {
        player_sprite=getSprite(texture,DataPlayer.getPlayer());
        money_texture.setSmooth(true);
        missions_texture.setSmooth(true);
        texture.setSmooth(true);
        money_sprite=getSprite(money_texture,Display(IMAGE_MONEY));
        missions_sprite=getSprite(missions_texture,Display(IMAGE_MISSIONS));
        money_sprite.scale(money_scale,money_scale);
        missions_sprite.scale(mission_width_scale,mission_height_scale);
    }
    dialog_texture.setSmooth(true);
    dialog_sprite=getSprite(dialog_texture,Display(IMAGE_DIALOG3));

    sf::Texture imageSource;
    imageSource.setSmooth(true);
    imageSprite=getSprite(imageSource,place);
	switch(_gameState)
	{
		case Game::ShowingMenu:
			{
				ShowMenu();
				break;
			}
		case Game::ShowingStart:
			{
				ShowStartScreen();
				break;
			}
        case Game::CreateCharacter:
            {
                Player=CreatePerson();
                std::cout<<"PlayerName:"<<Player.getName()<<std::endl;
                break;
            }
        case Game::Introduction:
            {
                _mainWindow.create(sf::VideoMode(WORLD_WIDTH,WORLD_HEIGHT,32),"Paradise Papers");
                World.setPerson(reporter1);
                setDataPlayer();
                ShowIntro();
                std::cout<<"DisplayIntro"<<std::endl;

                break;
            }
		case Game::Playing:
			{
			    MainGameLoop(player_sprite,money_sprite,missions_sprite);
				break;
			}
        case Game::Exiting:
            {
                _mainWindow.close();
                break;
            }
        default:
            {
                break;
            }
	}
}


void Game::load_country(Country country)
{
    isCountry=true;
    DataPlayer.addCountry(country);
    DataPlayer.setCurrent_Country(country);
    DataPlayer.getPlayer().setMoney(DataPlayer.getPlayer().getMoney()-50);
    std::cout<<"You are going to "<<country.getName()<<"."<<std::endl;
    _mainWindow.clear();
    _mainWindow.create(sf::VideoMode(COUNTRY_WIDTH,COUNTRY_HEIGHT,32),"Paradise Papers");
    std::cout<<"Going to "<<country.getName()<<std::endl;
    Game_HEIGHT=COUNTRY_HEIGHT;
    Game_WIDTH=COUNTRY_WIDTH;

}

void Game::MouseAction()
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(_mainWindow);
    std::cout <<"X:"<< localPosition.x <<" Y:"<< localPosition.y <<std::endl;
    if(continent==WORLD)
    {
        std::cout<<"Continent:"<<get_continent(localPosition.x,localPosition.y,continents).getName()<<std::endl;
        load_continent(get_continent(localPosition.x,localPosition.y,continents));
    }
    else
    {
        if(!isCountry)
        {
            Country country_tmp=get_country(localPosition.x,localPosition.y,DataPlayer.getCurrent_Continent());
            std::cout<<"Continent:"<<country_tmp.getName()<<std::endl;
            if(!country_tmp.getName().empty())
                load_country(country_tmp);
        }
    //        std::cout<<"GOOO BACK:"<<Go_South_spr.getPosition().x<<","<<Go_South_spr.getPosition().y<<std::endl;
    //        std::cout<<"GOOO BACK2:"<<Go_South_spr.getPosition().x+GO_SOUTH_WIDTH*0.2<<","<<Go_South_spr.getPosition().y+GO_SOUTH_HEIGTH*0.2<<std::endl;
    //        std::cout<<"MOUSE:"<<sf::Mouse::getPosition(_mainWindow).x<<","<<sf::Mouse::getPosition(_mainWindow).y<<std::endl;
        if(sf::Mouse::getPosition(_mainWindow).x>=Go_Back_spr.getPosition().x
           && sf::Mouse::getPosition(_mainWindow).x<=Go_Back_spr.getPosition().x+GO_BACK_WIDTH*0.5
           && sf::Mouse::getPosition(_mainWindow).y>=Go_Back_spr.getPosition().y
           && sf::Mouse::getPosition(_mainWindow).y<=Go_Back_spr.getPosition().y+GO_BACK_HEIGHT*0.5)
        {
            std::cout<<"GOOO BACK!!!!!!!!!!!"<<std::endl;
            if(!isCountry)
                load_continent(World);
            else
                load_continent(DataPlayer.getCurrent_Continent());
            isSouth=false;
            return;
        }
        if(continent==EUROPE||continent==NORTH_AMERICA
        ||continent==SOUTH_EUROPE||continent==CENTRAL_AMERICA)
        {
            if(sf::Mouse::getPosition(_mainWindow).x>=Go_South_spr.getPosition().x
            && sf::Mouse::getPosition(_mainWindow).x<=Go_South_spr.getPosition().x+GO_SOUTH_WIDTH*0.2
            && sf::Mouse::getPosition(_mainWindow).y>=Go_South_spr.getPosition().y
            && sf::Mouse::getPosition(_mainWindow).y<=Go_South_spr.getPosition().y+GO_SOUTH_HEIGTH*0.2)
            {
                if(continent==EUROPE)
                    load_continent(South_Europe,false);
                else if(continent==NORTH_AMERICA)
                    load_continent(Central_America,false);
                else if(continent==SOUTH_EUROPE)
                    load_continent(Europe,false);
                else
                    load_continent(North_America);
                isSouth=!isSouth;
                return;
            }
        }

    }
    sf::Vector2u size = _mainWindow.getSize();
    //std::cout<<"Country:"<<get_country(localPosition.x ,localPosition.y,Europe)<<std::endl;
    unsigned int width = size.x;
    unsigned int height = size.y;
    std::cout <<"Window size w:"<< width <<" h:"<< height <<std::endl;
}

void World_Dialog()
{
    Dialog=PHRASE_EXPLORE;
    Dialog="Bonjour "+DataPlayer.getPlayer().getName()+"."+Dialog.replace(Dialog.find("_"),1,companies[0].getName());
    fit_string_in_dialog_box(Dialog);
}

void Introduction_Dialog(bool publish=false)
{
    if(!publish)
    {
        if(isCountry)
        {
            Dialog="Bonjour "+DataPlayer.getPlayer().getName()+" et bienvenue en "+DataPlayer.getCurrent_Country().getName();
            Dialog+=".Je suis "+reporter1.getName();
            std::cout<<"Siege:"<<companies[0].getSiege()<<std::endl;
            std::cout<<"Current:"<<DataPlayer.getCurrent_Country()<<std::endl;

            if(companies[0].getSiege()==DataPlayer.getCurrent_Country())
            {
                Dialog+=" et je voundais vous feliciter, vous avez trouve le siege social de "+companies[0].getName()+".Maintenant vous pouvez publier votre article et gagner d'argent.";
                mission_accomplished=true;
            }
            else
                Dialog+=".Le siege de "+companies[0].getName()+"? Malheuresement vous vous etes trompe c'est pas ici.Je pense leur siege se trouve en "+companies[0].getHint_Location()+".";

            fit_string_in_dialog_box(Dialog);
            return;
        }
        Dialog="Bonjour "+DataPlayer.getPlayer().getName()+".Bienvenue en "+continent;
        Dialog+=".Vous devez trouver le pays ou se situe le siege social de "+companies[0].getName();
        Dialog+=".Vous pensez que la siege est a quelle pays?";
        fit_string_in_dialog_box(Dialog);
    }else
    {
        Dialog="Bonjour "+DataPlayer.getPlayer().getName()+".Bienvenue en "+continent;
        Dialog+=".Vous devez trouver le pays ou se situe le siege social de "+companies[0].getName();
        Dialog+=".Vous pensez que la siege est a quelle pays?";
        fit_string_in_dialog_box(Dialog);
    }
}

void Game::MainGameLoop(sf::Sprite& player_sprite,sf::Sprite& money_sprite,sf::Sprite& missions_sprite)
{
    if(playing==0)
    {
        playing=1;
        std::cout<<"PLAYING"<<std::endl;
    }
    sf::Event currentEvent;
    while((_mainWindow.pollEvent(currentEvent))&&_gameState==Game::Playing)
    {
        _mainWindow.clear(sf::Color(0,0,0));
        if(currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

        if(currentEvent.type == sf::Event::KeyPressed)
        {
            if(currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
        }
        if(sf::Event::MouseButtonPressed==currentEvent.type)
        {
            MouseAction();
        }
        reporter_sprite.setPosition(sf::Vector2f(0,Game_HEIGHT-reporter1.getHeight_image()));

        _mainWindow.draw(imageSprite);
        _mainWindow.draw(reporter_sprite);
        if(continent!=WORLD)
        {
            disp_go_back();
            Introduction_Dialog();
        }
        else
        {
            World_Dialog();
        }
        if(continent==EUROPE||continent==NORTH_AMERICA
        ||continent==SOUTH_EUROPE||continent==CENTRAL_AMERICA)
        {
            disp_go_south();
        }
        Playing_func(player_sprite,money_sprite,missions_sprite);
        if(continent==SOUTH_AMERICA)
            dialog_sprite.setPosition(sf::Vector2f(-50,Game_HEIGHT-DIALOG3_HEIGHT));
        else
            dialog_sprite.setPosition(sf::Vector2f(reporter1.getWidth_image(),Game_HEIGHT-DIALOG3_HEIGHT));
//        if(continent!=WORLD)
//        {
//
//        }
        _mainWindow.draw(dialog_sprite);
        WriteDialogBox(Dialog);
        _mainWindow.draw(Multinational_sprite);
        _mainWindow.display();
    }
}

void Game::WriteDialogBox(std::string msg)
{
        //std::cout<<money_string<<std::endl;
        text.setString(msg);
        // set the character size
        text.setCharacterSize(20);
        // set the color
        text.setColor(sf::Color::White);
        text.setPosition(sf::Vector2f(dialog_sprite.getPosition().x+70,dialog_sprite.getPosition().y+50));
        _mainWindow.draw(text);
}

void Game::ShowStartScreen()
{
	StartScreen startScreen;
	startScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result)
	{
	case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
    case MainMenu::Play:
			_gameState = Game::CreateCharacter;
			break;
    case MainMenu::Nothing:
            break;
    default:
            break;
	}
}


void Game::ShowIntro()
{
	StartScreen startScreen;
	if(Player.getSex()==Person::Female)
        startScreen.ShowIntro(_mainWindow,IMAGE_FEMALE_WORLD);
    else
        startScreen.ShowIntro(_mainWindow,IMAGE_MALE_WORLD);
	_gameState = Game::Playing;
	//std::cout<<"Dialog:"<<Dialog<<std::endl;
	Dialog="Bonjour "+DataPlayer.getPlayer().getName()+"."+Dialog.replace(Dialog.find("_"),1,companies[0].getName());
	//std::cout<<"Dialog:"<<Dialog<<std::endl;
    //Dialog.replace(Dialog.begin(),Dialog.end(),'\n',' ');
    //std::cout<<"Dialog:"<<Dialog<<std::endl;
    fit_string_in_dialog_box(Dialog);
    //std::cout<<"Dialog:"<<Dialog<<std::endl;
    load_multinational();
}

Journalist Game::CreatePerson()
{
    MainMenu create;
    MainMenu::MenuResult result = create.ShowCreate(_mainWindow);
    _gameState = Game::Introduction;
    switch(result)
	{
	case MainMenu::Female:
	    {
	        Journalist rania(NAME_FEMALE,IMAGE_FEMALE,FEMALE_WIDTH,FEMALE_WIDTH);
	        rania.setMoney(1000);
	        rania.setSex(Person::Female);
	        //Player=rania;
	        return rania;
	        break;
	    }
    case MainMenu::Male:
        {
            Journalist ross(NAME_MALE,IMAGE_MALE,MALE_WIDTH,MALE_WIDTH);
            ross.setMoney(1000);
            ross.setSex(Person::Male);
            //Player=ross;
            return ross;
            break;
        }
    default:
            return Game::CreatePerson();
            break;
	}
}


void Game::initAttributes () {
    Game::text.setFont(font);
    isSouth=false;
    isCountry=false;
    mission_accomplished=false;
    DataPlayer.setCurrent_Continent(World);
    if (!Game::font.loadFromFile(FONT_FILE))
    {
        std::cerr<<"FAILED TO LOAD FONT"<<std::endl;
    }else std::cout<<"FONT LOADED"<<std::endl;

    if (!Game::music.openFromFile(MUSIC_MAIN))
        std::cerr<<"ERROR Music failed to load"<<std::endl;
    else
        std::cout<<"MusicLoaded"<<std::endl;
    Game::music.play();
    Game::music.pause();
    Game::music.setLoop(true);
}

void /*Game::*/setDataPlayer()
{
    DataPlayer=GameInformation(Player,World);
    DataPlayer.setTotal_missions(5);
    DataPlayer.setCompleted_Missions(0);
    Game::Game_HEIGHT=WORLD_HEIGHT;
    Game::Game_WIDTH=WORLD_WIDTH;
}

void load_multinational()
{
    Multinational_sprite=getSprite(Multinational_texture,companies[0]);
    Multinational_sprite.setPosition(sf::Vector2f(0,15));
    if(companies[0].getHeight_image()>250 || companies[0].getWidth_image()>250)
        Multinational_sprite.scale(0.25,0.25);
        //(150/((float)companies[0].getWidth_image()),100/((float)companies[0].getHeight_image()));
    else
        Multinational_sprite.scale(0.4,0.4);
}

void Game::disp_go_back()
{
    Go_Back_spr=getSprite(Go_Back,Display(GO_BACK,GO_BACK_WIDTH,GO_BACK_HEIGHT));
    Go_Back_spr.scale(0.5,0.5);
    if(companies[0].getHeight_image()>250 || companies[0].getWidth_image()>250)
        Go_Back_spr_scale=0.25;
    else
        Go_Back_spr_scale=0.4;
    Go_Back_spr.setPosition(sf::Vector2f(0,Go_Back_spr_scale*companies[0].getHeight_image()+25));
    _mainWindow.draw(Go_Back_spr);
}




void Game::disp_go_south()
{
    if(isCountry)
        return;
    if(isSouth)
        Go_South_spr=getSprite(Go_South,Display(IMAGE_GO_NORTH));
    else
        Go_South_spr=getSprite(Go_South,Display(IMAGE_GO_SOUTH));
    Go_South_spr.scale(0.2,0.20);
//    if(companies[0].getHeight_image()>250 || companies[0].getWidth_image()>250)
//        Go_Back_spr_scale=0.25;
//    else
//        Go_Back_spr_scale=0.4;
    Go_South_spr.setPosition(sf::Vector2f(0,Go_Back_spr_scale*companies[0].getHeight_image()+GO_BACK_HEIGHT));
    //std::cout<<"GGGGGOOOOO SOUTGH"<<std::endl;
    _mainWindow.draw(Go_South_spr);
}


void change_reporter(std::string continent_name)
{
    if(continent_name==WORLD)
    {
        reporter1=Journalist(REPORTER_1,IMAGE_REPORTER_1,REPORTER_1_WIDTH,REPORTER_1_HEIGTH);
    }

    if(continent_name==EUROPE)
    {
        reporter1=Journalist(REPORTER_2,IMAGE_REPORTER_Europe,REPORTER_Europe_WIDTH,REPORTER_Europe_HEIGTH);
    }

    if(continent_name==NORTH_AMERICA||continent_name==SOUTH_AMERICA)
    {
        reporter1=Journalist(REPORTER_3,IMAGE_REPORTER_NAMERICA,REPORTER_NAMERICA_WIDTH,REPORTER_NAMERICA_HEIGTH);
    }
    if(continent_name==AFRICA)
    {
        reporter1=Journalist(REPORTER_4,IMAGE_REPORTER_AFRICA,REPORTER_AFRICA_WIDTH,REPORTER_AFRICA_HEIGTH);
    }
    if(continent_name==ASIA)
    {
        reporter1=Journalist(REPORTER_5,IMAGE_REPORTER_ASIA,REPORTER_ASIA_WIDTH,REPORTER_ASIA_HEIGTH);
    }
    if(continent_name==OCEANIA)
    {
        reporter1=Journalist(REPORTER_6,IMAGE_REPORTER_OCEANIA,REPORTER_OCEANIA_WIDTH,REPORTER_OCEANIA_HEIGTH);
    }
}

void Game::load_continent(Continent cont,bool payment)
{
    if(cont.getName()==EUROPE||cont.getName()==SOUTH_EUROPE||cont.getName()==ASIA
       ||cont.getName()==WORLD||cont.getName()==AFRICA||cont.getName()==SOUTH_AMERICA
       ||cont.getName()==CENTRAL_AMERICA||cont.getName()==NORTH_AMERICA||cont.getName()==OCEANIA)
    {
        if(cont.getName()==DataPlayer.getCurrent_Continent().getName()&&isCountry==false)
            return;
        change_reporter(cont.getName());
        continent=cont.getName();
        if(!isCountry)
            DataPlayer.setCurrent_Continent(cont);
        if(isCountry==true &&  mission_accomplished==true)
        {
            companies.erase(companies.begin());
            if(companies.size()<=0)
                _gameState=Game::Exiting;
            mission_accomplished=false;
            DataPlayer.getPlayer().setMoney(DataPlayer.getPlayer().getMoney()+100);
            DataPlayer.setCompleted_Missions(DataPlayer.getCompleted_Missions()+1);
            load_multinational();

        }
        _mainWindow.clear();
        _mainWindow.create(sf::VideoMode(cont.getWidth_image(),cont.getHeight_image(),32),"Paradise Papers");
        std::cout<<"Changing Continent:"<<cont.getName()<<std::endl;
        if(payment)
        {
            DataPlayer.getPlayer().setMoney(DataPlayer.getPlayer().getMoney()-10);
            //isSouth=false;
        }
        Game_HEIGHT=cont.getHeight_image();
        Game_WIDTH=cont.getWidth_image();
        isCountry=false;

    }
    else
        std::cout<<"NOT Changing Continent:"<<cont.getName()<<std::endl;

}


void Game::config_continent_images()
{
    Europe.setWidth_image(EUROPE_WIDTH);
    Europe.setHeight_image(EUROPE_HEIGHT);
    Europe.setImage(IMAGE_EUROPE);

    South_Europe.setWidth_image(SOUTH_EUROPE_WIDTH);
    South_Europe.setHeight_image(SOUTH_EUROPE_HEIGHT);
    South_Europe.setImage(IMAGE_SOUTH_EUROPE);

    North_America.setWidth_image(NORTH_AMERICA_WIDTH);
    North_America.setHeight_image(NORTH_AMERICA_HEIGHT);
    North_America.setImage(IMAGE_NORTH_AMERICA);

    Central_America.setWidth_image(CENTRAL_AMERICA_WIDTH);
    Central_America.setHeight_image(CENTRAL_AMERICA_HEIGHT);
    Central_America.setImage(IMAGE_CENTRAL_AMERICA);

    South_America.setWidth_image(SOUTH_AMERICA_WIDTH);
    South_America.setHeight_image(SOUTH_AMERICA_HEIGHT);
    South_America.setImage(IMAGE_SOUTH_AMERICA);

    Africa.setWidth_image(AFRICA_WIDTH);
    Africa.setHeight_image(AFRICA_HEIGHT);
    Africa.setImage(IMAGE_AFRICA);

    Asia.setWidth_image(ASIA_WIDTH);
    Asia.setHeight_image(ASIA_HEIGHT);
    Asia.setImage(IMAGE_ASIA);

    Oceania.setWidth_image(OCEANIA_WIDTH);
    Oceania.setHeight_image(OCEANIA_HEIGHT);
    Oceania.setImage(IMAGE_OCEANIA);

    World.setWidth_image(WORLD_WIDTH);
    World.setHeight_image(WORLD_HEIGHT);

    Go_South_spr=getSprite(Go_South,Display(IMAGE_GO_SOUTH));
}
