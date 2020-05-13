#ifndef _BST_H
#define _BST_H
#include"person.h"

class BSTree
{
private:
	int numberOfleaves;
	BSTtreeNode *root;
	int numberOfComapres;

public:
	friend BSTtreeNode;
	BSTree();
	~BSTree();
	BSTtreeNode* find(int key );
	void insert(person* newPerson);
	person* Delete(person* delPerson);
	const int getNumberOfCompares()					const;
	void printTree()								const;
	const person* BST(person** parray, int k,int size, int &NumComp);
	
};

class BSTtreeNode 
{
private:
	int HowManyNodesSubTree;
	person* currPerson;
	BSTtreeNode*left, *right;
public:
	BSTtreeNode* DeleteRec(int k,int *comp);
	void deleteRec();
	friend BSTree;
	BSTtreeNode(person* ptr);
	~BSTtreeNode();
	void PrintInorder()			const;
	void MakeMinArrayFromTree(person** arr, int& i, int& key, int &numcomp);
};
 
#endif // !_BST_H
