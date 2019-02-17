/*
Name: Davis Kieu
Date:12/2/2018
Description: A console program revolving around hashing. Enables the user to find a student by ID & retrieve information relative to the searched student.

*/

#include"HashTable.h"
#include<fstream>
#include<sstream>

using namespace std;

const string FILE_NAME = "Students.txt";

typedef Student<string> student;
typedef HashTable<student> studentList;

char selection();
void loadValues(studentList&,string);
ostream& operator<<(ostream&, const student&);
int main()
{
	studentList hashList(MAX_ITEMS);
	loadValues(hashList,FILE_NAME);

	do
	{
		switch (selection())
		{
		case 'a': {}
		case 'A':
		{
			string target;
			bool found;
			student searched;

			cout << "Enter id # to search : ";
			cin >> target;
			cin.ignore();

		    hashList.retrieve(target,searched,found);

			if (found)
				cout << searched;
			else
				cout << "Student with ID#" << target << " was not found!" << endl;
			break;
		}
		case 'b': {}
		case 'B':
		{
			exit(0);
		}
		default: cout << "Invalid choice.\n";
		}
	} while (1);
	
}
char selection()
{
	char choice;

	cout << "-----MENU-----\n"
		<< "A.Find a student by ID.\n"
		<< "B.Exit\n";

	cin.get(choice);
	cin.ignore();

	return choice;
}
void loadValues(studentList& list,string fileName)
{
	string line;
	ifstream input(fileName);

	if (input.is_open())
	{
		while (!input.eof())
		{
			string name, id , portion;

			getline(input, line);
			stringstream ss(line);
			
			ss >> id;
			
			while (!ss.eof())
			{
				ss >> portion;
				name += portion + (ss.eof() ? "" : " ");	
			}

			list.insert(id, name);
		}

		input.close();
	}

}
ostream& operator<<(ostream& out, const student& item)
{
	out << "ID : " << *(item.id) << " , NAME: " << *(item.name) << endl;
	return out;
}
