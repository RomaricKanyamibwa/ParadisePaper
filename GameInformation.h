
#ifndef GAMEINFORMATION_H
#define GAMEINFORMATION_H

#include <string>
#include <vector>
#include "Journalist.h"
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
  GameInformation (Journalist player,Place place):Player(player),Current_Place(place){};

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
  Place Current_Place;
  unsigned char Visited_Countries;
  unsigned char Completed_Missions;
  unsigned char Total_missions;
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
   * Set the value of Current_Place
   * @param new_var the new value of Current_Place
   */
  void setCurrent_Place (Place new_var)   {
      Current_Place = new_var;
  }

  /**
   * Get the value of Current_Place
   * @return the value of Current_Place
   */
  Place getCurrent_Place ()   {
    return Current_Place;
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
  void setVisited_Countries (unsigned char new_var)   {
      Visited_Countries = new_var;
  }

  /**
   * Get the value of Visited_Countries
   * @return the value of Visited_Countries
   */
  unsigned char getVisited_Countries ()   {
    return Visited_Countries;
  }

  /**
   * Set the value of Completed_Missions
   * @param new_var the new value of Completed_Missions
   */
  void setCompleted_Missions (unsigned char new_var)   {
      Completed_Missions = new_var;
  }

  /**
   * Get the value of Completed_Missions
   * @return the value of Completed_Missions
   */
  unsigned char getCompleted_Missions ()   {
    return Completed_Missions;
  }

  /**
   * Set the value of Total_missions
   * @param new_var the new value of Total_missions
   */
  void setTotal_missions (unsigned char new_var)   {
      Total_missions = new_var;
  }

  /**
   * Get the value of Total_missions
   * @return the value of Total_missions
   */
  unsigned char getTotal_missions ()   {
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
