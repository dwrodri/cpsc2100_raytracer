/* CPSC 2100 List functions */

#include "list.h"

node_t::node_t()
{
   objPtr = NULL;
   next = NULL;
}

node_t::node_t(void *objPtr)
{
   this->objPtr = objPtr;
   next = NULL;
}

node_t:: ~node_t()
{ }

void node_t::set_next(node_t *nextPtr)
{
   next = nextPtr;
}
   
node_t * node_t::get_nextPtr()
{
   return next;
}

void * node_t::get_entval()
{
   
   return objPtr;
}


list_t::list_t()
{
   head = NULL;
}

list_t::~list_t() {}

   
/** add -- add an object to the linked list **/
void list_t::add(void *objPtr) 
{
   node_t *newNode= new node_t(objPtr);

   
   newNode->set_next(head);
   head = newNode;
}

void  list_t::reset()
{
   current = head;
}

void * list_t::get_entity()
{
    assert(current != NULL);
    void * ent = current->get_entval();
    current = current->get_nextPtr();
    return ent;
}


int list_t::hasnext()
{
   int val = 0;
   if(current != NULL)
      val = 1;
   return val;
}

