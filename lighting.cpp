/******************************************************************************
   NAMES: Derek Rodriguez and Emilie Whitesell
   CLASS: CPSC2100, Section 001
   DATE: Tuesday, November 24th, 2015
   FUNCTION: calcualtes the total amount of light hitting point hit by the ray.
******************************************************************************/

#include "myvector.h"
#include "lighting.h"
#include "pointlight.h"

/* lighting returns the total lighting on a point in the form of a vector */
myvector_t lighting(scene_t *scene, entity_t *ent, hitinfo_t &hit) 
{


   /*** declare a myvector_t object for the total light.  
     declare a pointlight_t object for list traversal
    get a pointer to the lightList in the scene
   ***/
   myvector_t totalLight = myvector_t(0,0,0);
   pointlight_t *currentLight;
   list_t *lightList = scene->lightList;
 
   /***  reset the list   ***/
   lightList->reset();

   /***  
     for each light, get the light entity, then
     invoke processLight, to compute the contribution
     of this light and add the contribution to the
     total light
   ***/
   while(lightList->hasnext())
   { 
     currentLight = (pointlight_t *)(lightList->get_entity()); 
     totalLight = totalLight + currentLight->processLight(scene, ent, hit);     
   }
   return totalLight; 
}

