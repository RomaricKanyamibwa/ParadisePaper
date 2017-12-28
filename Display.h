
#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

/**
  * class Display
  *
  */

class Display
{
public:

  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Display ();
  Display (std::string Image):Image(Image){};

  /**
   * Empty Destructor
   */
  virtual ~Display ();

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

  std::string Image;
public:


  // Private attribute accessor methods
  //

private:

public:


  // Private attribute accessor methods
  //


  /**
   * Set the value of Image
   * @param new_var the new value of Image
   */
  void setImage (std::string new_var)   {
      Image = new_var;
  }

  /**
   * Get the value of Image
   * @return the value of Image
   */
  std::string getImage ()   {
    return Image;
  }
private:


  void initAttributes () ;

};

#endif // DISPLAY_H
