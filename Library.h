#include <iostream>
#include <string>
#include <list>
#include "Book.h"
#include "Employee.h"
#include "Priority Queue.h"
#include "Date.h"
#include "StringTokenizer.h"
using namespace std;

class Library
{
public:
	//Constructor
	Library();

	//Destructor
	~Library();

	//Functions
	void passOn(string bookName, Date date);
	void circulateBook(string bookName, Date date);
	void addEmployee(string name);
	void addBook(string bookName);

private:
	list<Employee*> listOfEmployees;
	list<Book> listOfBooks;
	list<Book> listOfArchivedBooks;
};
