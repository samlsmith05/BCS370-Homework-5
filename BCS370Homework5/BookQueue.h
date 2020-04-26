//****************************************************
// File: BookQueue.h
//
// Purpose: Contains the class definition for BookCollection
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//****************************************************
#ifndef BOOKQUEUE_H
#define BOOKQUEUE_H
#include <string>
#include <iostream>
#include "Book.h"
using namespace std;

class BookQueue
{
private:
	//NodeType struct
	struct NodeType {
		Book b;
		NodeType* next;
	};
	//Member variables
	NodeType* front;
	NodeType* rear;
	int length;
public:
	//Methods
	BookQueue();
	BookQueue(const BookQueue& rhs);
	~BookQueue();
	void Clear();
	int Size();
	void Enqueue(Book e);
	bool Dequeue(Book& returnedBook);
	BookQueue& operator=(BookQueue& rhs);
	friend ostream& operator<<(ostream& os, BookQueue& rhs);

};

#endif