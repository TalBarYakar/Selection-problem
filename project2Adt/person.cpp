#include"person.h"

using namespace std;
person::person(char* name, int id)
{
	P_name = name;
	P_id = id;
}
person::~person()
{
	delete[] P_name;
}
char const  *person::getname()							const
{
	return P_name;
}
char *reciveName()
{
	
	char* name = new char[MAXNAME];
	cin.getline(name, MAXNAME);
	char *newNAme = new char[strlen(name) + 1];	
	strcpy(newNAme, name);
	delete[] name;
	return newNAme;
}
void person::setName( char*name)
{
	P_name = name;
}
void person::setId(int id)
{
	P_id = id;
}
const int& person::getId()								const
{
	return P_id;
}
void person::printPerson()					const
{
	cout << P_id <<"  "<<P_name<< endl;
}