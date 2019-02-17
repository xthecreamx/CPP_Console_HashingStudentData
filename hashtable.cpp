#include"HashTable.h"

template<class type> HashTable<type>::HashTable()
{
	max = 50;
	ptr = new type[max];

	for (int i = 0; i < max; i++)
		ptr[i] = EMPTY_ITEM;

	length = 0;
}
template<class type> HashTable<type>::HashTable(int size)
{
	max = size;
	ptr = new type[max];

	for (int i = 0; i < max; i++)
		ptr[i] = EMPTY_ITEM;

	length = 0;
}
template<class type> HashTable<type>::~HashTable()
{
	delete[] ptr;
}
template<class type> int HashTable<type>::hash(int id)
{
	return (id % max);
}

template<class type> void HashTable<type>::insert(string id,string name)
{
	int location;

	location = hash(atoi(id.c_str()));

		while ((ptr[location] != EMPTY_ITEM))
			location = (location + 1) % max; //Rehash function increases position by 1

	ptr[location] = *(new Student<string>(id, name));
	length++;
}
template<class type> void HashTable<type>::retrieve(string id,type& searched,bool& found)
{
	Student<string> s(id, "");
	int location;
	int startLoc;
	bool moreToSearch = true;

	startLoc = s.hash();
	location = startLoc;

	do
	{
		if (ptr[location] == s || ptr[location] == EMPTY_ITEM)
			moreToSearch = false;
		else
			location = (location + 1) % MAX_ITEMS;
	}while(location != startLoc && moreToSearch);

	found = (ptr[location] == s);

	if(found)
	searched = ptr[location];

}