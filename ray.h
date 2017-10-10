/** CPSC 2100  ray.h **/

#ifndef RAY_H
#define RAY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <memory.h>
#include <assert.h>
#include <iostream>
#include <fstream>

/** Includes of data types and function prototypes for ray tracer objects.

    NOTE: be VERY careful about the order of the includes.  An object
          type (typedef) MUST be declared before it can be used, including
          by another include.  
**/
#include "myvector.h"

/* For readability, equate other 3-tuple types to a myvector_t */
typedef myvector_t point_t;
typedef myvector_t intensity_t;

#include "list.h"
#include "image.h"
#include "entity.h"
#include "window.h"
#include "scene.h"
//#include "sceneobj.h"

#include "readVals.h"

#include "plane.h"
#include "sphere.h"
#include "pointlight.h"
#include "render.h"
#include "raytrace.h"
   
#endif
