#pragma once
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
	Library();

	void passOn(Book book, Date date);
	void circulateBook(Book book, Date date);
	void addEmployee(Employee employeeName);
	void addBook(Book bookName);

private:
	list<Employee> listOfEmployees;
	list<Book> listOfBooks;
};
