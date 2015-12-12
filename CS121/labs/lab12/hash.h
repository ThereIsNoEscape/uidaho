/*  hash.h
 *
 *  Jonathan Buch
 *  Section #1
 *  Lab #12
 *  April 23rd, 2015
 *  Retrieved from Professor Bolden on April 22nd, 2015
 *
 */
#include <iostream>
#include <cstdlib>

#ifndef HASH_H
#define HASH_H

struct nList     /*  table entry:  */
{
   char *name;          /*  defined name         */
   char *defn;          /*  replacement text     */
   struct nList *next;  /*  next entry in chain  */
};

typedef struct nList *NListPtr;

unsigned Hash( char *s );
void OpenFile( string );
NListPtr Insert( char *name, char *defn );
NListPtr Lookup( char *s );
void PrintHash();

#endif  /*  HASH_H  */
