#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Journalist.h"
#include "Game.h"
#include "StartScreen.h"
#include "Global_Define.h"
#include "MainMenu.h"
#include "iostream"
// Constructors/Destructors
//

Journalist Player;
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
	if(_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024,768,32),"Paradise Papers");

	_gameState= Game::ShowingStart;

	while(!IsExiting())
	{
		GameLoop();
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

void Game::GameLoop()
{
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
                _mainWindow.create(sf::VideoMode(1024,768,32),"Paradise Papers");
                break;
            }
        case Game::Introduction:
            {
                _mainWindow.create(sf::VideoMode(GlOBE_WIDTH,GlOBE_HEIGHT,32),"Paradise Papers");
                ShowIntro();
                std::cout<<"DisplayIntro"<<std::endl;
                _mainWindow.create(sf::VideoMode(1024,768,32),"Paradise Papers");
                break;
            }
		case Game::Playing:
			{
				sf::Event currentEvent;
				while(_mainWindow.pollEvent(currentEvent))
					{
					_mainWindow.clear(sf::Color(0,0,0));
					_mainWindow.display();
					if(currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

					if(currentEvent.type == sf::Event::KeyPressed)
						{
							if(currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
						}
					}
				break;
			}
        default:
            {
                break;
            }
	}
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
        startScreen.ShowIntro(_mainWindow,IMAGE_FEMALE_GLOBE);
    else
        startScreen.ShowIntro(_mainWindow,IMAGE_MALE_GlOBE);
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
            return Journalist("","");
            break;
	}
}

// A quirk of C++, static member variables need to be instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;

void Game::initAttributes () {
}

