/*  testLink.cpp
 */

#include <iostream>

using namespace std;

#include "link2.h"


int main()
{
    LL list1 ;  // Dynamic:  = new LinkedList;

      //  add some initial nodes
    list1.AddtoFront( 3 );
    list1.AddtoFront( 5 );
    list1.AddSorted( 4 );
    cout << "Initial contents of list1:" << endl;
    list1.PrintNodes();

    cout << "Is 3 in the list? ";
    if( list1.IsInList( 3 ) )
        cout << " yes" << endl;
    else
        cout << " no" << endl;

      //  add a few more nodes
    list1.AddtoEnd( 1 );

    cout << "Contents of list1 after adding:" << endl;
    list1.PrintNodes();

      //  delete a few nodes
    list1.Dequeue();

    cout << "Contents of list1 after deleting:" << endl;
    list1.PrintNodes();
    cout << "First: ";
    cout << list1.FirstNode() << endl;
    cout << "List Size: ";
    cout << list1.Size() << endl;

    return 0;
}
