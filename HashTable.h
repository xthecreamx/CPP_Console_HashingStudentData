#ifndef HASH_TABLE_DEFINED
#define HASH_TABLE_DEFINED

#include"Student.h"

using namespace std;

const Student<string> EMPTY_ITEM("-1","-1");

template<class type> class HashTable
{
private:
	type*ptr;
	int length;
	int max;
	int hash(int);
public:
	HashTable();
	HashTable(int);
	~HashTable();
	void insert(string, string);
	void retrieve(string,type&,bool&);
};

#include"hashtable.cpp"

#endif
