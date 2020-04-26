//****************************************************
// File: BST.h
//
// Purpose: Contains the class definition for BST
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//****************************************************
#ifndef BST_H
#define BST_H
#include <string>
#include <iostream>
#include "Book.h"
using namespace std;
class BST
{
	//Member variables
	private: 
		//struct for the linked implementation
		struct Node {
			Node* left;
			Node* right;
			Book b;
		};
		Node* root;
		//Helper methods
		void Add(Node*& tree, Book e);
		void Preorder(Node* tree);
		void Inorder(Node* tree);
		void Postorder(Node* tree);
		bool GetPrice(Node* tree, string title, double& price);
		void Clear(Node*& tree);
		void PrintAll(Node* tree, ostream& os, BST& rhs);
		void CopyTree(Node*& copy, Node* tree);
		int Size(Node* tree);

	//Methods
	public:
		BST();
		BST(const BST& rhs);
		~BST();

		void Clear();
		int Size();
		void Add(Book e);
		void Preorder();
		void Inorder();
		void Postorder();
		bool GetPrice(string title, double& price);
		BST& operator=(const BST& rhs);
		friend ostream& operator<<(ostream& os, BST& rhs);

};


#endif
