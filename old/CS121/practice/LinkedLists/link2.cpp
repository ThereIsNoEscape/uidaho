#include "link2.h"
using namespace std;

void LL::AddtoFront( int x )
{
	nodeptr p;
	p = new node;
	p->data = x;
	if( head == NULL )
	{
		p->next = NULL;
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
	count++;
}

void LL::AddtoEnd( int x )
{
	nodeptr curr, p;
	curr = head;
	p = new node;
	p->data = x;
	p->next = NULL;
	count++;
	if( head == NULL )
	{
		head = p;
	}
	else
	{
		while( curr->next != NULL )
		{
			curr = curr->next;
		}
		curr->next = p;
	}
}

void LL::AddSorted( int x )
{
	nodeptr curr, prev, p;
	curr = head;
	p = new node;
	p->data = x;
	p->next = NULL;
	count++;
	if( head == NULL)
	{
		head = p;
	}
	else
	{
		while( curr != NULL && x > curr->data )
		{
			prev = curr;
			curr = curr->next;
		}
		if( curr == head )
		{
			p->next = head;
			head = p;
		}
		else
		{
			prev->next = p;
			p->next = curr;
		}
	}
}
	

void LL::Dequeue()
{
	nodeptr curr;
	if( head != NULL )
	{
		curr = head;
		head = curr->next;
		curr->next = NULL;
		delete curr;
	}
	count--;	
}

int LL::IsInList( int x )
{
	nodeptr curr;
	curr = head;
	if( head == NULL )
	{
		return 0;
	}
	else
	{
		while( curr != NULL && x != curr->data )
		{
			curr = curr->next;
		}
		if( curr->data == x )
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int LL::FirstNode()
{
	if( head != NULL )
		return head->data;
}

int LL::Size()
{
	return count;
}

void LL::PrintNodes()
{
	nodeptr curr;
	curr = head;
	while( curr != NULL )
	{
		cout << curr->data;
		curr = curr->next;
	}
	cout << endl;
}
