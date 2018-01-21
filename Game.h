
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

  /**
  * cette methode initialise les principaux attributs de la classe et
  * les variables locaux.
  *
  *
  */
  static void initAttributes () ;
  /**
   * Teste si le jeu est fini en verifiant la varlable _gametstatus
   * @return bool
   */
  static bool IsExiting();

  /**
   * Cette methode  lance la boucle principale du jeu
   * @param  p
   * @param  pers
   */
  static void GameLoop(Place p,Person* pers);

  /**
   *La methode affiche l'ecran d'acceuil du jeu.
   */
  static void ShowStartScreen();
  /**
   *Methode pour afficher le menu qui va permettre
   * de commencer le jeu.
   */
  static void ShowMenu();

  /**
   *Intro du jeu avec les regles.
   */
  static void ShowIntro();
  /***
   * Cette methode affiche l'ecran d'acceuil avec les regles
   * @param  win
   */
  static void ShowGameOver(bool win);

  /**
   * Selon le choix du joueur cette methode va cree l'objet de
   * type Journalist qui contiendra les information du joueur avec
   * son sprite
   * @return Journalist
   */
  static Journalist CreatePerson();

  /**
   * Cette fonction dessine sur l'ecran les sprites d'argent et des missions
   *
   * @param  player_sprite
   * @param  money_sprite
   * @param  missions_sprite
   */
  static void Playing_func(sf::Sprite& player_sprite,sf::Sprite& money_sprite,sf::Sprite& missions_sprite);

  /**
   *
   * @param  player_sprite
   * @param  money_sprite
   * @param  missions_sprite
   */
  static void MainGameLoop(sf::Sprite& player_sprite,sf::Sprite& money_sprite,sf::Sprite& missions_sprite);

  /**
   * cette methode ecrit sur le dialog_box un message.
   * @param  msg
   */
  static void WriteDialogBox(std::string msg);

  /**
   * Ici la methode configure les images que nous utiliserons.
   */
  static void config_continent_images();

  /**
   * Cette fonction charge et affiche le continent
   * @param  continent
   * @param  payment
   */
  static void load_continent(Continent continent,bool payment=true);

  /**
   * Cette mehode charge le pays Country sur le fentre.
   * @param  country
   */
  static void load_country(Country country);

  /**
   * cette methode selon l'endroit de la souris il
   * effectue une action differente
   */
  static void MouseAction();

 /**
  * Avec cette methode on affiche le symbole de retour sur le continent.
  *
  */
  static void disp_go_back();

  /**
   * Cette methode affiche le symbole pour aller au sud d'un continet
   */
  static void disp_go_south();


};

#endif // GAME_H
