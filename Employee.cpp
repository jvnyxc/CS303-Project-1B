#include "Employee.h"

//Default Constructor
Employee::Employee()
{
	waitTime = 0;
	retainingTime = 0;
	employeeName = "";
}

//Constructor
Employee::Employee(string name)
{
	waitTime = 0;
	retainingTime = 0;
	priority = 0;
	employeeName = name;
}

//Setter for the wait time
void Employee::setWaitTime(int waitTime)
{
	waitTime = waitTime;
}

//Setter for the retaining time
void Employee::setRetainingTime(int retainingTime)
{
	retainingTime = retainingTime;
}

//Setter for the employee name
void Employee::setEmployeeName(string name)
{
	employeeName = name;
}

//Getter for the wait time
int Employee::getWaitTime()
{
	return waitTime;
}

//Getter for the retaining time
int Employee::getRetainingTime()
{
	return retainingTime;
}

//Getter for the employee name
string Employee::getName()
{
	return employeeName;
}

//Getter for the priority
int Employee::getPriority()
{
	return priority;
}

//This updates the priority of the employee in the queue
void Employee::updatePriority()
{
	priority = waitTime - retainingTime;
}

//This add how long the employee been waiting for a book in days 
void Employee::addWaitTime(int wait)
{
	waitTime += wait;
}

//This add how long the employee retain a book in days 
void Employee::addRetainTime(int retain)
{
	retainingTime += retain;
}