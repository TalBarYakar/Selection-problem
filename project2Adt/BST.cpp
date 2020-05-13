#include"BST.h"
BSTtreeNode::BSTtreeNode(person* ptr)
{
	HowManyNodesSubTree = 0;
	currPerson = ptr;
	left = nullptr;
	right = nullptr;
	
}
//_________________________________________________________________________________________________________
void BSTtreeNode::deleteRec()
{
	if (left != nullptr)
		left->deleteRec();
	if (right != nullptr)
		right->deleteRec();
	delete this;

}
//___________________________________________________________________________________________________________
BSTtreeNode::~BSTtreeNode()
{
}
//___________________________________________________________________________________________________________
void BSTtreeNode::PrintInorder()			const
{
	if (left != nullptr)
		left->PrintInorder();
	currPerson->printPerson();
	if (right != nullptr)
		right->PrintInorder();
}
//___________________________________________________________________________________________________________
BSTtreeNode* BSTree::find(int key)
{
	BSTtreeNode*ptr = root;
	while (ptr != nullptr)
	{
		int currentId = ptr->currPerson->getId();
		if (currentId == key)
			return ptr;
		else	if (currentId > key)
			ptr = ptr->right;
		 else if (currentId < key)
			ptr = ptr->left;
	}
	return nullptr;
}


BSTree::BSTree()
{
	root = nullptr;
	numberOfComapres = 0;
}
BSTree::~BSTree()
{
	if(root!=nullptr)
	root->deleteRec();
	
}
//___________________________________________________________________________________________________________
void BSTree::insert(person* newPerson)//efficiency: theta(h) while h is the tree height 
{
	int newPersonId = newPerson->getId();
	BSTtreeNode* ptr = root;
	BSTtreeNode* parent=nullptr;
	while (ptr != nullptr)
	{
		numberOfComapres++;// in that case we will compare between the id's
		parent = ptr;
		int currKey = ptr->currPerson->getId();
		if (currKey < newPersonId)
		{
			
			ptr = ptr->right;
		}
		else
		{
			(ptr->HowManyNodesSubTree) ++;
			ptr = ptr->left;
			
		}
		}
	BSTtreeNode* newBSTtreeNode = new BSTtreeNode(newPerson);
	if (parent == nullptr)
	{
		
		root = newBSTtreeNode;
	}
	else if (newPersonId > parent->currPerson->getId())
	{
		
		parent->right = newBSTtreeNode;
	}
	else
	{
		
		parent->left = newBSTtreeNode;
	}
}
//___________________________________________________________________________________________________________
person* BSTree::Delete(person* delPerson)
{
	int comp = 0;
	BSTtreeNode*ptr = root;
	BSTtreeNode* temp=ptr->DeleteRec(delPerson->getId(),&comp);
	numberOfComapres += comp;
	return temp->currPerson;
}
//_________________________________________________________________________________________________________
BSTtreeNode* BSTtreeNode::DeleteRec(int k,int* comp) 
{

		// in case of empty tree
		if (this == nullptr)
			return this;

		// we will find at first the node ask to be deleted
		if (this->currPerson->getId() > k) 
		{
			(*comp)++;
			this->left = left->DeleteRec( k,comp);
			return this;
			
		}
		else if (this->currPerson->getId() < k)
		{
			(*comp)++;
			this->right = right->DeleteRec( k,comp);
			return this;
		}
		//from now we knew that this is the node to delete
		// If one of the children is empty 
		if (this->left == nullptr) {
			BSTtreeNode* temp = this->right;
			delete this;
			return temp;
		}
		else if (this->right == nullptr) {
			BSTtreeNode* temp = this->left;
			delete this;
			return temp;
		}

		// If both children exist 
		else {

			BSTtreeNode* succParent = this->right;

			// Find successor 
			BSTtreeNode*succ = this->right;
			while (succ->left != nullptr) 
			{
				(*comp)++;
				succParent = succ;
				succ = succ->left;
			}

			// Delete successor, always the left side. 
			succParent->left = succ->right;

			// Copy Successor Data to root 
			this->currPerson = succ->currPerson;
				
			this->right = succ->right;

			// Delete Successor and return root 
			delete succ;
			return this;
		}
	}

//____________________________________________________________________________________________________________
void BSTree::printTree()			const
{
	root->PrintInorder();
}
const int BSTree::getNumberOfCompares()					const
{
	return numberOfComapres;
}
//---------------------------the selection function using tree --------------------------------------------------
//in order to make it more efficient i add for every tree node a new field which represent the number of trenodes on his left sub tree

const person * BSTree::BST(person** Parray, int k,int size, int &NumComp)// function worst case effiency theta(n^2) when n is the number of elements in the tree
{																		//function average efficiency theta (nlogn) ""    ""  ""    ""     ""   ""    ""  ""   "".
	
	for (int i = 0; i < size; i++)
	{
		insert(Parray[i]);	//wort case efficiency theta(n^2)   avg case efficiency theta(nlogn).
	}
	BSTtreeNode *ptr = root;// wort case efficiency of the key search theta(n) . 
	while (ptr!=nullptr)
	{
		numberOfComapres++;
		if ((ptr->HowManyNodesSubTree+1) == k)
			return ptr->currPerson;
		else if (ptr->HowManyNodesSubTree + 1 > k)
		{
			ptr = ptr->left;
		}
		else 
		{
			k = k - ptr->HowManyNodesSubTree-1;
			ptr = ptr->right;
		}
	}
	//in case not founded
	return nullptr;

}
