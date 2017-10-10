/** CPSC 2100 - sceneobj.h  **/

#ifndef SOBJ_H
#define SOBJ_H

#include <iostream>
#include "entity.h"
#include "myvector.h"
#include "mycolor.h"

using namespace std;

class sobj_t : public entity_t 
{
   public:
      // Constructor
      sobj_t(ifstream &infile, const string objtype, int code);

      // Methods
      void     load(ifstream &infile);
      mycolor_t   getcolor();
      myvector_t  getdiffuse();
      myvector_t  getreflective();
      void     dump();

  private:
      //myvector_t color;
      mycolor_t color;
      myvector_t diffuse;
      myvector_t reflective;
};

#endif
