/*  LinkedList.cpp
 *  Jonathan Buch
 *  Section #1
 *  Lab #4
 *  Class for a linked list of doubles.
 *  Retrieved from: Bruce Bolden on February 15th 2015
 */

#include<iostream>
#include"LinkedList.h"

using namespace std;

void LinkedList::AddNode( double x )				// Adds a node to the top of the list
{
    nodeptr n;

        //  allocate new node
    n = new node;
    n->info = x;
    count++;

    if( start == NULL )
    {
        start = n;
        n->next = NULL;
    }
    else
    {
        nodeptr tmp = start;
        n->next = tmp;
        start = n;
    }
}

void LinkedList::DeleteNode( double x )				// Deletes a node from the list
{
    nodeptr prev, curr;

    curr = start;

    while( curr != NULL && x > curr->info )
    {
        prev = curr;
        curr = curr->next;
    }

    if( x == curr->info )
    {
        if( curr == start )
            start = start->next;
        else
            prev->next = curr->next;

        delete curr;
        count--;
    }
}

double LinkedList::FirstNode()					// Returns the first node
{
    return start->info;
}


void LinkedList::PrintNodes()					// Prints the nodes in a straight line
{
    nodeptr p = start;

    while( p != NULL )
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;

}

#ifdef NOT_USING_CC_WHATEVER_ITS_PREDEF_IF
bool LinkedList::IsInList( double x )
#else
double LinkedList::IsInList( double x )				// Checks if a value is in the list
#endif
{
    nodeptr p = start;

    while( p != NULL && x > p->info )
        p = p->next;

    return (x == p->info);
}


int LinkedList::Size()						// returns the size of the list
{
    return count;
}
