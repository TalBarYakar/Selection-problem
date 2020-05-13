#include"heap.h"
heap::heap(int max)
{
	MaxSize = max;
	arrayOfpersons = new person*[max];
	allocated = true;
}
heap::heap(person**arrayofPerson, int size)
{
	comparesNum = 0;
	arrayOfpersons = arrayofPerson;
	heapSize = size;
	for (int i = ((heapSize / 2) - 1); i >= 0; i--)//making the heap by floyd algorithem,effiency theta(n)
		fixheap(i);
}
heap::~heap()
{
	if (allocated == true)
		delete[]arrayOfpersons;// we dont want to delete the persons, in that class
}
int heap::right(int parent)
{
	return(parent * 2 + 2);
}
int heap::left(int parent)
{
	return(parent * 2 + 1);
}
int heap::parentIndex(int kid)
{
	return ((kid - 1) / 2);
}
void heap::insert(person *ptr)
{
	int key = ptr->getId();
	if (heapSize == MaxSize)
	{
		cout << "heap is full" << endl;
		exit(1);
	}
	int currentSize = heapSize;
	heapSize++;
	while (currentSize > 0 && arrayOfpersons[parentIndex(currentSize)]->getId() > key)
	{
		comparesNum++;
		arrayOfpersons[currentSize] = arrayOfpersons[parentIndex(currentSize)];
		currentSize = parentIndex(currentSize);
	}
	arrayOfpersons[currentSize] = ptr;
}
void heap::fixheap(int index)
{  
	person*temp;
	
	int min=0;
	while (index < heapSize )
	{
		int leftIndex = left(index);
		int rightIndex = right(index);
		if (leftIndex < heapSize)
		{
			
			if (arrayOfpersons[index]->getId() < arrayOfpersons[leftIndex]->getId())
			{
				comparesNum++;
				min = index;
			}
			else
			{
				min = leftIndex;
				comparesNum++;
			}
			}
		if (rightIndex < heapSize)
		{
			
			if (arrayOfpersons[min]->getId() > arrayOfpersons[rightIndex]->getId() && rightIndex < heapSize)
			{
				comparesNum++;
				min = rightIndex;
			}
			}
	
			if (min != index)
			{
				temp = arrayOfpersons[index];
				arrayOfpersons[index] = arrayOfpersons[min];
				arrayOfpersons[min] = temp;
				index = min;
			}
			else break;
		
	}

}
//_______________________________________________________________________________________________
void heap::printHeap()
{
	for (int i = 0; i < heapSize; i++)
		arrayOfpersons[i]->printPerson();
}
person* heap::deleteMin()
{
	
	person*temp = arrayOfpersons[0];
	arrayOfpersons[0] = arrayOfpersons[heapSize - 1];
	arrayOfpersons[heapSize - 1] = temp;
	heapSize--;
	fixheap(0);
	return temp;
}
const int heap::getCmpNum()				const
{
	return comparesNum;
}
person * heap::minHeap()
{
	return arrayOfpersons[0];
}
const person* heap::selectHeap(person**Parray, int size, int k, int &NumComp)
{
	
	for (int i = 0; i < (k-1); i++)//worst case effiency theta(klogn) sum of worst case efficiency theta(nlogn) when we search the biggest element;
	{								//avg case efficiency theta(n+ klogn) = theta(klogn) when k is the key we search.
	person*curr=deleteMin();
	}

	return minHeap();
}