#pragma once
#include <iostream>
#include<string>
#include<list>
#include "Date.h"
#include "Employee.h"
#include "Priority Queue.h"
using namespace std;

class Book
{
public:
	//Constructor 
	Book();
	Book(string bookName);

	//Setters
	void setBookName(string bookName);
	void setDateStart(Date dateStart);
	void setDateEnd(Date dateEnd);
	void setLastHeldDate(Date newLastHeld);

	//Getters
	string getBookName();
	Date getDateStart();
	Date getDateEnd();
	Date getLastHeldDate();
	Employee* top();

	//Functions
	bool isArchived();
	void addEmployeeToQueue(const list<Employee*> listOfEmployees);
	void removeHighPriority();
	void updateQueue();

private:
	string bookName;
	Date dateStart;
	Date dateEnd;
	bool archived;
	PriorityQueue queue;
	Date dateLastHeld;
};