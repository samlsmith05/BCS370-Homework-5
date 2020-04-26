//****************************************************
// File: BookQueue.cpp
//
// Purpose: Contains all of the function definitions 
//			for the BookQueue class
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//*****************************************************
#include "BookQueue.h"

//****************************************************
// Function: BookQueue()
//
// Purpose: The default constructor for BookQueue
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
//
//****************************************************
BookQueue::BookQueue()
{
	length = 0;		//sets the length to 0
	//set both to NULL since it is an empty queue still
	front = NULL;
	rear = NULL;
}

//****************************************************
// Function: BookQueue(const BookQueue& rhs)
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
BookQueue::BookQueue(const BookQueue& rhs)
{
	//set everything to null first
	front = NULL;
	rear = NULL;
	length = 0;

	NodeType* temp;

	//checks to see if the rhs's length is 0
	if (rhs.length == 0) {
		return;
	}

	//loops through until temp's next is NULL
	for (temp = rhs.front; temp != NULL; temp = temp->next) {
		Enqueue(temp->b);
	}
	//sets the length's equal
	length = rhs.length;
}

//****************************************************
// Function: ~BookQueue()
//
// Purpose: Destructor for BookQueue
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
BookQueue::~BookQueue()
{
	//calls clear
	Clear();
	//delete the front and rear pointers
	delete front;
	delete rear;
	cout << "BookQueue destructor called" << endl;
}

//****************************************************
// Function: Clear()
//
// Purpose: clears the current queue
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
void BookQueue::Clear()
{
	//create a temp NodeType
	NodeType* temp;

	//loop through until front is equal to NULL
	while (front != NULL) {
		temp = front;			//sets temp to front
		front = front->next;	//sets front to front's next
		delete temp;			//delete temp
	}

	//makes the whole queue empty
	rear = NULL;
	length = 0;

}

//****************************************************
// Function: Size() 
//
// Purpose: returns the number of items in the current queue
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
int BookQueue::Size()
{
	//returns the length of the queue
	return length;
}

//****************************************************
// Function: Enqueue(Book e) 
//
// Purpose: adds the Book to the end of the queue
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
void BookQueue::Enqueue(Book e)
{
	NodeType* temp = new NodeType;	//dynamically allocated a new node

	//set temp's data
	temp->next = NULL;
	temp->b = e;

	//checks to see if the queue is empty
	if (rear == NULL) {
		front = temp;	//sets the front to the temp 
	}
	else {
		rear->next = temp;	//sets the rear's next to point to the temp
	}

	//Make the new element the rear
	rear = temp;
	//Increment the length
	length++;
}

//****************************************************
// Function: Dequeue(Book& returnedBook) 
//
// Purpose: removes the Book from the front of the queue
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
bool BookQueue::Dequeue(Book& returnedBook)
{
	//checks to see if the queue is empty
	if (rear == NULL && front == NULL) {
		cout << "The queue is already empty." << endl;
		return false;
	}

	NodeType* temp = front;		//creates a temp pointer to the front

	returnedBook = front->b;	//sets the data for the pass by reference

	front = front->next;	//move the front to the second node

	//if the list is now empty after removing the item, we set the rear to NULL
	if (front == NULL) {
		rear = NULL;
	}

	//decrement the length
	length--;

	delete temp;	//delete the memory for the deleted node
	return true;
}

//***************************************************
// Function: operator=(BookQueue& rhs)
//
// Purpose: overloads the assignment operator = and 
//			creates an object like a copy constructor
//
// Big-O Runtime Cost: O(2n) = O(n)
//
// Update Information
// ------------------
// 
//****************************************************
BookQueue& BookQueue::operator=(BookQueue& rhs) {
	//clear out the list first
	Clear();

	NodeType* temp = front;
	//checks to see if they are already equal
	if (this == &rhs) {
		return *this;
	}

	//loops through until temp->next is NULL
	while (temp->next != NULL) {
		Enqueue(temp->b);
		temp = temp->next;
	}
	return *this;
}

//****************************************************
// Function: operator<<(ostream& os, BookQueue& rhs)
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
ostream& operator<<(ostream& os, BookQueue& rhs)
{
	//checks if queue is empty
	if (rhs.front == NULL && rhs.rear == NULL) {
		os << "The queue is empty" << endl;
		return os;
	}
	//otherwise it loops through the queue
	//creates a temporary node
	BookQueue::NodeType* temp;
	temp = rhs.front;

	//loops through until temp->next is NULL 
	for (temp = rhs.front; temp != NULL; temp = temp->next) {
		//adds the temp book to the os, but uses the operator<< from Book class
		os << temp->b << endl;
	}
	return os;		//returns the os so it will print the entire line above

}
