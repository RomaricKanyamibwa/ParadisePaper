
#ifndef GAMEINFORMATION_H
#define GAMEINFORMATION_H

#include <string>
#include <vector>
#include <iostream>
#include "Journalist.h"
#include "Continent.h"
#include "Country.h"



/**
  * class GameInformation
  *
  */

class GameInformation
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  GameInformation ();
  GameInformation (Journalist player,Continent place):Player(player),Current_Continent(place){};

  /**
   * Empty Destructor
   */
  virtual ~GameInformation ();

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

  float Score;
  Journalist Player;
  Continent Current_Continent;
  Country Current_Country;
  unsigned int Visited_Countries;
  unsigned int Completed_Missions;
  unsigned int Total_missions;
  std::vector<Country> Visited_Places;
public:


  // Private attribute accessor methods
  //

private:

public:


  // Private attribute accessor methods
  //


  /**
   * Set the value of Score
   * @param new_var the new value of Score
   */
  void setScore (float new_var)   {
      Score = new_var;
  }

  /**
   * Get the value of Score
   * @return the value of Score
   */
  float getScore ()   {
    return Score;
  }

  /**
   * Set the value of Current_Continent
   * @param new_var the new value of Current_Continent
   */
  void setCurrent_Continent (Continent new_var)   {
      Current_Continent = new_var;
  }

  /**
   * Get the value of Current_Continent
   * @return the value of Current_Continent
   */
  Continent getCurrent_Continent ()   {
    return Current_Continent;
  }


  /**
   * Set the value of Current_Country
   * @param new_var the new value of Current_Country
   */
  void setCurrent_Country (Country new_var)   {
      Current_Country = new_var;
  }

  /**
   * Get the value of Current_Country
   * @return the value of Current_Country
   */
  Country getCurrent_Country ()   {
    return Current_Country;
  }


  /**
   * Set the value of Player
   * @param new_var the new value of Player
   */
  void setPlayer (Journalist new_var)   {
      Player = new_var;
  }

  /**
   * Get the value of Player
   * @return the value of Player
   */
  Journalist getPlayer ()   {
    return Player;
  }

  /**
   * Set the value of Visited_Countries
   * @param new_var the new value of Visited_Countries
   */
  void setVisited_Countries (unsigned int new_var)   {
      Visited_Countries = new_var;
  }

  /**
   * Get the value of Visited_Countries
   * @return the value of Visited_Countries
   */
  unsigned int getVisited_Countries ()   {
    return Visited_Countries;
  }

  /**
   * Set the value of Completed_Missions
   * @param new_var the new value of Completed_Missions
   */
  void setCompleted_Missions (unsigned int new_var)   {
      std::cout<<"GAMEINFO:new_val="<<new_var<<std::endl;
      Completed_Missions = new_var;
  }

  /**
   * Get the value of Completed_Missions
   * @return the value of Completed_Missions
   */
  unsigned int getCompleted_Missions ()   {
    return Completed_Missions;
  }

  /**
   * Set the value of Total_missions
   * @param new_var the new value of Total_missions
   */
  void setTotal_missions (unsigned int new_var)   {
      std::cout<<"GAMEINFO:new_val="<<new_var<<std::endl;
      Total_missions = new_var;
  }

  /**
   * Get the value of Total_missions
   * @return the value of Total_missions
   */
  unsigned int getTotal_missions ()   {
    return Total_missions;
  }

  /**
   * Set the value of Visited_Places
   * @param new_var the new value of Visited_Places
   */
  void setVisited_Places (std::vector<Country> new_var)   {
      Visited_Places = new_var;
  }

  /**
   * Get the value of Visited_Places
   * @return the value of Visited_Places
   */
  std::vector<Country> getVisited_Places ()   {
    return Visited_Places;
  }
  /**
   * add a value to Visited_Places
   * @param new_var the new value to add in Visited_Places
   */
  void addCountry (Country new_var)   {
      Visited_Places.push_back(new_var);
  }
private:


  void initAttributes () ;

};

#endif // GAMEINFORMATION_H
