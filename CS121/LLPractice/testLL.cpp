#include <iostream>
#include "LL.h"
using namespace std;

int main()
{
	LinkedList List1;
	
	List1.AddtoFront( 1 );
	List1.AddtoFront( 2 );
	List1.AddtoFront( 3 );
	List1.AddtoFront( 4 );
	List1.AddtoFront( 5 );
	List1.PrintNodes();
	cout << "\n" << List1.Size() << endl;
	List1.DeleteNode( 3 );
	List1.AddtoEnd( 3 );
	List1.AddtoEnd( 6 );
	List1.PrintNodes();
	cout << "\n" << List1.Size() << endl;
}
