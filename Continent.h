
#ifndef CONTINENT_H
#define CONTINENT_H
#include "Place.h"
#include "Country.h"
#include <algorithm>    // std::find

#include <string>
#include <vector>



/**
  * class Continent
  *
  */

class Continent : public Place
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Continent ();

  Continent(std::string Nom, int xg, int yh, int xd, int yb);
  Continent(std::string Nom, int xg, int yh, int xd, int yb,std::vector<Country>& countries);
  Continent(std::string Nom, int xg, int yh, int xd, int yb,std::string image):Place(Nom,xg,yh,xd,yb,image){};
  /**
   * Empty Destructor
   */
  virtual ~Continent ();

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

public:


  // Private attribute accessor methods
  //
  std::vector<Country> countries;
  //std::string Image;
private:

public:


  // Private attribute accessor methods
  //
  /**
   * Set the value of countries
   * @param new_var the new value of countries
   */
  void setCountries (std::vector<Country> new_var)   {
      countries = new_var;
  }

  /**
   * add a value to countries
   * @param new_var the new value to add in countries
   */
  void addCountry (Country new_var)   {
      countries.push_back(new_var);
  }

  /**
   * add a value to countries
   * @param new_var the new value to add in countries
   */
  void deleteCountry (Country del_var)   {
    //std::vector<Country>::iterator it;
//      std::find(countries.begin(),countries.end(),del_var);
    for(std::vector<Country>::iterator it = countries.begin(); it != countries.end(); ++it) {
        if(*it==del_var)
        {
            countries.erase(it);
            return;
        }
    }
  }

  /**
   * Get the value of countries
   * @return the value of countries
   */
  std::vector<Country> getCountries ()   {
    return countries;
  }
//
//    /**
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



};

#endif // CONTINENT_H
