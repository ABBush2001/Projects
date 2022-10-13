#include "HashTable.h"

/******
 * In this file, provide all of the definitions of the hash table functions as described in HashTable.h.
 *
 * ****/

//malloc hashtable, malloc array to size n, intialize each element to -2, return h
HashTable newHashTable(int n)
{
	int i;

	HashTable h = (HashTable)malloc(sizeof(HashTableImp));
	
	h->n = n;

	h->hashTable = (HashTableEntry*)malloc(n * sizeof(HashTableEntry));

	for(i = 0; i < n; i++)
	{
		(h->hashTable[i]).chainIndex = -2;
	}

	return h;


}

//convert string to int and return
int stringToInt(char *stringToConvert)
{
	int x = 0;
	int i = 0;

	while(stringToConvert[i] != '\0')
	{
		x = x + stringToConvert[i];
	
		i++;
	}


	return abs(x);
}

//return key mod n
int divisionMethod(int key, int n)
{
	return (key % n);	
}

//squares the key and returns the middle values
int midsquareMethod(int key, int n)
{
	int x;
	x = key * key;

	x = x / 10000;
	x = x % n;

	return x;
}

//insert an element e into the hashtable at a unique index
void put(HashTable h, Element e)
{
	int index = midsquareMethod(stringToInt(e.teamName), h->n);

	if(h->hashTable[index].chainIndex == -2)
	{
		h->hashTable[index].key = e;
		h->hashTable[index].chainIndex = -1;
	}

	//if we have a collision
	else
	{
		int k = 7;
		int endOfChain = index;

		while(h->hashTable[endOfChain].chainIndex != -1)
		{
			endOfChain = h->hashTable[endOfChain].chainIndex;
		}

		int myNewIndex = (endOfChain + k) % h->n;

		while(h->hashTable[myNewIndex].chainIndex != -2)
		{
			myNewIndex = (myNewIndex + k) % h->n;
		}

		h->hashTable[endOfChain].chainIndex = myNewIndex;
		h->hashTable[myNewIndex].key = e;
		h->hashTable[myNewIndex].chainIndex = -1;
	}
}

//traverse hashtable for teamname, assign e to the element containing teamname. If element doesn't exist return 0 for false, otherwise 1 for true
Element* get(HashTable h, char *teamname)
{
	int index = midsquareMethod(stringToInt(teamname), h->n);

	if(h->hashTable[index].chainIndex == -2)
	{
		return NULL;
	}

	while( strcmp(teamname, h->hashTable[index].key.teamName) != 0 && h->hashTable[index].chainIndex != -1 )
	{
		index = h->hashTable[index].chainIndex;
	}


	if( strcmp(teamname, h->hashTable[index].key.teamName) == 0 )
	{
		return &(h->hashTable[index].key);
	}

	else
	{
		return NULL;
	}
}

//frees hashtable pointer and h itself
void freeHashTable(HashTable h)
{
	free(h->hashTable);
	free(h);
}
