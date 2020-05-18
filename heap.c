/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author: 
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	//TODO - BuildHeap on the list
	buildHeap(A, n);
	
	//TODO - while n > 0:
	while(n > 0){
		//TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		swap(&A[n-1], &A[0]);
		//TODO - A[n-1] now sorted in place!
		//TODO - So decrement n
		n--;
		//TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
		heapify(A, 0, n);
	}
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	//TODO - heapify() every element from A[n/2] to A[0]
	int i = n/2;
	while(i >= 0) {
		heapify(A, i, n);
		i--;
	}
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */
void heapify(struct Employee *A, int i, int n)
{
	//TODO - get index of left child of element i
	int l = 2*(i+1)-1;
	//TODO - get index of right child of element i
	int r = 2*(i+1);
	if(i < n && (l < n || r < n)){
	//TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
		int smaller = l;

		if(r < n && A[l].salary > A[r].salary){
			smaller = r;
		}

	//TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
		if(A[i].salary > A[smaller].salary){
			swap(&A[i], &A[smaller]);
			heapify(A, smaller, n);
		}
	//TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
	
		
	}
}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{
	return &A[0];
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	struct Employee tmp = *e1;
	*e1 = *e2;
	*e2 = tmp; 
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	for(int i = 0; i < n-1; i++) {
		printf("[ name= %s sal=%d], ", A[i].name, A[i].salary);
	}
	printf("[ name= %s sal=%d]\n ", A[n-1].name, A[n-1].salary);
}
