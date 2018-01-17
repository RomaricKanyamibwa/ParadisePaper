
#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <vector>
#include "Display.h"
#include "Person.h"
#include <iostream>

/**
  * class Place
  *
  */

class Place : public Display
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Place ();
  Place (std::string Nom, int xg, int yh, int xd, int yb);
  Place (std::string Nom, int xg, int yh, int xd, int yb,std::string Image);

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
  Person pers;
public:


  // Private attribute accessor methods
  //

private:

public:


  // Private attribute accessor methods
  //

  bool operator==(Place c)
  {
      bool b=true;
      int i=0;
      if(this->Position.size()!=c.getPosition().size())
        return false;
      for(auto const& value:c.getPosition())
      {
          b=this->Position[i++]==value && b;
      }
      std::cout<<"Position:Result of =="<<(b)<<std::endl;
      std::cout<<"Result of =="<<(this->Name.compare(c.getName())==0 && b)<<std::endl;
      return (this->Name.compare(c.getName())==0) && b;
  }

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

  /**
   * Set the value of pers
   * @param new_var the new value of pers
   */
  void setPerson (Person new_var)   {
      pers = new_var;
  }

  /**
   * Get the value of pers
   * @return the value of pers
   */
  Person getPerson ()   {
    return pers;
  }
private:


  void initAttributes () ;

};

#endif // PLACE_H
