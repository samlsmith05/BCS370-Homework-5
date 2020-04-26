//****************************************************
// File: Main.cpp
//
// Purpose: Show and utilize all the functions in all the classes
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//****************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "BookCollection.h"
#include "BookList.h"
#include "BookQueue.h"
#include "BookStack.h"
#include "BST.h"
using namespace std;

//****************************************************
// Function: main()
//
// Purpose: entry point for the program
//
// Update Information
// ------------------
//
//****************************************************

int main() {
	Book book1 = Book();			//calls the default constructor
	Book book2 = Book("ABC123", "The Hunger Games", 19.95);		//calls the constructor that takes all member variables
	Book book3 = Book("XYZ789", "To Kill A Mockingbird", 23.75);//calls the constructor that takes all member variables
	Book book4 = Book("JKL456", "Introduction to C++", 163.98); //calls the constructor that takes all member variables
	Book book5 = Book();			//calls the default constructor
	Book book6 = Book(book4);		//calls the copy constructor
	Book book7 = book2;				//calls operator=

	book1.SetIsbn("321EFG");		//calls SetIsbn
	book1.SetPrice(9.99);			//calls SetPrice
	book1.SetTitle("Easy Poems");	//calls SetTitle

	book5.SetIsbn("QRS987");
	book5.SetTitle("Divergent");
	book5.SetPrice(15.99);

	cout << "Operator< test true result: " << endl;
	if (book3 < book2) {									//calls operator<
		cout << book3.GetTitle() << " is the lesser title.\n";
	}
	else {
		cout << book2.GetTitle() << " is the lesser title.\n";
	}

	cout << "Operator< test false result: " << endl;
	if (book2 < book3) {									//calls operator<
		cout << book2.GetTitle() << " is the lesser title.\n";
	}
	else {
		cout << book3.GetTitle() << " is the lesser title.\n";
	}
	
	cout << "Operator> test true result: " << endl;
	if (book3 > book2) {									//calls operator>
		cout << book3.GetTitle() << " is the greater title.\n";
	}
	else {
		cout << book2.GetTitle() << " is the greater title.\n";
	}

	cout << "Operator> test false result: " << endl;
	if (book2 > book3) {									//calls operator>
		cout << book2.GetTitle() << " is the greater title.\n";
	}
	else {
		cout << book3.GetTitle() << " is the greater title.\n";
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "BST tests follow.\n";

	BST bst = BST();									//calls default constructor
	

	bst.Add(book1);										//calls Add
	bst.Add(book2);										//calls Add
	bst.Add(book4);										//calls Add
	bst.Add(book5);										//calls Add
	bst.Add(book3);										//calls Add

	cout << "Inorder traversal: " << endl;
	bst.Inorder();										//calls Inorder

	cout << "-------------------------------------------------" << endl;

	cout << "Preorder traversal: " << endl;
	bst.Preorder();										//calls Preorder

	cout << "-------------------------------------------------" << endl;

	cout << "Postorder traversal: " << endl;
	bst.Postorder();									//calls Postorder
	
	cout << "-------------------------------------------------" << endl;

	cout << "Price of requested book: " << endl;
	double p;
	if (bst.GetPrice("Introduction to C++", p)) {		//calls GetPrice
		cout << "Introduction to C++'s price is $" << p << endl;
	}
	else {
		cout << "The book is not in the tree." << endl;
	}
	cout << "-------------------------------------------------" << endl;
	if (bst.GetPrice("The Hunger Games", p)) {		//calls GetPrice
		cout << "The Hunger Games's price is $" << p << endl;
	}
	else {
		cout << "The book is not in the tree." << endl;
	}
	cout << "-------------------------------------------------" << endl;

	cout << "Price of requested book: " << endl;
	if (bst.GetPrice("The Alchemist", p)) {
		cout << "The Alchemist's price is $" << p << endl;
	}
	else {
		cout << "The book is not in the tree." << endl;
	}

	cout << "-------------------------------------------------" << endl;

	cout << bst;											//calls operator<<
	cout << "The size of the search tree is " << bst.Size() << endl;	//calls Size

	cout << "-------------------------------------------------" << endl;

	BST bst2 = bst;											//calls operator=

	cout << "Operator= tree is: " << endl;
	cout << bst2;											//calls operator<<
	cout << "Postorder of bst2: \n";
	bst2.Postorder();
	
	cout << "-------------------------------------------------" << endl;

	BST bst3 = BST(bst);									//calls copy constructor
	cout << "Copy constructed tree is: " << endl;
	cout << bst3;											//calls operator<<
	cout << "Postorder of bst3: \n";
	bst3.Postorder();
	
	cout << "-------------------------------------------------" << endl;

	bst.Clear();											//calls Clear
	cout << "After clear:\n" << bst;						//calls operator<<
	cout << "The size of the search tree is " << bst.Size() << endl;	//calls Size

	cout << "-------------------------------------------------" << endl;

	



	return 0;
}