#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
//#include <tchar.h>
#include<iostream>
#include<string>
#include <fstream>
//#include "Place.h"
//#include "Country.h"
#include "Global_Define.h"
#include "Game.h"
#include "StartScreen.h"
#include "MainMenu.h"
//#include "Journalist.h"
//#include "Continent.h"
#include <sstream>      // std::stringstream

std::ostream& operator<<(std::ostream & out, Country p)
{

    out << "Country:"<<p.getName()<<",xg:"<<p.getPosition()[0]<<",yh:"<<p.getPosition()[1]<<",xd:"<<p.getPosition()[2]<<",yb:"<<p.getPosition()[3]<<std::endl;
    return out;

}
//France, 200, 513, 324, 636
std::vector<Country> get_Europe()
{
    std::string line;
    std::ifstream myfile (EUROPE_FILE);
    std::vector<Country> Europe;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::string Nom;
            int xg=0,yh=0,xd=0,yb=0;
            std::stringstream ss;
            replace(line.begin(), line.end(), ',', ' ');
            ss<<line;
            ss>>Nom>>xg>>yh>>xd>>yb;
            if(!Nom.empty())
            {
                Country Country(Nom,xg,yh,xd,yb);
                Europe.push_back(Country);
            }
        }
    std::cout<<"Europe Loaded sucessfully"<<std::endl;
    myfile.close();
    }
    else std::cerr << "Unable to open file"<<std::endl;
    return Europe;
}

std::vector<Continent> read_Continents()
{
    std::string line;
    std::ifstream myfile (WORLD_FILE);
    std::vector<Continent> Continents;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::string Nom;
            int xg=0,yh=0,xd=0,yb=0;
            std::stringstream ss;
            replace(line.begin(), line.end(), ',', ' ');
            ss<<line;
            ss>>Nom>>xg>>yh>>xd>>yb;
            std::cout<<"Continent:"<<Nom<<std::endl;
            std::replace( Nom.begin(), Nom.end(), '_', ' ');
            if(!Nom.empty())
            {
                if(Nom=="Europe")
                {
                    Continent continent(Nom,xg,yh,xd,yb,europe);
                    Continents.push_back(continent);
                }
                else
                {
                    Continent continent(Nom,xg,yh,xd,yb);
                    Continents.push_back(continent);
                }
            }
        }
    std::cout<<"Continents Loaded sucessfully"<<std::endl;
    myfile.close();
    }
    else std::cerr << "Unable to open file "<<WORLD_FILE<<std::endl;
    return Continents;
}

Country get_country(int X,int Y,Continent continent)
{
    Country country;
    std::vector<int> Pos;
    for(auto & value: continent.getCountries()) {
        if(X>=value.getPosition()[0] && X<=value.getPosition()[2]
           && Y>=value.getPosition()[1] && Y<=value.getPosition()[3])
        {
            country=value;
            break;
        }


    }
    return country;
}

std::vector<Multinational> get_Multinationals()
{
    std::vector<Multinational> companies;
    std::string line;
    std::ifstream myfile (MULTINATIONALS);
        if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            //replace(line.begin(), line.end(), ',', ' ');
            std::cout<<"Multinational:"<<line<<std::endl;
            if(!line.empty())
            {
                Multinational comp=create_Multinational(line);
                companies.push_back(comp);
            }
        }
    std::cout<<"Multinationals Loaded sucessfully"<<std::endl;
    myfile.close();
    }
    else std::cerr << "Unable to open file "<<MULTINATIONALS<<std::endl;


    return companies;
}

