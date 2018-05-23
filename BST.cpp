/*Title: BST.cpp
Abstract: BST functions
Author: Joseph Cortez
ID: 002885414
Date: 2/20/2018
*/

#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
	: myRoot(0)
{}

bool BST::empty() const
{
	return myRoot == 0;
}


bool BST::search(const int & item) const
{
	BinNode * locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	return found;
}


void BST::insert(const int & item)
{
	BinNode * locptr = myRoot;   // search pointer
	BinNode * parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new BinNode(item);
		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->left = locptr;
		else                           // insert to right of parent
			parent->right = locptr;
	}
	else
		cout << "Item already in the tree\n";
}

// Functions necessary for recursive implementation of creating balance BST
/**void BST::SelectionSort(int A[], int n)
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

}*/

/**void BST::balancedBST(int arr[], int n)
{
	SelectionSort(arr, n);
	balancedBSTAux(arr, 0, n-1, myRoot);
}

void BST::balancedBSTAux(const int arr[], int start, int end, BinNodePointer & subtreeRoot)
{
	if (start > end)
	{
		return;
	}
	int mid = start + (end - start) / 2;

	subtreeRoot = new BinNode(arr[mid]);
	balancedBSTAux(arr, start, mid - 1, subtreeRoot->left);
	balancedBSTAux(arr, mid + 1, end, subtreeRoot->right);
}*/

//--- Definition of inOrder()
void BST::inOrder(ostream & out) const
{
	inOrderAux(out, myRoot);
}

//--- Definition of inOrderAux()
void BST::inOrderAux(ostream & out, BinNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		inOrderAux(out, subtreeRoot->left);			// left opeartion
		out << subtreeRoot->data << " ";			// root operation
		inOrderAux(out, subtreeRoot->right);		// right operation
	}
}

//--- Definition of leafHeights()
void BST::leafHeights(ostream & out) const
{
	leafHeightsAux(out, myRoot, -1);
}

//--- Definition of leafHeightsAux()
void BST::leafHeightsAux(ostream & out, BinNodePointer subtreeRoot, int height) const
{
	height++;
	// if node is null, return
	if (!subtreeRoot)
		return;

	// if node is leaf node, print its data    
	if (!subtreeRoot->left && !subtreeRoot->right)
	{
		cout << "Height of leaf \"" << subtreeRoot->data << "\": " << height << endl;
		return;
	}

	// if left child exists, check for leaf 
	// recursively
	if (subtreeRoot->left)
		leafHeightsAux(out, subtreeRoot->left, height);

	// if right child exists, check for leaf 
	// recursively
		if (subtreeRoot->right)
		leafHeightsAux(out, subtreeRoot->right, height);
}

//--- Definition of NewSearch()
int BST::NewSearch(const int & item) const
{
	return NewSearchAux(item, myRoot);
}

//--- Definition of NewSearchAux
int BST::NewSearchAux(const int & item, BinNodePointer subtreeRoot) const
{
	static int foundValue = 0;
	if (subtreeRoot == NULL)
		return foundValue;
	if (subtreeRoot->data > item)
	{
		foundValue = subtreeRoot->data;
		NewSearchAux(item, subtreeRoot->left);
	}
	else if (subtreeRoot->data < item)
		NewSearchAux(item, subtreeRoot->right);
	else if (subtreeRoot->data == item)
		return item;
	else return foundValue;
	
}