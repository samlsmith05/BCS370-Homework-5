//****************************************************
// File: BST.cpp
//
// Purpose: Contains all of the function definitions 
//			for the BST class
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//*****************************************************
#include "BST.h"

//****************************************************
// Function: BST()
//
// Purpose: The default constructor for BST
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
//
//****************************************************
BST::BST()
{
	//sets an empty tree
	root = NULL;
}

//****************************************************
// Function: BST(const BST& rhs)
//
// Purpose: The copy constructor for BST that performs
//			a deep copy
//
// Big-O Runtime Cost: O(nlogn)
//
// Update Information
// ------------------
//
//****************************************************
BST::BST(const BST& rhs)
{
	//if the rhs is an empty tree, we make the new one an empty tree also
	if (rhs.root == NULL) {
		root = NULL;
	}
	//if the tree is not empty
	else {
		//calls the helper method
		CopyTree(root, rhs.root);
	}
}

//****************************************************
// Function: ~BST()
//
// Purpose: The destructor for BST
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
BST::~BST()
{
	//empties the tree
	Clear();
	cout << "BST destructor called..." << endl;
}

//****************************************************
// Function: Clear()
//
// Purpose: empties the binary search tree
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Clear()
{
	//calls the helper method
	Clear(root);
	//sets the root to NULL so it points to nothing
	root = NULL;
}

//****************************************************
// Function: int Size()
//
// Purpose: returns the number of elements in the tree
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
int BST::Size()
{
	//calls the helper method
	return Size(root);
}

//****************************************************
// Function: Add(Book e)
//
// Purpose: adds a book to the tree according to the 
//			titles of the book
//
// Big-O Runtime Cost: O(logn)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Add(Book e)
{
	//calls the helper method 
	Add(root, e);
}

//****************************************************
// Function: Preorder()
//
// Purpose: Prints the title of all books in the
//			tree using a preorder traversal
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Preorder()
{
	//calls the helper method
	Preorder(root);
}

//****************************************************
// Function: Inorder()
//
// Purpose: Prints the title of all books in the
//			tree using an inorder traversal
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Inorder()
{
	//calls the helper method
	Inorder(root);
}

//****************************************************
// Function: Postorder()
//
// Purpose: Prints the title of all books in the
//			tree using a postorder traversal
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Postorder()
{
	//calls the helper method
	Postorder(root);
}

//****************************************************
// Function: bool GetPrice(string title, double& price)
//
// Purpose: Searches the whole tree to find the book with 
//			with the given title to get the price of the
//			book
//
// Big-O Runtime Cost: O(logn)
//
// Update Information
// ------------------
//
//****************************************************
bool BST::GetPrice(string title, double& price)
{
	//calls the helper method
	return GetPrice(root, title, price);
}

//****************************************************
// Function: operator=(const BST& rhs)
//
// Purpose: performs a deep copy of the rhs 
//
// Big-O Runtime Cost: O(nlogn)
//
// Update Information
// ------------------
//
//****************************************************
BST& BST::operator=(const BST& rhs)
{
	//checks to see if we are trying to set it equal to itself
	if (this == &rhs) {
		return *this;
	}
	//if the bst is not empty, then clear the whole thing
	if (root != NULL) {
		Clear();
	}
	//if the one tree is empty, makes the new tree empty also
	if (rhs.root == NULL) {
		root = NULL;
	}
	else {
		//calls the helper method to copy the tree
		CopyTree(root, rhs.root);
	}
	return *this;
}


//****************************************************
// Function: operator<<(ostream& os, BST& rhs)
//
// Purpose: Prints all the data for each node on the tree
//			using an inorder traversal of the tree
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
ostream& operator<<(ostream& os, BST& rhs) {
	//calls helper method
	rhs.PrintAll(rhs.root, os, rhs);
	return os;

}

//****************************************************
// Function: Add(Node*& tree, Book e)
//
// Purpose: adds a book to the tree according to the 
//			titles of the book using recursion. 
//			Helper method
//
// Big-O Runtime Cost: O(logn)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Add(Node*& tree, Book e)
{
	//if the tree is null, we add it right there
	if (tree == NULL) {
		//creates a new node
		tree = new Node();
		//adds the new leaf's information
		tree->b = e;
		tree->left = NULL;
		tree->right = NULL;
	}
	//uses the operator< from Book to see if it needs to the left node
	else if (e < tree->b) {
		Add(tree->left, e);			//direct recursion
	}
	//goes to the right node
	else {
		Add(tree->right, e);		//direct recursion
	}
}

