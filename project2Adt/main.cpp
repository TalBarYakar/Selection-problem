#include"BST.h"
#include"heap.h"
#include<ctime>
//-------------------------------------efficienccy------------------------------------------------------------------
//___________________________________________________________________________________________________________________
//algorithem					|			efficiency worst case			|		effiency average case			|
//__________________________________________________________________________________________________________________|
//BST							|			theta(n^2)						|		theta(nlogn)					|
//__________________________________________________________________________________________________________________|
//Randselection					|			theta(n)						|		theta(n^2)						|
//__________________________________________________________________________________________________________________|
//heap							|			theta(klogn)					|		theta(nlogn)					|
//__________________________________________________________________________________________________________________|
using namespace std;
int partition(person **Parray, int left, int right,int&numcomp);
const person * RandSelection(person** arrayOfPersons,int left,int right, int k, int &NumComp);
void checkValidityOdId(int& id, person** Parray, int size);
char *reciveName();
//----------------------------------------------main-------------------------------------------------
int main()
{
	int selectionKey;
	int heapcomp = 0;
	const person *temp=nullptr;
	BSTree tree;
	srand(time(NULL));
	int tempId;
	int numberOfpersons;
	cin >> numberOfpersons;
	person**parray = new person*[numberOfpersons];
	for (int i = 0; i < numberOfpersons; i++)
	{
		cin >> tempId;// we can assume the recive input type is char
		checkValidityOdId(tempId, parray, i); //if ther is no id as the input one in the array
		
			cin.ignore();
			char* currName = reciveName();

			person* newPerson = new person(currName, tempId);
			parray[i] = newPerson;
	}
	cin >> selectionKey;
	if (selectionKey > numberOfpersons || selectionKey<1)
{
		cout << "invalid input " << endl;
		exit(1);
}

//------------treee selection soloution without chainging the array-------------------------
		
	int numcompere = 0;
		temp = tree.BST(parray, selectionKey, numberOfpersons, numcompere);
	


	//--------------------------Random selection------------------------------------------
	//in oeder not making any changes in the original array of person we will copy the array to another one
		int randNumComp = 0;
			person** tempArray = new person*[numberOfpersons];
		for (int i = 0; i < numberOfpersons; i++)
			tempArray[i] = parray[i];
		//the rand selection functoin
		const person* randselection = RandSelection(tempArray, 0, numberOfpersons - 1, selectionKey, randNumComp);
		delete[] tempArray;

	//--------------------------selection be heap-----------------------------------------
		// we have no other use in the array after that function we can use it as his
		heap b(parray, numberOfpersons);
		const person* heapSel = b.selectHeap(parray, numberOfpersons, selectionKey, heapcomp);



		//-------------------------------result-prints--------------------------------
		if (heapSel == randselection && randselection == temp)
		{
			heapSel->printPerson();
			cout << "RandSelection:" << randNumComp << endl;
			cout << "selectHeap:" << b.getCmpNum() << endl;
			cout << "BST :" << tree.getNumberOfCompares() << endl;
		}
		//----------------delete the array-----------------------------
		for (int i = 0; i < numberOfpersons; i++)
			delete parray[i];
		delete[] parray;
		

}


//_______________________________________________________________________________________________________________________________________________

const person * RandSelection(person** arrayOfPersons, int left,int right, int k, int &NumComp)//worst case efficiency theta(n^2), average(nlogn).
{
	int pivot,currPiv;
	pivot = partition(arrayOfPersons,left,right ,NumComp);//worst case efficiency theta(n)
	currPiv = pivot - left + 1;
	if(currPiv==k)
	{
		NumComp++;
		return arrayOfPersons[pivot];
	}
	else if(currPiv>k)
	{
		NumComp++;
	return	RandSelection(arrayOfPersons, left, pivot - 1, k, NumComp);
	}
	else
	{
		NumComp++;
		return RandSelection(arrayOfPersons, pivot + 1, right, k - currPiv, NumComp);
	}
	}
//________________________________________________________________________________________
int partition(person **Parray, int left, int right,int& numComp)// theta(n)
{
int x=	rand() % (right - left+1) + left;
person*temp=nullptr;
temp = Parray[x];
Parray[x] = Parray[left];
Parray[left] = temp;
int lIndex = left + 1;
int PivKey = Parray[left]->getId();
while (lIndex < right)
	{
	if (PivKey<Parray[lIndex]->getId() && PivKey>Parray[right]->getId())
	{
		numComp += 2;
		temp = Parray[lIndex];
		Parray[lIndex] = Parray[right];
		Parray[right] = temp;
	}
	else
	{
		if (PivKey > Parray[lIndex]->getId())
		{
			numComp++;
			lIndex++;
		}
		if (PivKey < Parray[right]->getId())
		{
			numComp++;
			right--;
		}
	}
	
	}
if (lIndex > right)
{
--lIndex;
}
 if (Parray[(lIndex)]->getId() > PivKey)
lIndex--;
numComp++;
temp = Parray[lIndex];
Parray[lIndex] = Parray[left];
Parray[left] = temp;
return lIndex;
}
//______________________________________________________________________________________
void checkValidityOdId(int& id,person** Parray,int size)
{
	if (id < 0)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	for (int i = 0; i < size; i++)
	{
		if (id == Parray[i]->getId())
		{
			cout << "invalid input" << endl;
			exit(1);
		}
	}
	
}









