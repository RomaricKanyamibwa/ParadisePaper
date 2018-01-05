
#ifndef GAME_H
#define GAME_H

#include <string>
#include "Journalist.h"


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
					ShowingMenu,CreateCharacter,Playing, Exiting };
  static GameState _gameState;
  static sf::RenderWindow _mainWindow;
  //player
  static Journalist player;

  // Private attributes
  //

public:


  // Private attribute accessor methods
  //
//
//
//  /**
//   * Set the value of _gameState
//   * @param new_var the new value of _gameState
//   */
//  void set_gameState (GameState new_var)   {
//      Game::_gameState = new_var;
//  }
//
//  /**
//   * Get the value of _gameState
//   * @return the value of _gameState
//   */
//  GameState get_gameState ()   {
//    return Game::_gameState;
//  }
//
//  /**
//   * Set the value of _mainWindow
//   * @param new_var the new value of _mainWindow
//   */
//  void set_mainWindow (sf::RenderWindow new_var)   {
//      Game::_mainWindow = new_var;
//  }
//
//  /**
//   * Get the value of _mainWindow
//   * @return the value of _mainWindow
//   */
//  sf::RenderWindow get_mainWindow ()   {
//    return Game::_mainWindow;
//  }

  static void Start();
private:

public:


  // Private attribute accessor methods
  //
    /**
   * Set the value of player
   * @param new_var the new value of player
   */
  void setplayer (Journalist new_var)   {
      player = new_var;
  }

  /**
   * Get the value of player
   * @return the value of player
   */
  Journalist getplayer ()   {
    return player;
  }

private:

  void initAttributes () ;
  static bool IsExiting();
  static void GameLoop();
  static void ShowStartScreen();
  static void ShowMenu();
  static void ShowIntro();
  static Journalist CreatePerson();

};

#endif // GAME_H
