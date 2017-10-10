/******************************************************************************
   NAMES: Derek Rodriguez
   CLASS: CPSC 2100, Section 001
   DATE: Thursday, DEc 3rd, 2015
   FUNCTION:  generates rays and collects light and color data to be rendered 
******************************************************************************/

#include "raytrace.h"

/** genRay **/
myvector_t genRay(scene_t *scene, int column, int row) {
   double x;
   double y;
   double z;

   myvector_t dir;              // direction vector
   window_t *window;
   image_t *picture;
   window = scene->getWindow();
   picture = scene->getPicture();

   /* Computer the pixel's real scene coordinates */
   x = ((double)(column)/
      (double)(picture->columns-1))*window->getWindowWidth();
   x -= window->getWindowWidth()/2.0;
   
   y = ((double)(row)/
      (double)(picture->rows-1))*window->getWindowHeight();
   y -= window->getWindowHeight()/2.0;
   
   z = 0;

   dir = myvector_t(x, y, z);
   /* And now construct a unit vector from the view point to 
      the pixel 
   */
   dir = dir.diff(window->getViewPoint());
   dir = dir.unitvec();
   return dir;
} /* End genRay */

/** rayTrace **/
myvector_t raytrace(scene_t *scene, myvector_t base, myvector_t unitDir, double total_dist, entity_t *self) {

   double x;
   double y;
   double z;
   hitinfo_t newHit;
   myvector_t intensity (0.0,0.0,0.0);
   mycolor_t  closeColor(0.0, 0.0, 0.0);
   myvector_t  ambient(0.0,0.0,0.0);
   window_t *win;
   entity_t *ent = 
            (entity_t *)closest(scene, base, unitDir, self, newHit);
   sobj_t *close = (sobj_t *)ent;
   if(close == NULL)
   {
      return myvector_t(0,0,0);
   }
   total_dist += newHit.getdistance();
   win = (window_t *)scene->getWindow();
   
   ambient = win->getAmbient();
   closeColor = close->getcolor();
   
   x = closeColor.getR() * ambient.getx();
   y = closeColor.getG() * ambient.gety();
   z = closeColor.getB() * ambient.getz();

   intensity = myvector_t(x, y, z);
   

   /*** 
     invoke the lighting() function and add the result
     to intensity
   ***/
   myvector_t diffuse = lighting(scene, close, newHit);
   intensity = diffuse + intensity;
   /*** 
     scale the intensity by 1.0 / 255.0
   ***/
   double scaler = 1.0/(255.0*total_dist);
   intensity = intensity.scale(scaler);
//    Traverse objects and collect reflected light if needed 
   if(close->getreflective().length() != 0)
   { 
       self = close;
       myvector_t V = ~(unitDir.reflect(~(newHit.getnormal()),unitDir));
       myvector_t refSum=raytrace(scene,newHit.gethitpoint(),V,total_dist,self);
       refSum = myvector_t(refSum[0]*close->getreflective()[0],
                           refSum[1]*close->getreflective()[1],
                           refSum[2]*close->getreflective()[2]);
      intensity = intensity + refSum; 
    }
   return intensity;
} /* End rayTrace */


entity_t *closest(scene_t *scene, myvector_t base, 
            myvector_t unitDir, entity_t *self, hitinfo_t &hit) 
{
   entity_t *obj;
   entity_t *close = NULL;
   list_t *list = scene->sobjList; 
   hitinfo_t currhit;

   double mindist = 999999;
   int isHit;
   
   list->reset();
   while(list->hasnext())
   {
       obj = (entity_t *)list->get_entity();
       isHit = obj->hits(base,unitDir,currhit);
       if(isHit && obj != self)
       {
           if(currhit.getdistance() < mindist)
           {
               close = obj;
               mindist = currhit.getdistance();
	           hit.setdistance(currhit.getdistance());
               hit.sethitpoint(currhit.gethitpoint());
               hit.setnormal(currhit.getnormal());
           }
       }
   }
   return(close);
} /* End closest */

