#include <iostream>

using namespace std;

class LL
{
	private:
		struct node
		{
			int data;
			node * next;
		};
		typedef node * nodeptr;
		int count;
		nodeptr head;
	public:
		LL()
		{
			head = NULL;
			count = 0;
		}
		~LL()
		{
			nodeptr curr, prev;
			curr = head;
			while( curr != NULL )
			{
				prev = curr;
				curr = curr->next;
				delete prev;
			}
		}
		void AddtoFront(int x);
		void AddtoEnd(int x);
		void AddSorted(int x);
		void Dequeue();
		int IsInList(int x);
		int FirstNode();
		int Size();
		void PrintNodes();
};
