#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include<iostream>
#include<string>

//France, 200, 513, 324, 636
std::string get_country(int X,int Y)
{
    std::string country="";
    if(X>=200 && X<=324 && Y>=513 && Y<=636)
        country="France";

    return country;
}

int main()
{

  sf::RenderWindow window(sf::VideoMode(940, 880,32),"Paradises Papers");
  std::string Name="";


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
        switch (event.type)
        {
            // window closed
            case sf::Event::Closed:
                window.close();
                break;

            // key pressed
            case sf::Event::KeyPressed:
                break;

            case sf::Event::TextEntered:
            {
                if (event.text.unicode < 128)
                    {
                        std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                        Name+=static_cast<char>(event.text.unicode);
                    }
                if((event.text.unicode)==13)
                    std::cout<<"Name:"<<Name<<std::endl;
                break;
            }

            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                std::cout <<"X:"<< localPosition.x <<" Y:"<< localPosition.y <<std::endl;
                sf::Vector2u size = window.getSize();
                std::cout<<"Country:"<<get_country(localPosition.x ,localPosition.y)<<std::endl;
                unsigned int width = size.x;
                unsigned int height = size.y;
                std::cout <<"w:"<< width <<" h:"<< height <<std::endl;
                float constante = 940/846.0;
                if(width/float(height)!=constante)
                    window.setSize(sf::Vector2u(width, constante*width));


            }
            // we don't process other types of events
            default:
                break;
        }

     }

     window.draw(imageSprite);
     window.display();
  }

  return EXIT_SUCCESS;
}

//int main()
//{
//
//    // Display the list of all the video modes available for fullscreen
//    std::vector modes = sf::VideoMode::getFullscreenModes();
//
//    // Display each mode
//    for (std::size_t i = 0; i < modes.size(); ++i)
//    {
//        sf::VideoMode mode = modes[i];
//        std::cout << "Mode #" << i << "\t"
//                  << mode.width << "x" << mode.height << " \t "
//                  << mode.bitsPerPixel << " bpp" << std::endl;
//    }
//
//    // Get and display desktop mode
//    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
//    std::cout << "Desktop"  << "\t"
//              << mode.width << "x" << mode.height << " \t "
//              << mode.bitsPerPixel << " bpp" << std::endl;
//
//    // End of application
//    return 0;
//}
