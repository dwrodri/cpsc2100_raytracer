/**  CPSC 2100 - sphere.h  **/

#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "sceneobj.h"
#include "hitinfo.h"

#define SPHERE 2

using namespace std;

class sphere_t : public sobj_t 
{
   public:
      // Constructor
      sphere_t(ifstream &infile);

      // Methods
      void     load(ifstream &infile);
      myvector_t getcenter();
      double   getradius();
      int      hits(myvector_t base, myvector_t dir, hitinfo_t &hit);
      void     dump();

  protected:
      myvector_t center;
      double   radius;
};

#endif
