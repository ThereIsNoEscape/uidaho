/*
 *
 *
 */

#include <iostream>
#include "LL.h"
using namespace std;


void LinkedList::AddtoFront(int x)
{
	nodeptr n = new node;
	n->data = x;
	count++;
	if( head == NULL )
	{
		head = n;
		n->next = NULL;
	}
	else
	{
		n->next = head; 
		head = n; 
	}
}

void LinkedList::AddtoEnd(int x)
{
	nodeptr curr, n;
	curr = head;
	n = new node;
	n->data = x;
	if(head == NULL)
	{
		head = n;
		n->next = NULL;  
	}
	else 	
	{
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
		n->next = NULL;
	} 
	count++; 
}

void LinkedList::DeleteNode(int x)
{
	nodeptr curr, prev;
	curr = head;
	while(curr != NULL && curr->data != x)
	{
		prev = curr;
		curr = curr->next;
	}

	if(x == curr->data)
	{
		if(curr == head)
		{
			head = head->next;
			delete curr; 
			count--; 
		}
		else
		{
			prev->next = curr->next;
			delete curr;
			count--;
		}
	}
}


int LinkedList::FirstNode()
{
	return head->data;
}

void LinkedList::PrintNodes()
{
	nodeptr p = head;
	
	while(p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}

int LinkedList::Size()
{
	return count;
}
