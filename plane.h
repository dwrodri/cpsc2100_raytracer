/**  CPSC 2100 - plane.h **/

#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include "sceneobj.h"
#include "hitinfo.h"

#define PLANE 1

using namespace std;

class plane_t : public sobj_t {
   public:
      plane_t(ifstream &infile);
      void load(ifstream &infile);
      myvector_t getpoint();
      myvector_t getnormal();
      int hits(myvector_t base, myvector_t dir, hitinfo_t &hit);
      void   dump();

  protected:
      myvector_t point;
      myvector_t normal;
      myvector_t orient1;
      myvector_t orient2;
};

#endif
