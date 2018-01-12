
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
  Display (std::string Image,int image_w,int image_h):Image(Image),width_image(image_w),height_image(image_h){};

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
  int width_image;
  int height_image;
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

  /**
   * Set the value of width_image
   * @param new_var the new value of width_image
   */
  void setWidth_image (int new_var)   {
      width_image = new_var;
  }

  /**
   * Get the value of width_image
   * @return the value of width_image
   */
  int getWidth_image ()   {
    return width_image;
  }

  /**
   * Set the value of heigh_image
   * @param new_var the new value of heigh_image
   */
  void setHeight_image (int new_var)   {
      height_image = new_var;
  }

  /**
   * Get the value of heigh_image
   * @return the value of heigh_image
   */
  int getHeight_image ()   {
    return height_image;
  }
private:


  void initAttributes () ;

};

#endif // DISPLAY_H
