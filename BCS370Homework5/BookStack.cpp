//****************************************************
// File: BookStack.cpp
//
// Purpose: Contains all of the function definitions 
//			for the BookStack class
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//*****************************************************
#include "BookStack.h"
//****************************************************
// Function: BookStack()
//
// Purpose: The default constructor for BookStack
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
//
//****************************************************
BookStack::BookStack() {
	//creates dynamically allocated array that is empty
	arr = new Book[5];
	top = -1;
	maximum = 5;
}

//****************************************************
// Function: BookStack(int max)
//
// Purpose: Constructor for BookStack that takes in the max 
//			size of the array
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
//
//****************************************************
BookStack::BookStack(int max) {
	//creates dynamically allocated array that is empty
	arr = new Book[max];
	top = -1;
	maximum = max;
}

//****************************************************
// Function: BookStack(const BookStack& rhs)
//
// Purpose: does a deep copy of the member variables 
//			as a copy constuctor
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
BookStack::BookStack(const BookStack& rhs) {
	//sets the array to NULL first
	arr = NULL;
	delete[]arr;
	//makes the max and the top values the same
	maximum = rhs.maximum;
	top = rhs.top;

	//creates a new dynamically allocated array
	arr = new Book[maximum];
	//loops through and copies the values from the rhs to the new array
	for (int i = 0; i <= top; i++) {
		arr[i] = rhs.arr[i];
	}
}

//****************************************************
// Function: ~BookStack()
//
// Purpose: destructor
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
//
//****************************************************
BookStack::~BookStack() {
	//delete the arr pointer 
	delete[] arr;
	cout << "BookStack destructor called" << endl;
}

//****************************************************
// Function: Clear()
//
// Purpose: clears the stack
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
void BookStack::Clear() {
	//logically clears the whole stack
	top = -1;
}

//****************************************************
// Function: Size()
//
// Purpose: returns the logical size of the stack
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
int BookStack::Size() {
	//return the logical size of the dynamically allocated array
	return top + 1;
}
//****************************************************
// Function: MaxStorage()
//
// Purpose: returns the maximum size of the stack
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
int BookStack::MaxStorage() {
	//return the max size of the dynamically allocated array
	return maximum;
}

//****************************************************
// Function: Push(Book b)
//
// Purpose: adds the given Book to the top of the stack
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
bool BookStack::Push(Book b) {
	//checks to see if the stack is full
	if (top == maximum - 1) {
		return false;
	}

	//otherwise we increment and add it
	//increment top
	top++;
	//add the Book to the stack
	arr[top] = b;
	return true;
}
//****************************************************
// Function: Pop()
//
// Purpose: removes the given Book from the top of the stack
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
bool BookStack::Pop() {
	//check if the stack is empty
	if (top == -1) {
		return false;
	}

	//otherwise, we decrement top
	//we do not need to delete the Book since it is not logically there
	top--;
	return true;

}

//****************************************************
// Function: Top(Book& b)
//
// Purpose: gets the top element of the stack and passes the 
//			value by reference
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
bool BookStack::Top(Book& b) {
	//checks if the stack is empty
	if (top == -1) {
		return false;
	}

	//without removing the top element, we set b equal to the Book at the top of the stack
	b = arr[top];
	return true;
}

//***************************************************
// Function: operator=(BookStack& rhs)
//
// Purpose: overloads the assignment operator = and 
//			creates an object like a copy constructor
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
BookStack& BookStack::operator=(BookStack& rhs) {
	//checks to see if we are trying to set it equal to itself
	if (this == &rhs) {
		return *this;
	}

	//sets the array to NULL first
	arr = NULL;
	delete[]arr;
	//makes the max and the top values the same
	maximum = rhs.maximum;
	top = rhs.top;

	//creates a new dynamically allocated array
	arr = new Book[maximum];
	//loops through and copies the values from the rhs to the new array
	for (int i = 0; i <= top; i++) {
		arr[i] = rhs.arr[i];
	}
}

//****************************************************
// Function: operator<<(ostream& os, BookStack& rhs)
//
// Purpose: prints the values of all member variables 
//			on the given ostream
//
// Big-O Runtime Cost: O(n) if not empty 
//
// Update Information
// ------------------
// 
//****************************************************
ostream& operator<<(ostream& os, BookStack& rhs) {
	//checks if stack is empty
	if (rhs.top == -1) {
		os << "The stack is empty" << endl;
		return os;
	}
	//otherwise it loops through the stack
	for (int i = 0; i <= rhs.top; i++) {
		os << "Book " << i + 1 << ": \n" << rhs.arr[i] << "\n";
	}
	return os;		//returns the os so it will print the entire line above
}
