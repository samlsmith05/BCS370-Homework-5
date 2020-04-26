//****************************************************
// File: BookStack.h
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
#ifndef BOOKSTACK_H
#define BOOKSTACK_H
#include <string>
#include <iostream>
#include "Book.h"
using namespace std;


class BookStack
{
	//Member variables
private:
	Book* arr;
	int top;
	int maximum;
	//Member Functions
public:
	BookStack();
	BookStack(int max);
	BookStack(const BookStack& rhs);

	~BookStack();
	void Clear();
	int Size();
	int MaxStorage();
	bool Push(Book b);
	bool Pop();
	bool Top(Book& b);

	BookStack& operator=(BookStack& rhs);
	friend ostream& operator<<(ostream& os, BookStack& rhs);


};

#endif



