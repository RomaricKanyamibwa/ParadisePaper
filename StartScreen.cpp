#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "StartScreen.h"

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
	if(!image.loadFromFile("images/StartScreen.jpg"))
	{
		return;
	}

	sf::Sprite sprite;
	sprite.setTexture(image);

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
void StartScreen::ShowIntro(sf::RenderWindow & renderWindow,std::string file)
{
	sf::Texture image;
	if(!image.loadFromFile(file))
	{
		return;
	}

	sf::Sprite sprite;
	sprite.setTexture(image);

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


