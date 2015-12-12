/*  Link.cpp
 *
 *  Class for a sorted linked list of integers.
 */

//#include <bool.h>    not in CC
#include <iostream>

using namespace std;

#include "link.h"



void LinkedList::AddNode(int x)
{
    nodeptr n, prev, curr;

    n = new node;
    n->info = x;
    count++;

    if (start == NULL)
    {
        start = n;
        n->next = NULL;
    }
    else
    {
        curr = start;
        while ( curr != NULL && x > curr->info )
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == start)
        {
           n -> next = start;
           start = n;
        }
        else
        {
           prev->next = n;
           n -> next = curr;
        }
    }
}


void LinkedList::DeleteNode(int x)
{
    nodeptr prev, curr;

    curr = start;

    while (curr != NULL && x > curr->info)
    {
        prev = curr;
        curr = curr->next;
    }

    if (x == curr->info)
    {
        if ( curr == start )
            start = start->next;
        else
            prev->next = curr->next;

        delete curr;
        count--;
    }
}


void LinkedList::ListNodes()
{
    nodeptr p = start;

    while (p != NULL)
    {
        cout << p->info << endl;
        p = p->next;
    }

}


//bool LinkedList::IsInList(int x)
int LinkedList::IsInList(int x)
{
    nodeptr p = start;

    while (p != NULL && x > p->info)
        p = p->next;

    return (x == p->info);
    //return (int)(x == p->info);
}


int LinkedList::Size()
{
    return count;
}
 
