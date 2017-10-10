/** CPSC 2100
    list.h - specification file for the list_t class  
**/

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

class node_t
{
  public:
     node_t();
     node_t(void *);
     ~node_t();

     void set_next(node_t *);
     node_t *get_nextPtr();
     void   *get_entval();

  private:
     void   *objPtr;        /* pointer to associated object */
     node_t *next;          /* pointer to next node         */
};


class list_t
{
  public:
    list_t();
    ~list_t();

    void add(void *obj);         /* Insert object into list  */
    void  reset();
    void *get_entity();
    int hasnext();
   
   private:
     node_t *head;
     node_t *current;
};


#endif

