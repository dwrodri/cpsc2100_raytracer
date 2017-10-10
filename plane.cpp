/******************************************************************************
    NAMES: Derek Rodirguez and Emilie Whitesell
    CLASS: CPSC 2100, Section 001
    DATE: Thursday, Dec 3rd 2015
    FUNCTION: This creates planes in the scene.
              The plane_t class is derived from the sobj_t class.
******************************************************************************/

#include "plane.h"
#include "sceneobj.h"
#include "hitinfo.h"

using namespace std;

// Constructor
plane_t:: plane_t(ifstream &infile) : sobj_t(infile, "plane", PLANE)
{

   /*** initalize point to <0,0,0>  ***/
   point = myvector_t(0, 0, 0);
   
   /*** initalize normal to <0,0,0>   ***/
   normal = myvector_t(0, 0, 0);

   /*** initialize orient1 to <0,0,0> ***/
   orient1 = myvector_t(0, 0, 0);

   /*** initialize orient2 to <0,0,0> ***/
   orient2 = myvector_t(0, 0, 0);

   /*** invoke load to read values for the plane  ***/
   load(infile);

   /*** 
     invoke cross to compute the normal.  note that
     cross is a method in the myvector_t class
    ***/
   normal = orient1.cross(orient2);
   
}

void plane_t::load(ifstream &infile)
{
   string token;
   infile >> token;

   while(token != ";")
   {
      if (token == "orient1") {
         infile >> orient1;
      }
      else if(token == "orient2")
      {
         infile >> orient2;
      }
      else if (token == "point") {
         infile >> point;
      }
      else 
      {
         cerr << "bad plane token " << token 
              << ". exiting" << endl;
         exit(1);
      }

      infile >> token;
   }
}

myvector_t plane_t::getpoint() 
{
   return point;
}

myvector_t plane_t::getnormal() 
{
   return normal;
}

int plane_t::hits(myvector_t base, myvector_t dir, hitinfo_t &hit) {
   //Initialize local vars to match documaentation
   myvector_t  Q = point;   
   myvector_t  N = normal;   
   myvector_t  D = dir;              
   myvector_t  V = base;             
   myvector_t  H;                    
   double   t;                     

   //prevent divide by 0 error,
   if (N.dot(D) == 0) return 0;

   /** calculating distance from the view point to hit point **/
   t = (N.dot(Q) - N.dot(V))/(N.dot(D));
  
   /** calculating location of the hit point **/
   H = V + (D*t);

   /* Adjust the normal depending on whether ray hit from front
      or back of plane.  DO NOT delete  
   */
   hit.setdistance(t);
   hit.sethitpoint(H);
   hit.setnormal(N);

 
   if (D.dot(hit.getnormal()) > 0) 
   {
      hit.setnormal(~(N.scale(-1)));
   }
   
   //check to see if you actually hit anything
   if (t < 0) return 0;
   if (H.getz() > 0) return 0;


   return 1;  
}

void plane_t :: dump() 
{
   sobj_t::dump();   // Invoke dump() from sobj_t class
   cerr << "   orient1: " << orient1 << endl;
   cerr << "   orient2: " << orient2 << endl;
   cerr << "   point:   " << point << endl;
   cerr << "   normal:  " << normal << endl;
}
