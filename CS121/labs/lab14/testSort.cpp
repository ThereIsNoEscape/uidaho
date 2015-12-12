/*	Jonathan Buch
	Section #1
	Lab #14
	May 7th, 2015
	
	testSort.cpp
*/


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	srand(time(NULL));
	int nA1 = 100;
	int nA2 = 1000;
	int nA3 = 10000;
	int sortHL100[nA1];
	int sortHL1000[nA2];
	int sortHL10000[nA3];
	int rand100[nA1];
	int rand1000[nA2];
	int rand10000[nA3];
	int sortLH100[nA1];
	int sortLH1000[nA2];
	int sortLH10000[nA3];
	
	ofstream datafile;

	datafile.open( "rand100.txt" );
	for( int i = 0; i < nA1; i++ )
	{
		rand100[i] = rand() % 1000;
		datafile << rand100[i] << "\n";
	}
	datafile.close();	

	datafile.open( "rand1000.txt" );
	for( int i = 0; i < nA2; i++ )
	{
		rand1000[i] = rand() % 10000;
		datafile << rand1000[i] << "\n";
	}
	datafile.close();	

	datafile.open( "rand10000.txt" );
	for( int i = 0; i < nA3; i++ )
	{
		rand10000[i] = rand() % 100000;
		datafile << rand10000[i] << "\n";
	}
	datafile.close();	

	datafile.open( "sortHL100.txt" );
	for( int i = 0; i < nA1; i++ )
	{
		sortHL100[i] = nA1 - i; 
		datafile << sortHL100[i] << "\n";
	}
	datafile.close();	

	datafile.open( "sortHL1000.txt" );
	for( int i = 0; i < nA2; i++ )
	{
		sortHL1000[i] = nA2 - i; 
		datafile << sortHL1000[i] << "\n";
	}
	datafile.close();	

	datafile.open( "sortHL10000.txt" );
	for( int i = 0; i < nA3; i++ )
	{
		sortHL10000[i] = nA3 - i; 
		datafile << sortHL10000[i] << "\n";
	}
	datafile.close();	

	datafile.open( "sortLH100.txt" );
	for( int i = 0; i < nA1; i++ )
	{
		sortLH100[i] = i;
		datafile << sortLH100[i] << "\n";
	}
	datafile.close();	

	datafile.open( "sortLH1000.txt" );
	for( int i = 0; i < nA2; i++ )
	{
		sortLH1000[i] = i;
		datafile << sortLH1000[i] << "\n";
	}
	datafile.close();	

	datafile.open( "sortLH10000.txt" );
	for( int i = 0; i < nA3; i++ )
	{
		sortLH10000[i] = i;
		datafile << sortLH10000[i] << "\n";
	}
	datafile.close();	
}
