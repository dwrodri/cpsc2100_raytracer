#ifndef HITINFO_H
#define HITINFO_H

#include <iostream>
#include "myvector.h"

using namespace std;

class hitinfo_t {
   public:
      void     setdistance(const double &value);
      void     sethitpoint(const myvector_t &H);
      void     setnormal(const myvector_t &N);
      double   getdistance();
      myvector_t gethitpoint();
      myvector_t getnormal();

  protected:
      double   distance;
      myvector_t hitpoint;
      myvector_t normal;
};

#endif
