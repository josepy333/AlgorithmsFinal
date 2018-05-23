/*Title: BST_tester.cpp
Abstract: Driver program for BST functions
Author: Joseph Cortez
ID: 002885414
Date: 2/20/2018
*/
#include <iostream>
using namespace std;

#include "BST.h"

// Function to sort array
void SelectionSort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[iMin])
				iMin = j;
		}
		int temp = A[i];
		A[i] = A[iMin];
		A[iMin] = temp;
	}

}

// Function to resort array to mimic a balance tree for insertion
void ArrayBalance(int A[], int start, int end, int &count, int temp[])
{
	count++;
	if (start > end)
		return;
	int mid = start + (end - start) / 2;	
	temp[count] = A[mid];
	ArrayBalance(A, start, mid - 1, count, temp);
	count--;
	ArrayBalance(A, mid + 1, end, count, temp);
}

int main()
{
	BST intBST;
	//int arr[] = { 3, 2, 1, 4, 6, 5 };
	int arr[] = {3, 33, 7, 21, 9, 15, 55, 32, 24};				// Test array
	int const arraySize = sizeof(arr) / sizeof(arr[0]);
	int temp[arraySize];
	cout << "Original input array: " << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
	SelectionSort(arr, arraySize);
	int start = 0;
	int const end = arraySize - 1;
	int count = -1;

	// Part1: Algorithm for balanced binary search tree insertion
	ArrayBalance(arr, start, end, count, temp);

	// Insertion of new array to get balance binary search tree
	for (int i = 0; i < arraySize; i++)
	{
		intBST.insert(temp[i]);
	}

	cout << "\nBST " << (intBST.empty() ? "is" : "is not") << " empty\n\n";

	// Part2: InOrder traversal of balanced BST
	cout << "In order traversal of balanced binary search tree:" << endl;
	intBST.inOrder(cout);
	cout << endl << endl;

	// Part 3: Calculate and print out the height of all leaf nodes
	cout << "Calculate and print out the height of all leaf nodes:\n";
	intBST.leafHeights(cout);
	cout << endl;

	// Part 4:  NewSearch that, for a given number N, finds the node in the BST
	//that has the value equal to or the smallest number greater than N.
	cout << "Implementation of NewSearch() function: \n";
	cout << "Enter a number to find it or the next largest number in the tree:";
	int find;
	cin >> find;
	cout << endl;
	int found = intBST.NewSearch(find);
	if (found == 0)
	{
		cout << "The number is not in the binary search tree," << endl;
		cout << "and there is no number greater than it in the tree." << endl << endl;
	}
	else if (found == find)
		cout << found << " is in the binary search tree!" << endl << endl;
	else
		cout << found << " is the next largest number in the binary search tree!" << endl<<endl;
}