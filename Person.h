
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "Display.h"



/**
  * class Person
  *
  */

class Person : public Display
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Person ();
  Person (std::string Name,std::string Image):Display(Image),Name(Name){};

  /**
   * Empty Destructor
   */
  virtual ~Person ();

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
  //std::string Image;
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

//  /**
//   * Set the value of Image
//   * @param new_var the new value of Image
//   */
//  void setImage (std::string new_var)   {
//      Image = new_var;
//  }
//
//  /**
//   * Get the value of Image
//   * @return the value of Image
//   */
//  std::string getImage ()   {
//    return Image;
//  }
private:


  void initAttributes () ;

};

#endif // PERSON_H
