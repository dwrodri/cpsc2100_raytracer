/******************************************************************************
   NAMES: Derek Rodriguez
   CLASS: CPSC 2100, Section 001
   DATE: Thursday Dec 3rd, 2015
   FUNCTION:  pointlight.cpp contains all of the functions included in the 
              pointlight class, which is a light found at a singular point.
******************************************************************************/

#include "pointlight.h"

using namespace std;

pointlight_t::pointlight_t() : entity_t() 
{
   /*** initialize center to <0,0,0> ***/
   center = myvector_t(0,0,0);

   /*** initialize color to <0,0,0> ***/
   color = mycolor_t(0,0,0);

   /*** initialize brightness to 0 ***/
   brightness = 0;

}

/* This constructor makes a pointlight with default values */
pointlight_t::pointlight_t(ifstream &infile) :
                           entity_t(infile, "pointlight", LIGHT) 
{
   /*** initialize center to <0,0,0> ***/
   center = myvector_t(0,0,0);

   /*** initialize color to <0,0,0> ***/
   color = mycolor_t(0,0,0);

   /*** initialize brightness to 0 ***/
   brightness = 0;
    
   /*** Invoke the load function ***/
   load(infile);

}


/* load takes in a file and reads in the values of the provided 
   attributes. 
*/
void pointlight_t::load(ifstream &infile)
{

   string token;
   infile >> token;
   while(token != ";")
   {
      if (token == "color")
      {
          infile >> color;
      }
      else if (token == "center")
      {
          infile >> center;
      }
      else if (token == "brightness")
      {
          infile >> brightness;
      }
      else
      {
          cerr << "Unknown pointlight attribute " << token << ". exiting" 
          << endl;
          exit(1);
      }
      infile >> token;
    }
}
    
/* getcenter returns the center of the light */
myvector_t pointlight_t::getcenter()
{
    
   return center;
}

/* getcolor returns the color of the light */
mycolor_t pointlight_t::getcolor()
{
   return color; 
}

/* getbrightness returns the brightness of the light */
double pointlight_t::getbrightness()
{
   return brightness; 
}

/* dump prints out all values of the pointlight */
void pointlight_t::dump()
{
   /***  first invoke the dump() function of the 
         entity_t base class
   ***/
   entity_t::dump();
   cerr << "  color:      " << color << endl;
   cerr << "  brightness: " << brightness << endl;
   cerr << "  center:     " << center << endl;
}


/** 
   determines the contribution of a pointlight on total light of the 
**/
myvector_t pointlight_t::processLight(scene_t *scene, 
                                 entity_t *ent, hitinfo_t &hit) 
{
   hitinfo_t temphit;
   /*** test object is not self occluding ***/
   myvector_t unitNormal = ~hit.getnormal();
   myvector_t unitizedDir = ~(center-hit.gethitpoint());
   
   if(unitizedDir.dot(unitNormal)<0) 
   {
   return myvector_t(0, 0, 0);
   }
   myvector_t flip = unitizedDir * -1;
   /*** call closest starting at center of the light and pointing
      * in direction of the hit point ***/ 
   myvector_t unitDir = ~(hit.gethitpoint()-center);
   entity_t *close = (entity_t *)closest(scene, center, flip, NULL, temphit);
   
   /*** Check to see if closest object is not original object ***/
   if(close != ent) return myvector_t(0,0,0);

   /*** compute and return illumination intensity ***/
   double r, g, b;
   sobj_t *sobj = (sobj_t *)close;
   myvector_t diffuse = sobj->getdiffuse();
   mycolor_t intensity = color * brightness;
   double dist = temphit.getdistance();
   double cos = unitizedDir.dot(unitNormal);
   
   /** calculate how much light of each color reaches that point **/
   r =  (diffuse.getx() * intensity.getR() * cos)/dist;
   g =  (diffuse.gety() * intensity.getG() * cos)/dist;
   b =  (diffuse.getz() * intensity.getB() * cos)/dist;

   return myvector_t(r, g, b);

}
