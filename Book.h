#pragma once
#include <iostream>
#include<string>
#include "Date.h"
#include "Employee.h"
using namespace std;

class Book
{
public:
	Book();
	Book(string bookName);

	void setBookName(string bookName);
	void setDateStart(Date dateStart);
	void setDateEnd(Date dateEnd);

	string getBookName();
	Date getDateStart();
	Date getDateEnd();

	bool isArchived();
	void addEmployeeToQueue(Employee* user);
	void removeHighPriority();

private:
	string bookName;
	Date dateStart;
	Date dateEnd;
	bool archived;
};