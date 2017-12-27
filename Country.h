
#ifndef Country_H
#define Country_H
#include "Place.h"

#include <string>
#include <vector>



/**
  * class Country
  *
  */
//    file.open("europe.txt");
//    list<Country> CountryEurope;
//    while(getline(file,s))
//    {
//        if(!s.empty())string
//            CountryEurope.push_back(Reaction(s));
//    }
//    for(const  auto& iter : CountryEurope)
//    {
//      std::cout << iter.normalize() << endl;
//    }
//    file.close();

class Country : public Place
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
   Country();
  Country (std::string Nom, int xg, int yh, int xd, int yb);

  /**
   * Empty Destructor
   */
  virtual ~Country ();

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

  std::string Capitale;
  int Nb_habitants;
  float Superficie;
public:


  // Private attribute accessor methods
  //

private:

public:


  // Private attribute accessor methods
  //


  /**
   * Set the value of Capitale
   * @param new_var the new value of Capitale
   */
  void setCapitale (std::string new_var)   {
      Capitale = new_var;
  }

  /**
   * Get the value of Capitale
   * @return the value of Capitale
   */
  std::string getCapitale ()   {
    return Capitale;
  }

  /**
   * Set the value of Nb_habitants
   * @param new_var the new value of Nb_habitants
   */
  void setNb_habitants (int new_var)   {
      Nb_habitants = new_var;
  }

  /**
   * Get the value of Nb_habitants
   * @return the value of Nb_habitants
   */
  int getNb_habitants ()   {
    return Nb_habitants;
  }

  /**
   * Set the value of Superficie
   * @param new_var the new value of Superficie
   */
  void setSuperficie (float new_var)   {
      Superficie = new_var;
  }

  /**
   * Get the value of Superficie
   * @return the value of Superficie
   */
  float getSuperficie ()   {
    return Superficie;
  }
private:


  void initAttributes () ;

};


#endif // Country_H
