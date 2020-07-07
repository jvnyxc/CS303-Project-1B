#include "Library.h"

//Default Constructor
Library::Library()
{
	//In this case there nothing to initialize
}

//Destructor
Library::~Library()
{
	for (list<Employee*>::iterator it = listOfEmployees.begin(); it != listOfEmployees.end(); it++)
	{
		delete* it;
	}
}

void Library::addBook(string bookName)
{
	Book book(bookName);
	listOfBooks.push_front(book);
}

void Library::addEmployee(string name)
{
	Employee* employee;
	employee = new Employee(name);
	listOfEmployees.push_front(employee);

}

void Library::passOn(string bookName, Date date)
{
	Employee* next, * front; 
	for (list<Book>::iterator it = listOfBooks.begin(); it != listOfBooks.end(); ++it) 
	{
		if (it->getBookName() == bookName)
		{
			front = it->top();
			it->removeHighPriority();
			front->addRetainTime(date - it->getLastHeldDate());
			front->updatePriority();
			if (!it->isArchived()) 
			{
				next = it->top();
				next->addWaitTime(date - it->getDateStart());
				it->setLastHeldDate(date); 
				next->updatePriority(); 
			}
			else 
			{
				it->setDateEnd(date); 
				listOfArchivedBooks.push_back(*it);
				listOfBooks.erase(it);
			}
			break;
		}
	}
	for (list<Book>::iterator it = listOfBooks.begin(); it != listOfBooks.end(); ++it) 
	{
		if (it->getBookName() != bookName) 
		{
			it->updateQueue();
		}
	}
}

void Library::circulateBook(string bookName, Date date)
{
	for (list<Book>::iterator it = listOfBooks.begin(); it != listOfBooks.end(); ++it)
	{
		if (it->getBookName() == bookName)
		{
			it->addEmployeeToQueue(listOfEmployees); 
			it->setDateStart(date);
			break;
		}
	}
}