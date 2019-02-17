#ifndef STUDENT_DEFINED
#define STUDENT_DEFINED

#include<string>
#include<iostream>

using namespace std;

const int MAX_ITEMS = 100;

template<class type> class Student
{
private:
	type * id;
	type * name;
public:
	Student() { id = 0; name = 0; }
	Student(type id, type name){ this->id = new type(id); this->name = new type(name);}
	~Student() { delete id; delete name; }
	friend ostream& operator<<(ostream&, const Student<type>&);
};

template<> class Student<string>
{
private:
	string * id;
	string * name;
public:
	Student() { id = 0; name = 0; }
	Student(string id, string name){this->id = new string(id); this->name = new string(name);}
	~Student() { delete id; delete name; }
	int hash() { return (atoi(id->c_str()) % MAX_ITEMS); }
	bool operator!=(const Student<string>& other) { return (atoi(id->c_str()) != (atoi((other.id)->c_str()))); }
	bool operator==(const Student<string>& other) { return (atoi(id->c_str()) == (atoi((other.id)->c_str()))); }
	bool operator<(const Student<string>& other) { return (atoi(id->c_str()) < (atoi((other.id)->c_str()))); }
	bool operator>(const Student<string>& other) { return (atoi(id->c_str()) > (atoi((other.id)->c_str()))); }
	bool operator<=(const Student<string>& other) { return (atoi(id->c_str()) <= (atoi((other.id)->c_str()))); }
	bool operator>=(const Student<string>& other) { return (atoi(id->c_str()) >= (atoi((other.id)->c_str()))); }
	friend ostream& operator<<(ostream&, const Student<string>&);
};
#endif
