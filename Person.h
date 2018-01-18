
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
    typedef enum
    {
        Male,Female
    }Sex;

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Person ();
  Person (std::string Name,std::string Image):Display(Image),Name(Name){};
  Person (std::string Name,std::string Image,Sex sex):Display(Image),Name(Name),_Sex(sex){};
  virtual std::string greeting(std::string OtherPersonName,std::string Place)=0;

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
  Sex _Sex;
  int Money;
  //std::string Image;
public:


  // Private attribute accessor methods
  //

private:

public:


  // Private attribute accessor methods
  //


  /**
   * Set the value of _Sex
   * @param new_var the new value of _Sex
   */
  void setSex (Sex new_var)   {
      _Sex = new_var;
  }

  /**
   * Get the value of _Sex
   * @return the value of _Sex
   */
  Sex getSex ()   {
    return _Sex;
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
   * Set the value of Money
   * @param new_var the new value of Money
   */
  void setMoney (int new_var)   {
      Money = new_var;
  }

  /**
   * Get the value of Money
   * @return the value of Money
   */
  int getMoney ()   {
    return Money;
  }
  /**
   * Get the value of Money
   * @return the value of Money
   */
  std::string MoneyToString ()   {
    std::string tmpstring=Money+"€";
    return tmpstring;
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
// virtual std::string greetings()=0;
private:


  void initAttributes () ;

};

#endif // PERSON_H
