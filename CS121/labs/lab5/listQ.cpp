/*  ListQ.cpp
 *
 *  Jonathan Buch
 *  Section #1
 *  Lab #5
 *  Retrieved From Prof. Bruce Bolden on February 24th, 2015
 *
 *  Class for a sorted linked list of integers.
 */

//#include <bool.h>
#include <iostream>

#include "listQ.h"

using namespace std;

void LinkedList::AddNode(int x)
{
    nodeptr n, nTmp;

    n = new node;
    n->info = x;
    n->next = NULL;
    count++;

    if( start == NULL )
    {
        start = n;
        end   = start;
    }
    else
    {
        end->next = n;
        nTmp = end;
        end  = nTmp->next;
    }
}
//  \end{verbatim}  \lecpb  \begin{verbatim}
void LinkedList::DeleteNode()
{
    nodeptr curr;

    if( start != NULL )
    {
        curr = start;
        start = start->next;
        delete curr;
        
        count--;
    }
}

int LinkedList::FirstNode()
{
    int  iVal;
    
    if( start != NULL )
        iVal = start->info;
        
    return iVal;
}

int LinkedList::LastNode()
{
    if( end != NULL )
        return end->info;
}
//  \end{verbatim}  \lecpb  \begin{verbatim}
void LinkedList::PrintNodes()
{
    nodeptr p = start;

    while( p != NULL )
    {
        cout << p->info << endl;
        p = p->next;
    }

}


bool LinkedList::IsInList(int x)
{
    nodeptr p = start;

    while (p != NULL && x > p->info)
        p = p->next;

    return (x == p->info);
}


int LinkedList::Size()
{
    return count;
}
 
