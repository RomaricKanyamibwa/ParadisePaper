#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "StartScreen.h"
#include "Global_Define.h"
#include "Game.h"

// Constructors/Destructors
//

StartScreen::StartScreen () {
}

StartScreen::~StartScreen () { }

//
// Methods
//


// Accessor methods
//


// Other methods
//
void StartScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	sf::Texture image_press;
	if(!image.loadFromFile("images/StartScreen.jpg"))
	{
		return;
	}

    if(!image_press.loadFromFile(PRESS_ANY))
	{
		return;
	}

	sf::Sprite sprite;
	sf::Sprite sprite2;
	sprite.setTexture(image);
	image_press.setSmooth(true);
	sprite2.setTexture(image_press);

	sprite2.setPosition(sf::Vector2f(1200.0/2.0-293,667.0/2.0-100));
	//sprite2.setColor(sf::Color(255, 255, 255, 255)); // half transparent
    renderWindow.draw(sprite);
	renderWindow.draw(sprite2);
	renderWindow.display();

	sf::Event event;
	while(true)
	{
		while(renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed)
			{
				return;
			}
			else if(event.type == sf::Event::EventType::Closed )
                renderWindow.close();
                Game::_gameState=Game::Exiting;
		}
	}
}
void StartScreen::ShowIntro(sf::RenderWindow & renderWindow,std::string file)
{
	sf::Texture image;
	if(!image.loadFromFile(file))
	{
		return;
	}

	sf::Sprite sprite;
	sprite.setTexture(image);
	image.setSmooth(true);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while(true)
	{
		while(renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed )
			{
				return;
			}
		}
	}
}


