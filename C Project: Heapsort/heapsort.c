#include "stdio.h"
#include "stdlib.h"



/*******************
In this project, we will implement the HeapSort
algorithm to sort an array of 200,000 integers

Function prototypes listed below.
**********************/

//heapSort takes arrayToSort, an int pointer to an array that we need to sort,
//and n, the size of the array, and puts the elements
//of arrayToSort into non-decreasing order using a heap to repeatedly
//find the largest element that we have not yet placed into the 
//"sorted portion" of arrayToSort.
void heapSort(int *arrayToSort, int n);


//Given index i, return the index of the left child of i.
int leftChild(int i);


//Given index i, return the index of the right child of i.
int rightChild(int i);


//Given index i, return the index of the parent of i.
int parent(int i);


//Given an array of integers, makeHeap arranges the elements 
//int a valid heap configuration where each number is 
//greater than both of its children.
void makeHeap(int *heap, int n);


//heapifyUp is used to restore the heap to a valid configuration
//after inserting a new value at the end of the heap.  i
//is the index of the new value.  While it is larger than
//its parent, swap the value with the parent (or stop when
//it becomes the root and does not have a parent).
void heapifyUp(int *heap, int i);



//heapifyDown is used to restore the heap to a valid configuration
//after removing the largest value at the top of the heap.  After
//removing the maximum element at the top of the heap, we would
//have swapped a value from the bottom of the heap into the top position.
//This value may be smaller than some of its children.  If so, 
//we need to swap this value with the larger of its two children.
//Stop when it's larger than all of its children (or when it no longer
//has any children).
void heapifyDown(int *heap, int n, int i);


int main()
{
    
    //Creating an array of size 200,000 and filling it
    //with random values between 0 and 999,999.
    int n = 200000;
    int *arrayToSort = (int*)malloc(n*sizeof(int));
    int i;
    for(i=0; i<n; i++){
        
        arrayToSort[i] = rand() % 1000000;
    
    }
	
	
	heapSort(arrayToSort,n);
    
    
    
    for(i=0; i<n; i++){
        
        printf("%d \n",arrayToSort[i]);
    
    }

	free(arrayToSort);
		
	return 0;
}


void heapSort(int *arrayToSort, int n)
{
	int i;

	for(i = n / 2 - 1; i >= 0; i--)
	{
		heapifyDown(arrayToSort, n, i);
	}

	//swap current root with i, call heapifyDown
	for(i = n - 1; i > 0; i--)
	{
		int temp;
		temp = arrayToSort[0];
		arrayToSort[0] = arrayToSort[i];
		arrayToSort[i] = temp;

		heapifyDown(arrayToSort, i, 0);
	}
}




int leftChild(int i)
{	
	return (i*2 + 1);
}




int rightChild(int i)
{	
	return (i*2 + 2);
}




int parent(int i)
{
	return ((i - 1) / 2);
}




void makeHeap(int *heap, int n)
{
	//get index of last non-leaf node
	int startIdx;
	startIdx = (n / 2) - 1;

	/*perform reverse level order traversal
	from the last non-leaf node and heapifyDown each node*/
	int i;
	for(i = startIdx; i >= 0; i--)
	{
		heapifyDown(heap, n, i);
	}    
    
}




//while the newly inserted value is greater than the parent value, swap
void heapifyUp(int *heap, int i)
{
	if(i == 0)
	{
		return;
	}    

	int parentIndex;
	parentIndex = parent(i);

	//if new node is greater than its parent, swap and
	//recursively call function
	if(heap[parentIndex] > heap[i])
	{
		int temp;
		temp = heap[parentIndex];
		heap[parentIndex] = heap[i];
		heap[i] = temp;

		heapifyUp(heap, parentIndex);
				
	}

	else
	{
		return;
	}
    
}



//when the top element of a heap is removed, we place a bottom element on top
//and then swap it with its child nodes until the heap is in the correct order
void heapifyDown(int *heap, int n, int i)
{
	if(i >= n)
	{
		return;
	}        

	int leftChildIndex = leftChild(i);
	int rightChildIndex = rightChild(i);
	int selectedChildIndex = -1;

	if((leftChildIndex >= n) && (rightChildIndex >= n))
	{
		return;
	}

	if((leftChildIndex < n) && (rightChildIndex >= n))
	{
		selectedChildIndex = leftChildIndex;
	}

	if((leftChildIndex < n) && (rightChildIndex < n))
	{
		if(heap[leftChildIndex] >= heap[rightChildIndex])
		{
			selectedChildIndex = leftChildIndex;
		}

		else
		{
			selectedChildIndex = rightChildIndex;
		}
	}

	//swap and recursively call heapifyDown
	if(heap[i] < heap[selectedChildIndex])
	{
		int temp;
		temp = heap[i];
		heap[i] = heap[selectedChildIndex];
		heap[selectedChildIndex] = temp;

		heapifyDown(heap, n, selectedChildIndex);
	}

	else
	{
		return;
	}
}
