#ifndef _PR_H
#define _PR_H
#include<iostream>
#include<string.h>
#include<vector>
class BSTtreeNode;
#pragma warning (disable:4996)
using namespace std;
const int MAXNAME = 30;
class person
{
private:
	char *P_name;
	int P_id;
public:
	friend BSTtreeNode;
	person(char* name, int id);
	~person();
	friend char* reciveName()				;
	const	char *getname()				const;
	void setName(char *name)				;
	void setId(int id)						;
	const int& getId()					const;
	void printPerson()					const;
};


#endif // !_PR_H
