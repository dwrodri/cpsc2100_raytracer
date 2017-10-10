/** CPSC 2100 - pointlight.h  **/

#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <iostream>
#include "entity.h"
#include "sceneobj.h"
#include "lighting.h"

#define LIGHT 3

using namespace std;

class pointlight_t : public entity_t 
{
   public:
      pointlight_t();
      pointlight_t(ifstream &infile);

      void load(ifstream &infile);
      myvector_t getcenter();
      mycolor_t  getcolor();
      double   getbrightness();
      void     dump();
      myvector_t processLight (scene_t *scene, entity_t *ent, hitinfo_t &hit);

  protected:
      myvector_t center;
      mycolor_t color;
      double   brightness;
};

#endif
