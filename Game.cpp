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
short int MAX_DIALOG_PHRASE_LENGTH=std::string("Please choose a Continent AAAAAAAAAAAAAAAAAAAAAAAAAAA.").length();
GameInformation DataPlayer;
Place World("World",0,0,0,0,IMAGE_WORLD);
std::vector<Country> europe=get_Europe();
std::vector<Continent> continents=get_Continents();
Continent Europe("Europe",0,0,0,0,europe);
Journalist reporter1(REPORTER_1,IMAGE_REPORTER_1);

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
    playing=0;
	if(_gameState != Uninitialized)
		return;
	_mainWindow.create(sf::VideoMode(1024,768,32),"Paradise Papers");

	_gameState= Game::ShowingStart;

	while(!IsExiting())
	{
	    if(playing)
            GameLoop(DataPlayer.getCurrent_Place(),DataPlayer.getCurrent_Place().getPerson());
        else
            GameLoop(World,reporter1);
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
        // set the string to display
        std::stringstream ss;
        std::stringstream ss2;
        ss<<DataPlayer.getPlayer().getMoney();
        std::string money_string=ss.str();
        //std::cout<<money_string<<std::endl;
        text.setString(money_string);
        // set the character size
        text.setCharacterSize(15);
        // set the color
        text.setColor(sf::Color::Black);
        text.setPosition(sf::Vector2f(Game_WIDTH-(MONEY_WIDTH*money_scale+text.getCharacterSize()/2.0*money_string.size()),MONEY_HEIGHT*money_scale/2.2));

        player_sprite.setPosition(sf::Vector2f(Game_WIDTH-MALE_WIDTH,Game_HEIGHT-REPORTER_1_HEIGTH));
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
        money_sprite=getSprite(money_texture,Display(IMAGE_MONEY));
        missions_sprite=getSprite(missions_texture,Display(IMAGE_MISSIONS));
        money_sprite.scale(money_scale,money_scale);
        missions_sprite.scale(mission_width_scale,mission_height_scale);
        money_texture.setSmooth(true);
        missions_texture.setSmooth(true);
        texture.setSmooth(true);
    }
    if(continent==WORLD)
    {
        dialog_sprite=getSprite(dialog_texture,Display(IMAGE_DIALOG3));
        dialog_texture.setSmooth(true);
    }

    sf::Texture imageSource;
    imageSprite=getSprite(imageSource,place);
    imageSource.setSmooth(true);
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
            sf::Vector2i localPosition = sf::Mouse::getPosition(_mainWindow);
            std::cout <<"X:"<< localPosition.x <<" Y:"<< localPosition.y <<std::endl;
            std::cout<<"Continent:"<<get_continent(localPosition.x,localPosition.y,continents)<<std::endl;
            sf::Vector2u size = _mainWindow.getSize();
            //std::cout<<"Country:"<<get_country(localPosition.x ,localPosition.y,Europe)<<std::endl;
            unsigned int width = size.x;
            unsigned int height = size.y;
            std::cout <<"w:"<< width <<" h:"<< height <<std::endl;
        }
        reporter_sprite.setPosition(sf::Vector2f(0,Game_HEIGHT-REPORTER_1_HEIGTH));

        _mainWindow.draw(imageSprite);
        _mainWindow.draw(reporter_sprite);
        Playing_func(player_sprite,money_sprite,missions_sprite);
        if(continent==WORLD)
        {
            dialog_sprite.setPosition(sf::Vector2f(REPORTER_1_WIDTH,Game_HEIGHT-DIALOG3_HEIGHT));
            //std::cout<<"DIALOG"<<std::endl;
            _mainWindow.draw(dialog_sprite);
            WriteDialogBox("Welcome "+DataPlayer.getPlayer().getName()+".\n"+PHRASE_EXPLORE+" Glencore.\n"+PHRASE_EXPLORE2);
        }
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
	        Journalist rania(NAME_FEMALE,IMAGE_FEMALE);
	        rania.setMoney(1000);
	        rania.setSex(Person::Female);
	        //Player=rania;
	        return rania;
	        break;
	    }
    case MainMenu::Male:
        {
            Journalist ross(NAME_MALE,IMAGE_MALE);
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
    Europe.setImage(IMAGE_EUROPE);
    Game::text.setFont(font);

    if (!Game::font.loadFromFile(FONT_FILE))
    {
        std::cerr<<"FAILED TO LOAD FONT"<<std::endl;
    }else std::cout<<"FONT LOADED"<<std::endl;

    if (!Game::music.openFromFile(MUSIC_MAIN))
        std::cerr<<"ERROR Music failed to load"<<std::endl;
    else
        std::cout<<"MusicLoaded"<<std::endl;
    Game::music.play();
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