//****************************************************
// Function: Preorder(Node* tree)
//
// Purpose: prints the tree using preorder traversal
//			and recursion.
//			Helper method
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Preorder(Node* tree)
{
	//checks to see if the tree is null already
	if (tree != NULL) {
		cout << "Title: " << tree->b.GetTitle() << endl;	//prints the current node's title
		Preorder(tree->left);								//direct recursion of the left nodes
		Preorder(tree->right);								//direct recursion of the right nodes
	}
}

//****************************************************
// Function: Inorder(Node* tree)
//
// Purpose: prints the tree using inorder traversal
//			and recursion.
//			Helper method
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Inorder(Node* tree)
{
	//checks to see if the tree is null already
	if (tree != NULL) {
		Inorder(tree->left);								//direct recursion of the left nodes
		cout << "Title: " << tree->b.GetTitle() << endl; //prints the current node's title
		Inorder(tree->right);							//direct recursion of the right nodes
	}
}
//****************************************************
// Function: Postorder(Node* tree)
//
// Purpose: prints the tree using postorder traversal
//			and recursion.
//			Helper method
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Postorder(Node* tree)
{
	//checks to see if the tree is null already
	if (tree != NULL) {
		Postorder(tree->left);								//direct recursion of the left nodes
		Postorder(tree->right);								//direct recursion of the right nodes
		cout << "Title: " << tree->b.GetTitle() << endl;	//prints the current node's title
	}
}

//****************************************************
// Function: GetPrice(Node* tree, string title, double& price)
//
// Purpose: checks to see if the book is in the tree and 
//			returns the price of that book.
//			Helper method
//
// Big-O Runtime Cost: O(logn)
//
// Update Information
// ------------------
//
//****************************************************
bool BST::GetPrice(Node* tree, string title, double& price) {
	bool result = false;
	//sees if the tree is empty
	if (tree == NULL) {
		cout << "Cannot search an empty tree." << endl;
	}
	
	else {
		//loops through until the tree is null or the result becomes true
		while (tree != NULL && result == false) {
			//sees if the title's are equal
			if (tree->b.GetTitle() == title) {
				//sets the price equal to the current node's price
				price = tree->b.GetPrice();
				result = true;
				return result;
			}
			//sees if the title is less than the current node's title, and will then go to the left
			else if (title < tree->b.GetTitle()) {
				//if the left node is null, we have reached the end and the book is not in the tree
				if (tree->left == NULL) {
					return false;
				}
				return GetPrice(tree->left, title, price);			//direct recursion for left nodes
			}
			//sees if the title is greater than the current node's title, and will then go to the right
			else {
				//if the right node is null, we have reached the end and the book is not in the tree
				if (tree->right == NULL) {
					return false;
				}
				return GetPrice(tree->right, title, price);			//direct recursion for right nodes
			}
		}
	}
	return result;
	
}

//****************************************************
// Function: Clear(Node*& tree)
//
// Purpose: checks to see if the book is in the tree and 
//			returns the price of that book.
//			Helper method
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::Clear(Node*& tree)
{
	//checks if the tree is empty or not
	if (tree != NULL)
	{
		Clear(tree->left);		//direct recursion for left nodes

		Clear(tree->right);		//direct recursion for right nodes
		delete tree;			//deletes the pointer
	}

}

//****************************************************
// Function: PrintAll(Node* tree, ostream& os, BST& rhs)
//
// Purpose: prints all the data using an inorder traversal
//			Helper method
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::PrintAll(Node* tree, ostream& os, BST& rhs)
{
	//checks to see if the tree is empty
	if (tree != NULL) {
		PrintAll(tree->left, os, rhs);		//direct recursion to the left nodes
		os << tree->b << endl;				//adds the current book to the os
		PrintAll(tree->right, os, rhs);		//direct recursion to the right nodes
	}
	
}

//****************************************************
// Function: CopyTree(Node*& copy, Node* tree)
//
// Purpose: copy the tree while copying the exact
//			structure of the tree
//			Helper method
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
void BST::CopyTree(Node*& copy, Node* tree) {
	//if the tree is already empty, make the new tree empty also
	if (tree == NULL)
		copy = NULL;
	else
	{
		//adds the new leaf
		copy = new Node;
		copy->b = tree->b;
		CopyTree(copy->left, tree->left);		//direct recursion for left
		CopyTree(copy->right, tree->right);		//direct recursion for right
	}
}

//****************************************************
// Function: Size(Node* tree)
//
// Purpose: gets the size of the tree
//			Helper method
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
int BST::Size(Node* tree)
{
	//if the tree is empty, the size is 0
	if (tree == NULL){
		return 0;
	}	
	//recursively calls adding to the total to return it
	else{ 
		return Size(tree->left) + Size(tree->right) + 1;
	}
}
