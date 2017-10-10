/** CPSC 2100 - raytrace.h  **/

#ifndef RAYTRACE_H
#define RAYTRACE_H

#include "ray.h"

/** Prototype statements **/
myvector_t raytrace(scene_t *scene, myvector_t base, 
                       myvector_t unitDir,
                 double total_dist, entity_t *self);
entity_t       *closest(scene_t *scene, myvector_t base, 
                        myvector_t unitDir, 
                 entity_t *self, hitinfo_t &hit);
myvector_t  genRay(scene_t *scene, int columnNdx, int rowIndx);

#endif
