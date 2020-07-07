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
	this->dateStart = dateLastHeld = dateStart;
}

//Setter for end date
void Book::setDateEnd(Date dateEnd)
{
	this->dateEnd = dateEnd;
}

//Setter for the date that someone who last held onto the book
void Book::setLastHeldDate(Date newLastHeld)
{
	this->dateLastHeld = newLastHeld;
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

//Getter for the date that someone who last held onto the book
Date Book::getLastHeldDate()
{
	return this->dateLastHeld;
}

//Returnes the employee who is at the front of the priority queue
Employee* Book::top()
{
	return queue.top();
}

//Will return true if there are no employees in the queue if not then return false
bool Book::isArchived()
{
	this->archived = queue.isEmpty();
	return this->archived;
}

//Pushes the employees  from the list into the queue
void Book::addEmployeeToQueue(const list<Employee*> listOfEmployees)
{
	for (list<Employee*>::const_iterator it = listOfEmployees.begin(); it != listOfEmployees.end(); it++)
	{
		queue.push(*it);
	}
}

//Pops the highest priority employee
void Book::removeHighPriority()
{
	queue.pop();
}

//Updates the queue or sort the queue in decreasing order of priority
void Book::updateQueue()
{
	queue.updateQueue();
}
