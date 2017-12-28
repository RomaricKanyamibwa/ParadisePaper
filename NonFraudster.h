
#ifndef NONFRAUDSTER_H
#define NONFRAUDSTER_H
#include "Person.h"

#include <string>

/**
  * class NonFraudster
  *
  */

class NonFraudster : public Person
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  NonFraudster ();
  NonFraudster (std::string Name,std::string Image):Person(Name,Image){};

  /**
   * Empty Destructor
   */
  virtual ~NonFraudster ();

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

private:

public:


  // Private attribute accessor methods
  //

private:



};

#endif // NONFRAUDSTER_H
