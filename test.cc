#include <SFML/Graphics.hpp>

int main()
{


  sf::RenderWindow window(sf::VideoMode(940, 880, 32), "SFML");


  sf::Texture imageSource;
  if(!imageSource.loadFromFile("Europe.png", sf::IntRect(10, 10, 2200,1760)))
      return EXIT_FAILURE;
  sf::Sprite imageSprite;
  imageSprite.setTexture(imageSource);
  imageSprite.scale(0.5,0.5);
  sf::Texture texture;
  texture.setSmooth(true);

  while(window.isOpen())
  {
     sf::Event event;
     while(window.pollEvent(event))
     {


     }

     window.draw(imageSprite);
     window.display();
  }

  return EXIT_SUCCESS;
}
