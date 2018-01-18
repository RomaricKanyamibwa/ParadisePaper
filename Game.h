
#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Audio.hpp>
#include "Journalist.h"
#include "Person.h"
#include "Continent.h"
#include "MainMenu.h"
#include "StartScreen.h"


/**
  * class Game
  *
  */

class Game
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Game ();

  /**
   * Empty Destructor
   */
  virtual ~Game ();

  // Static Public attributes
  //
  static sf::Text text;
  static sf::Font font;
  static sf::Music music;
  friend class StartScreen;
  friend class MainMenu;

  // Public attributes
  //


  // Public attribute accessor methods
  //


  // Public attribute accessor methods
  //


protected:

  // Static Protected attributes
  //

  // Protected attributes
  //

public:
      static unsigned int Game_WIDTH;
      static unsigned int Game_HEIGHT;

  // Protected attribute accessor methods
  //

protected:

public:

  // Protected attribute accessor methods
  //

protected:


private:

  // Static Private attributes
  //
  enum GameState { Uninitialized, ShowingStart, Paused,Introduction,
					ShowingMenu,CreateCharacter,Playing, Exiting,Game_over};
  static GameState _gameState;
  static sf::RenderWindow _mainWindow;
  //player


  // Private attributes
  //


public:



  static void Start();
private:

public:


  // Private attribute accessor methods
  //


  /**
   * Set the value of Game_WIDTH
   * @param new_var the new value of Game_WIDTH
   */
  void setGame_WIDTH (unsigned int new_var)   {
      Game::Game_WIDTH = new_var;
  }

  /**
   * Get the value of Game_WIDTH
   * @return the value of Game_WIDTH
   */
  unsigned int getGame_WIDTH ()   {
    return Game::Game_WIDTH;
  }

  /**
   * Set the value of Game_HEIGHT
   * @param new_var the new value of Game_HEIGHT
   */
  void setGame_HEIGHT (unsigned int new_var)   {
      Game::Game_HEIGHT = new_var;
  }

  /**
   * Get the value of Game_HEIGHT
   * @return the value of Game_HEIGHT
   */
  unsigned int getGame_HEIGHT ()   {
    return Game::Game_HEIGHT;
  }
private:

  static void initAttributes () ;
  static bool IsExiting();
  static void GameLoop(Place p,Person pers);
  static void ShowStartScreen();
  static void ShowMenu();
  static void ShowIntro();
  static void ShowGameOver(bool win);
  static Journalist CreatePerson();
  static void Playing_func(sf::Sprite& player_sprite,sf::Sprite& money_sprite,sf::Sprite& missions_sprite);
  static void MainGameLoop(sf::Sprite& player_sprite,sf::Sprite& money_sprite,sf::Sprite& missions_sprite);
  static void WriteDialogBox(std::string msg);
  static void config_continent_images();
  static void load_continent(Continent continent,bool payment=true);
  static void load_country(Country country);
  static void MouseAction();
  static void disp_go_back();
  static void disp_go_south();


};

#endif // GAME_H
