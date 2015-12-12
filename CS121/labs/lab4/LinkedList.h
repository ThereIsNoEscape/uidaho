/*  LinkedList.h
 *  Jonathan Buch
 *  Section #1
 *  Lab #4	
 *  Retrieved from: Bruce Bolden on February 15th 2015 
 */

// This is a class for a linked list for a list of doubles

#ifndef LINK_H
#define LINK_H

#ifdef NOT_USING_CC_WHATEVER_ITS_PREDEF_IS
#include <bool.h>
#endif
#include <iostream>


class LinkedList
{
private:

  struct node
  {
     double info;
     node * next;
  };

  typedef node * nodeptr;

  nodeptr start;

  int count;

public:

       // Constructor

   LinkedList()
   {
      start = NULL;
      count = 0;
   }

       // Destructor

   ~LinkedList()
   {
      nodeptr p = start, n;
 
      while (p != NULL)
      {
         n = p;
         p = p->next;
         delete n;
      }
   }
 
    // Add a node onto the front of the linked list.

   void AddNode(double x);

    // Delete the first node found with the value x, if one exists.

   void DeleteNode(double x);
   
    // Return the first node found in the list
    
   double FirstNode();

    // Output the values in the nodes in a straight line 

   void PrintNodes();

    // Return true if there in a node in the list with the value x.

   //bool IsInList(double x);
   double IsInList(double x);

    // Return a count of the number of nodes in the list.
 
   int Size();
};

#endif

