/** CPSC 2100 - scene.cpp  **/

#include "ray.h"
#include "sceneobj.h"

using namespace std;

/** getindex **/

/** constructor  **/
scene_t::scene_t(ifstream &infile)
{
   sobjList = new list_t();
   lightList = new list_t();

   loadScene(infile);
}

/** loadScene **/
void scene_t::loadScene(ifstream &infile)
{
   string token;
   entity_t *obj;
   pointlight_t *lgt;
// entity_t::load(ifstream, token);

   /* Start processing scene description language */
   while (infile >> token)
   {
      if(token == "window") 
      {
         window = new window_t(infile);
      }   
      else if(token == "plane")
      {
         obj = new plane_t(infile);
         sobjList->add((void *)obj);
      }
      else if (token == "sphere")
      {
         obj = new sphere_t(infile);
         sobjList->add((void *)obj);
      }
      else if(token == "pointlight")
      {
         lgt = new pointlight_t(infile);
         lightList->add((void *)lgt);
      } 
      else
      {
         cerr << "Unknown token " << token << endl;
         exit(1);
      }
    }

/** completeScene **/
   // assert(window->magic == WINDOW_T);

   picture = newImage(window->getPixelColumns(), 
             window->getPixelColumns()*
             window->getWindowHeight()/
             window->getWindowWidth(), 255);
}

/** dumpScene **/
void scene_t::dumpScene()
{
   sobj_t *obj;         // object_t pointer
   pointlight_t *lgt;         // object_t pointer
   list_t *list;
   //assert(scene->magic == SCENE_T);


    cerr <<  "\nPixel Height :    " 
        << picture->rows << endl;

   /* First dump the window data */
   /* Print the separately computed pixel rows value */
   
    cerr << "\nDUMP OF WINDOW\n";
    window->dump();

   /* Now dump the scene objects list */
   cerr <<  "\nDUMP OF SCENE OBJECTS:\n";
   
   list = sobjList;
   list->reset();

   while(list->hasnext())
   {
       obj = (sobj_t *)list->get_entity();
       obj->dump();

   }

   /* Next print light data */
   cerr << "\nDUMP OF LIGHT LIST:\n";

   list = lightList;
   list->reset();

   while(list->hasnext())
   {
      lgt = (pointlight_t *)list->get_entity();
      lgt->dump();
   }
}


window_t * scene_t::getWindow()
{
   return window;
}

image_t *scene_t::getPicture()
{
   return picture;
}
