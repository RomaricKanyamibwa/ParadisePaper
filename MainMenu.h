
#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include <list>

/**
  * class MainMenu
  *
  */

class MainMenu
{
public:
    enum MenuResult { Nothing, Exit, Play,Female,Male};
    struct MenuItem
    {
      public:
          sf::Rect<int> rect;
          MenuResult action;
    };
  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  MainMenu ();
  MenuResult Show(sf::RenderWindow& window);
  MenuResult ShowCreate(sf::RenderWindow& window);

  /**
   * Empty Destructor
   */
  virtual ~MainMenu ();

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

  std::list<MenuItem> _menuItems;
  MenuResult GetMenuResponse(sf::RenderWindow& window);
  MenuResult HandleClick(int x, int y);

private:

  // Static Private attributes
  //

  // Private attributes
  //

public:


  // Private attribute accessor methods
  //

private:

public:


  // Private attribute accessor methods
  //


  /**
   * Set the value of _menuItems
   * @param new_var the new value of _menuItems
   */
  void set_menuItems (std::list<MenuItem> new_var)   {
      _menuItems = new_var;
  }

  /**
   * Get the value of _menuItems
   * @return the value of _menuItems
   */
  std::list<MenuItem>& get_menuItems ()   {
    return _menuItems;
  }
private:


  void initAttributes () ;

};

#endif // MAINMENU_H
