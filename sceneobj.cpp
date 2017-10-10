/** CpSc 2100
    The sobj_t class is "derived" from the base entity_t class.
**/

#include "sceneobj.h"

using namespace std;

// Constructor
sobj_t:: sobj_t(ifstream &infile, const string objtype, int code) : 
       entity_t(infile, objtype, code)
{
   color = mycolor_t(0, 0, 0);
   diffuse = myvector_t(0, 0, 0);
   reflective = myvector_t(0, 0, 0);
   load(infile);
}

// Methods
void sobj_t::load(ifstream &infile) 
{
   string token;
   infile >> token;
   while(token != ";")
   {
      if (token == "color") 
      {
         infile >> color;
      }
      else if (token == "diffuse") 
      {
         infile >> diffuse;
      }
      else if (token == "reflective") 
      {
         infile >> reflective;
      }
      else 
      {
         cerr << "Unknown sobj attribute " << token << ". exiting"
              << endl;
         exit(1);
          
      }
      infile >> token;
   }
}

mycolor_t sobj_t:: getcolor() {
   return color;
}

myvector_t sobj_t:: getdiffuse() {
   return diffuse;
}

myvector_t sobj_t:: getreflective() {
   return reflective;
}

void   sobj_t:: dump() {
   entity_t::dump();   // Invoke dump() from entity_t class
   cerr << "   color:      " << color << endl;
   cerr << "   diffuse:    " << diffuse << endl;
   cerr << "   reflective: " << reflective << endl;
}
