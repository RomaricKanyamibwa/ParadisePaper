
#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <vector>



/**
  * class Place
  *
  */

class Place
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Place ();
  Place (std::string Nom, int xg, int yh, int xd, int yb);

  /**
   * Empty Destructor
   */
  virtual ~Place ();

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

  // Private attributes
  //

  std::string Name;
  std::vector<int> Position;
public:


  // Private attribute accessor methods
  //

private:

public:


  // Private attribute accessor methods
  //


  /**
   * Set the value of Name
   * @param new_var the new value of Name
   */
  void setName (std::string new_var)   {
      Name = new_var;
  }

  /**
   * Get the value of Name
   * @return the value of Name
   */
  std::string getName ()   {
    return Name;
  }

  /**
   * Set the value of Position
   * @param new_var the new value of Position
   */
  void setPosition (std::vector<int> new_var)   {
      Position = new_var;
  }

  /**
   * Get the value of Position
   * @return the value of Position
   */
  std::vector<int> getPosition ()   {
    return Position;
  }
private:


  void initAttributes () ;

};

#endif // PLACE_H