Multinational create_Multinational(std::string Name)
{
    Multinational m;
    std::string line;
    std::ifstream myfile ("data/"+Name+".txt");
        if (myfile.is_open())
    {
        std::string image;
        std::string descr;
        Country siege;
        int height,width;
        std::vector<Country> societes_ecran;
        if(getline (myfile,line))
        {
            std::stringstream ss;
            replace(line.begin(), line.end(), ',', ' ');
            ss<<line;
            ss>>image>>width>>height;
            image="images/logo multinationales/"+image;
        }
        else std::cerr << "Unable to get "<<Name<<"'s image."<<std::endl;

        if(getline (myfile,line))
            descr=line;
        else std::cerr << "Unable to get "<<Name<<"'s description."<<std::endl;
        if(getline (myfile,line))
            siege=Country(line,0,0,0,0);
        else std::cerr << "Unable to get "<<Name<<"'s siege."<<std::endl;
        while ( getline (myfile,line) )
        {
            societes_ecran.push_back(Country(line,0,0,0,0));
        }
        std::cout<<Name<<" was successfully created."<<std::endl;
        m=Multinational(image,Name,siege,descr);
        m.setWidth_image(width);
        m.setHeight_image(height);
        m.m_societes_ecranVector=societes_ecran;
    }
    else std::cerr << "Unable to open file \"data/"<<Name<<".txt\""<<std::endl;
    return m;
}

Continent get_continent(int X,int Y,std::vector<Continent> continents)
{
    Continent cont;
    std::vector<int> Pos;
    for(auto & value: continents) {
        if(X>=value.getPosition()[0] && X<=value.getPosition()[2]
           && Y>=value.getPosition()[1] && Y<=value.getPosition()[3])
        {
            cont=value;
            //std::replace( country.begin(), country.end(), '_', ' ');
            break;
        }
    }
    if(cont.getName()==EUROPE)
        return Europe;
    if(cont.getName()==NORTH_AMERICA)
        return North_America;
    if(cont.getName()==SOUTH_AMERICA)
        return South_America;
    if(cont.getName()==AFRICA)
        return Africa;
    if(cont.getName()==ASIA)
        return Asia;
    if(cont.getName()==OCEANIA)
        return Oceania;
    return cont;
}

sf::Sprite getSprite(sf::Texture& texture2,Display p)
{
    sf::Sprite sprite;
    if (!texture2.loadFromFile(p.getImage()))
    {
        // error...
        std::cerr<<"Failled to load player!!"<<std::endl;
    }else
    {
        sprite.setTexture(texture2);
    }
    return sprite;
}

std::string fit_string_in_dialog_box(std::string& str)
{
    std::string::size_type str_size=str.size();
    if(str_size<=MAX_DIALOG_PHRASE_LENGTH)
        return str;
    else
    {
        std::string tmpstr =str.substr(MAX_DIALOG_PHRASE_LENGTH,str_size-MAX_DIALOG_PHRASE_LENGTH);
        str=str.substr(0,MAX_DIALOG_PHRASE_LENGTH);
        //std::cout<<"TMP"<<tmpstr<<std::endl;
        std::string::size_type last=str.find_last_of(" ");
        str=str.replace(last,1,"\n");
        fit_string_in_dialog_box(tmpstr);
        str=str+tmpstr;
    }
    //std::cout<<"Fitted word:"<<str<<std::endl;
    return str;
}

int Game(sf::RenderWindow& window)
{

  //window(sf::VideoMode(940, 680,32),"Paradises Papers");
  std::string Name="";
  std::vector<Country> europe=get_Europe();
  Continent Europe("Europe",0,0,0,0,europe);
  Europe.setImage("Europe.png");
  Journalist reporter("Nadia et Pete","Reporter.png");
  sf::Texture texture2;
  sf::Sprite reporter_sprite=getSprite(texture2,reporter);


  sf::Texture imageSource;
  sf::Sprite imageSprite=getSprite(imageSource,Europe);
  imageSprite.setTexture(imageSource);
  imageSprite.scale(0.5,0.5);
  //sf::Texture texture;
  //texture.setSmooth(true);

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
                std::cout<<"Country:"<<get_country(localPosition.x ,localPosition.y,Europe).getName()<<std::endl;
                unsigned int width = size.x;
                unsigned int height = size.y;
                std::cout <<"w:"<< width <<" h:"<< height <<std::endl;
                //float constante = 940/846.0;
                //if(width/float(height)!=constante)
                //  window.setSize(sf::Vector2u(width, constante*width));
                break;
            }
            // we don't process other types of events
            default:
                break;
        }

     }
     reporter_sprite.setPosition(sf::Vector2f(0,25));
     window.draw(imageSprite);
     window.draw(reporter_sprite);
     window.display();
  }

  return EXIT_SUCCESS;
}




int main(int argc,char* argv[])
{
	Game::Start();
	Game::music.stop();
	return 0;
}



