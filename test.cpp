#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include<iostream>
#include<string>
#include <fstream>
#include "Place.h"
#include "Pays.h"
#include <sstream>      // std::stringstream

std::ostream& operator<<(std::ostream & out, Pays p)
{

    out << "Country:"<<p.getName()<<",xg:"<<p.getPosition()[0]<<",yh:"<<p.getPosition()[1]<<",xd:"<<p.getPosition()[2]<<",yb:"<<p.getPosition()[3]<<std::endl;
    return out;

}
//France, 200, 513, 324, 636
std::vector<Pays> get_Europe()
{
    std::string line;
    std::ifstream myfile ("europe.txt");
    std::vector<Pays> Europe;
    if (myfile.is_open())
    {
//        getline (myfile,line);
        while ( getline (myfile,line) )
        {
            std::string Nom;
            int xg=0,yh=0,xd=0,yb=0;
            std::stringstream ss;
            replace(line.begin(), line.end(), ',', ' ');
//            replace(line.begin(), line.end(), ',', ' ');
            ss<<line;
            ss>>Nom>>xg>>yh>>xd>>yb;
            if(!Nom.empty())
            {
                Pays Country(Nom,xg,yh,xd,yb);
                //std::cout<<"TEST SS:"<<Country<<std::endl;
                Europe.push_back(Country);
            }
            //std::cout << line <<std::endl;
            //std::cout <<"Constr:"<<Nom<<xg<<yh<<xd<<yb<<std::endl;
        }
    myfile.close();
    }
    else std::cout << "Unable to open file";
    return Europe;
}
std::string get_country(int X,int Y,std::vector<Pays> continent)
{
    std::string country="";
    //std::string Nom;
    //int xg,yh,xd,yb;
    //std::stringstream ss;
//    Pays france=Pays("France",200,324,513,6360);
//    std::string line;
//    std::ifstream myfile ("europe.txt");
//    std::vector<Pays> Europe;
//    if (myfile.is_open())
//    {
////        getline (myfile,line);
//        while ( getline (myfile,line) )
//        {
//            std::string Nom;
//            int xg,yh,xd,yb;
//            std::stringstream ss;
//            replace(line.begin(), line.end(), ',', ' ');
////            replace(line.begin(), line.end(), ',', ' ');
//            ss<<line;
//            ss>>Nom>>xg>>yh>>xd>>yb;
//            if(!Nom.empty())
//            {
//                Pays Country(Nom,xg,yh,xd,yb);
//                std::cout<<"TEST SS:"<<Country<<std::endl;
//                Europe.push_back(Country);
//            }
//            //std::cout << line <<std::endl;
//            //std::cout <<"Constr:"<<Nom<<xg<<yh<<xd<<yb<<std::endl;
//        }
//    myfile.close();
//    }
//    else std::cout << "Unable to open file";
    std::vector<int> Pos;
    for(auto & value: continent) {
//        std::cout<<value<<std::endl;
        //Pos=value.getPosition();
        if(X>=value.getPosition()[0] && X<=value.getPosition()[2]
           && Y>=value.getPosition()[1] && Y<=value.getPosition()[3])
        {
            country=value.getName();
            break;
        }


    }
//    if(X>=200 && X<=324 && Y>=513 && Y<=636)
//        country="France";

    return country;
}

int main()
{

  sf::RenderWindow window(sf::VideoMode(940, 680,32),"Paradises Papers");
  std::string Name="";
  std::vector<Pays> Europe=get_Europe();


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
                std::cout<<"Country:"<<get_country(localPosition.x ,localPosition.y,Europe)<<std::endl;
                unsigned int width = size.x;
                unsigned int height = size.y;
                std::cout <<"w:"<< width <<" h:"<< height <<std::endl;
                //float constante = 940/846.0;
                //if(width/float(height)!=constante)
                  //  window.setSize(sf::Vector2u(width, constante*width));


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

