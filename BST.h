/*Title: BST.h
Abstract: Header file for BST.cpp
Author: Joseph Cortez
ID: 002885414
Date: 2/20/2018
*/

#include <iostream>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
public:
	/***** Function Members *****/
	BST();
	bool empty() const;
	bool search(const int & item) const;
	void insert(const int & item);
	//void SelectionSort(int A[], int n);
	//void balancedBST(int arr[], int n);
	void inOrder(ostream & out) const;
	void leafHeights(ostream & out) const;
	int NewSearch(const int & item) const;

private:
	/***** Node class *****/
	class BinNode
	{
	public:
		int data;
		BinNode * left;
		BinNode * right;

		// BinNode constructors
		// Default -- data part is default int value; both links are null.
		BinNode()
			: left(0), right(0)
		{}

		// Explicit Value -- data part contains item; both links are null.
		BinNode(int item)
			: data(item), left(0), right(0)
		{}

	};// end of class BinNode declaration

	typedef BinNode * BinNodePointer;
	  /***** Data Members *****/
	BinNodePointer myRoot;

	/**** Priivate function members****/
	void inOrderAux(ostream & out, BST::BinNodePointer subtreeRoot) const;
	//void balancedBSTAux(const int arr[], int start, int end, BinNodePointer & subtreeRoot);
	void leafHeightsAux(ostream & out, BinNodePointer subtreeRoot, int height) const;
	int NewSearchAux(const int & item, BinNodePointer subtreeRoot) const;
}; // end of class declaration

#endif
