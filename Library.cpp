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

//Function to add books into the list
void Library::addBook(string bookName)
{
	Book book(bookName);
	listOfBooks.push_front(book);
}

//Function to add employees into the list
void Library::addEmployee(string name)
{
	Employee* employee;
	employee = new Employee(name);
	listOfEmployees.push_front(employee);

}

//Pass on the book to the next employee in the queue
//If no one is left in the queue the book is archived 
void Library::passOn(string bookName, Date date)
{
	Employee* next, * front; //Used to store the employees at the front employee and the next employee after the front
	for (list<Book>::iterator it = listOfBooks.begin(); it != listOfBooks.end(); ++it) //First looks through the list of books to find the book we need to pass on
	{
		if (it->getBookName() == bookName) //Once the book in the list we need to pass on is found
		{
			front = it->top();
			it->removeHighPriority(); //Remove the employee at front and the next employee should be the new front
			front->addRetainTime(date - it->getLastHeldDate()); //Updates the employee retain time who passed the book on
			front->updatePriority(); //Updates the employee priority who passed the book on
			if (!it->isArchived()) //If there are still employees in the queue
			{
				next = it->top();
				next->addWaitTime(date - it->getDateStart()); //Update the employee wait time who just got the book
				it->setLastHeldDate(date); //Update the last held date for the book
				next->updatePriority(); //Update the priority of the employee who just got the book
			}
			else //If there are no employees left in the queue
			{
				it->setDateEnd(date); //Update the end date
				listOfArchivedBooks.push_back(*it); //Move to the book into the archived list
				listOfBooks.erase(it); //Remove the book from the book list
			}
			break;
		}
	}
	for (list<Book>::iterator it = listOfBooks.begin(); it != listOfBooks.end(); ++it) //Used to go through the other queues of the books
	//I didn't used one for loop in the case that the second book was the pass on book which would cause the first book to not update the queue.
	{
		if (it->getBookName() != bookName) //For the books that wasn't passed on then their queues get updated from the employees who changed their priorities
		{
			it->updateQueue();
			//These two lines below are just for testing to see if the queue was correct
			//it->showQueue();
			//cout << endl;
		}
	}
}

//To start the circulation of the book on the date given
void Library::circulateBook(string bookName, Date date)
{
	for (list<Book>::iterator it = listOfBooks.begin(); it != listOfBooks.end(); ++it)
	{
		if (it->getBookName() == bookName)
		{
			it->addEmployeeToQueue(listOfEmployees); //Creates the queue
			it->setDateStart(date); //Set the start date
			//These two lines below are just for testing to see if the queue was correct
			//it->showQueue();
			//cout << endl;
			break;
		}
	}
}