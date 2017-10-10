/** CPSC 2100 - window.h  **/

#ifndef WINDOW_H
#define WINDOW_H

#define WINDOW_T 3311657
#define WINDOW 0

#include "ray.h"

class window_t : public entity_t
{
  public:
     window_t(ifstream &infile);
     void load(ifstream &infile); 
     void dump();
     double getWindowWidth();
     double getWindowHeight();
     myvector_t getViewPoint();
     myvector_t getAmbient();
     int getPixelColumns();

  private:
     double windowWidth;
     double windowHeight;
     myvector_t viewPoint;
     myvector_t ambient;
     int pixelColumns; 
};

#endif
