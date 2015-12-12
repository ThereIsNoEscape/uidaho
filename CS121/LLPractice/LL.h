/*	LL.h
 *	Jonathan Buch
 *	
 *
 *
 */

class LinkedList
{
	private:
		struct node
		{
			int data;
			node * next;
		};
		typedef node * nodeptr;

		nodeptr head;
		
		int count;
	public:					// Constructor, Destructor, Functions
		LinkedList()
		{
			head = NULL;
			count = 0;
		}
		~LinkedList()
		{
			nodeptr p = head, n;
			
			while(p != NULL)
			{
				n = p;
				p = p->next;
				delete n;
			}
		}
		void AddtoFront(int x);
		void AddtoEnd(int x);
		void DeleteNode(int x);
		int FirstNode();
		void PrintNodes();
		int Size();
};
