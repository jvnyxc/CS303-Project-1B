#include "Book.h"

//Default Constructor
Book::Book()
{
	this->bookName = "";
	this->archived = true;
}

//Constructor
Book::Book(string bookName)
{
	this->bookName = bookName;
	this->archived = true;
}

//Setter for book name
void Book::setBookName(string bookName)
{
	this->bookName = bookName;
}

//Setter for start date
void Book::setDateStart(Date dateStart)
{
	this->dateStart = dateStart;
}

//Setter for end date
void Book::setDateEnd(Date dateEnd)
{
	this->dateEnd = dateEnd;
}

//Getter for book name
string Book::getBookName()
{
	return this->bookName;
}

//Getter for start date
Date Book::getDateStart()
{
	return this->dateStart;
}

//Getter for end date
Date Book::getDateEnd()
{
	return this->dateEnd;
}

//Getter for the queue
PriorityQueue Book::getQueue()
{
	return this->queue;
}

//Will return true if there are no employees in the queue if not then return false
bool Book::isArchived()
{
	this->archived = queue.isEmpty();
	return this->archived;
}

//Pushes the employee into the queue
void Book::addEmployeeToQueue(Employee* user)
{
	queue.push(user);
}

//Pops the highest priority employee
void Book::removeHighPriority()
{
	queue.pop();
}