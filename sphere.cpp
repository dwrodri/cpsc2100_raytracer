/******************************************************************************
   NAMES: Derek Rodriguez and Emilie Whitesell
   CLASS: CPSC2100, Section 001
   DATE: Tuesday, November 24th, 2015
   FUNCTION: This creates spheres in the scene.
             The sphere_t class is derived from the sobj_t class.
******************************************************************************/

#include "sphere.h"
#include "math.h"

using namespace std;

// Constructor
sphere_t:: sphere_t(ifstream &infile) : sobj_t(infile, "sphere", 
             SPHERE)
{
   // initalize center to <0,0,0>
   center = myvector_t(0, 0, 0);

   // initalize radius to 0
   radius = 0;

  
   // invoke the load function
   load(infile); 
}

void sphere_t:: load(ifstream &infile) 
{
   string token;

   infile >> token;
   while(token != ";")
   {
      if (token == "center") 
      {
         infile >> center;
      }
      else
      if (token == "radius") 
      {
         infile >> radius;
      }
      else 
      {
         cerr << "Unknown sphere attribute " << token << "exiting." 
              << endl;
         exit(1);
      }

      infile >> token;
   }
}

// Methods

// Get center
myvector_t sphere_t:: getcenter() 
{
   return center;
}

// Get radius
double sphere_t:: getradius() 
{
   return radius;
}

// Sphere hit function
int sphere_t:: hits(myvector_t base, myvector_t dir, hitinfo_t &hit) {
   // calculate Points and Vectors
   myvector_t V = base;
   myvector_t D = dir;
   myvector_t C = center;
   double R = radius;
   
   // calculate V'
   myvector_t vPrime = myvector_t(V - C);
  
   // calculate a, b, and c for quadratic
   double a = D.dot(D);
   double b = 2 * vPrime.dot(D);
   double c = vPrime.dot(vPrime) - pow(R, 2);

   // calculate discriminant
   double discriminant = pow(b, 2) - 4*a*c;
   double distance = (-b - sqrt(discriminant)) / (2*a);
   myvector_t P = V + (D * distance);
   myvector_t N = ~(P - C);

   //check to see if the object was actually hit
   if (discriminant <= 0) return 0;
   if (distance < 0) return 0;
   if (P.getz() > 0) return 0;

   //save info to the hitpoint and return
   hit.setdistance(distance);
   hit.sethitpoint(P);
   hit.setnormal(N);

   return 1;
}

// Dump sphere
void sphere_t:: dump() 
{
   sobj_t::dump();   // Invoke dump() from sobj_t class
   cerr << "   center:      " << center << endl;
   cerr << "   radius:    " << radius << endl;
}
