#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MainMenu.h"
#include <iostream>
#include "Global_Define.h"
#include "Game.h"

bool createcharacter=false;
// Constructors/Destructors
//

MainMenu::MainMenu () {
initAttributes();
}



MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{

	//Load menu image from file
	sf::Texture image;
	image.loadFromFile("images/mainmenu.png");
	sf::Sprite sprite;
	sprite.setTexture(image);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top= 145;
	playButton.rect.height = 380;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.height = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.width = 560;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}


MainMenu::MenuResult MainMenu::ShowCreate(sf::RenderWindow& window)
{

	//Load menu image from file
	window.clear();
	window.create(sf::VideoMode(768,668),"Paradise Papers"/*,sf::Style::Fullscreen*/);
	_menuItems.clear();
	sf::Texture image;
	sf::Texture person_m;
	sf::Texture person_f;
	sf::Texture choice_im;
	sf::Texture name_f;
	sf::Texture name_m;

	image.loadFromFile("images/PlayerScreen.png");
	person_f.loadFromFile("images/Female.png");
	person_m.loadFromFile("images/Male.png");
	choice_im.loadFromFile("images/Choice.png");
	name_f.loadFromFile(IMAGE_FEMALE_Name);
	name_f.setSmooth(true);
	name_m.loadFromFile(IMAGE_MALE_NAME);
	name_m.setSmooth(true);

	sf::Sprite sprite;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite_rania;
	sf::Sprite sprite_ross;

	sprite.setTexture(image);
	sprite1.setTexture(person_m);
	sprite2.setTexture(person_f);
	sprite3.setTexture(choice_im);
	sprite_rania.setTexture(name_f);
	name_f.setSmooth(true);
	sprite_ross.setTexture(name_m);
	name_m.setSmooth(true);

	//Setup clickable regions

	//MaleCharacter coordinates
	MenuItem MaleButton;
	MaleButton.rect.top= 35;
	MaleButton.rect.height = 494;
	MaleButton.rect.left = 0;
	MaleButton.rect.width = 180;
	MaleButton.action = Male;

	//FemaleCharacter item coordinates
	MenuItem FemaleButton;
	FemaleButton.rect.left = 600;
	FemaleButton.rect.height = 494;
	FemaleButton.rect.top = 35;
	FemaleButton.rect.width = 768;
	FemaleButton.action = Female;

	_menuItems.push_back(MaleButton);
	_menuItems.push_back(FemaleButton);

	window.draw(sprite);
	sprite1.setPosition(sf::Vector2f(0,25));
	sprite2.setPosition(sf::Vector2f(600,25));
	sprite3.setPosition(sf::Vector2f(250,0));
	sprite_ross.setPosition(sf::Vector2f(0,394));
	sprite_rania.setPosition(sf::Vector2f(500,394));

	window.draw(sprite1);
	window.draw(sprite2);
	window.draw(sprite3);
	window.draw(sprite_rania);
	window.draw(sprite_ross);

	window.display();
	createcharacter=true;

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for ( it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if( menuItemRect.height > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.width> x)
        {
            if((*it).action==Male)
                std::cout<<"MALE"<<std::endl;
            if((*it).action==Female)
                std::cout<<"FEMALE"<<std::endl;
            return (*it).action;
        }
        if((*it).action==Exit)
        {
            std::cout<<"EXIT"<<std::endl;
            return (*it).action;
        }
	}

	return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	MainMenu::MenuResult res;

	while(42 != 43)
	{

		while(window.pollEvent(menuEvent))
		{
		    if(menuEvent.type == sf::Event::Closed)
			{
			    window.close();
			    Game::_gameState=Game::Exiting;
				return Exit;
			}
			if(menuEvent.type == sf::Event::MouseButtonPressed)
			{
			    std::cout<<"X:"<<menuEvent.mouseButton.x<<",Y:"<<menuEvent.mouseButton.y<<std::endl;
				res=HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
				if(createcharacter)
                {
                    if(res==MainMenu::Female||MainMenu::Male==res)
                        return res;
                }
                else
                    return res;
			}

		}
	}
}


MainMenu::~MainMenu () { }

//
// Methods
//


// Accessor methods
//


// Other methods
//

void MainMenu::initAttributes () {
}

