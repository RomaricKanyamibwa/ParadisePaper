
#ifndef MULTINATIONAL_H
#define MULTINATIONAL_H
#include "Display.h"

#include <string>
#include <vector>

#include "Country.h"


/**
  * class Multinational
  *
  */

class Multinational : public Display
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Multinational ();
  Multinational (std::string image,std::string name,Country siege,std::string descr)
  :Display(image),Name(name),Siege(siege),Description(descr){};

  /**
   * Empty Destructor
   */
  virtual ~Multinational ();

  // Static Public attributes
  //

  // Public attributes
  //


   std::vector<Country> m_societes_ecranVector;

  // Public attribute accessor methods
  //


  // Public attribute accessor methods
  //


  /**
   * Add a Societes_Ecran object to the m_societes_ecranVector List
   */
  void addSocietes_Ecran (Country add_object);

  /**
   * Remove a Societes_Ecran object from m_societes_ecranVector List
   */
  void removeSocietes_Ecran (Country remove_object);

  /**
   * Get the list of Societes_Ecran objects held by m_societes_ecranVector
   * @return std::vector<Country *> list of Societes_Ecran objects held by
   * m_societes_ecranVector
   */
  std::vector<Country> getSocietes_EcranList ();

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
  std::string Hint_Location;
  Country Siege;
  std::string Description;
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
   * Set the value of Siege
   * @param new_var the new value of Siege
   */
  void setSiege (Country new_var)   {
      Siege = new_var;
  }

  /**
   * Get the value of Siege
   * @return the value of Siege
   */
  Country getSiege ()   {
    return Siege;
  }

  /**
   * Set the value of Description
   * @param new_var the new value of Description
   */
  void setDescription (std::string new_var)   {
      Description = new_var;
  }

  /**
   * Get the value of Description
   * @return the value of Description
   */
  std::string getDescription ()   {
    return Description;
  }

  /**
   * Set the value of Hint_Location
   * @param new_var the new value of Hint_Location
   */
  void setHint_Location (std::string new_var)   {
      Hint_Location = new_var;
  }

  /**
   * Get the value of Hint_Location
   * @return the value of Hint_Location
   */
  std::string getHint_Location ()   {
    return Hint_Location;
  }
private:


  void initAttributes () ;

};

#endif // MULTINATIONAL_H
