#ifndef  _HE_H
#define _HE_H
#include"person.h"
class heap
{
private:
	person** arrayOfpersons;
	int MaxSize;
	int heapSize;
	bool allocated;
	int comparesNum;
	static int left(int key);
	static int right(int key);
	static int parentIndex(int key);
	void fixheap(int key);
public:
	heap(int max);
	heap(person**arrayofPerson, int size);
	~heap();
	const int getCmpNum()				const;
	person * minHeap();
	person *deleteMin();
	void insert(person* ptr);
	void printHeap();
	const person* selectHeap(person**Parray, int size, int k, int &NumComp);
};
#endif // ! _HE_H

