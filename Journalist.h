
#ifndef JOURNALIST_H
#define JOURNALIST_H
#include "NonFraudster.h"

#include <string>

/**
  * class Journalist
  *
  */

class Journalist : public NonFraudster
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Journalist ();
  Journalist (std::string Name,std::string Image):NonFraudster(Name,Image){};

  /**
   * Empty Destructor
   */
  virtual ~Journalist ();

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

#endif // JOURNALIST_H
