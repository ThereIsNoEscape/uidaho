/*  link.h
 */

// This is a class for a sorted linked list of integers.

//#include <bool.h>   not in CC
#include <iostream>

using namespace std;


class LinkedList
{
private:

  struct node
  {
     int info;
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
 
    // Put a node into the linked list with the value x so the
    // list remains sorted in ascending order.

   void AddNode(int x);

    // Delete the first node found with the value x, if one exists.

   void DeleteNode(int x);

    // Output the values in the nodes, one integer per line. 

   void ListNodes();

    // Return true if there in a node in the list with the value x.

   //bool IsInList(int x);
   int IsInList(int x);

    // Return a count of the number of nodes in the list.
 
   int Size();
};

