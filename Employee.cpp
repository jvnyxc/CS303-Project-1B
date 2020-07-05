#include "Employee.h"

//Default Constructor
Employee::Employee()
{
	this->waitTime = 0;
	this->retainingTime = 0;
	this->employeeName = "";
}

//Constructor
Employee::Employee(int waitTime, int retainingTime, string name)
{
	this->waitTime = waitTime;
	this->retainingTime = 0;
	this->employeeName = name;
}

//Setter for the wait time
void Employee::setWaitTime(int waitTime)
{
	this->waitTime = waitTime;
}

//Setter for the retaining time
void Employee::setRetainingTime(int retainingTime)
{
	this->retainingTime = retainingTime;
}

//Setter for the employee name
void Employee::setEmployeeName(string name)
{
	this->employeeName = name;
}

//Getter for the wait time
int Employee::getWaitTime()
{
	return this->waitTime;
}

//Getter for the retaining time
int Employee::getRetainingTime()
{
	return this->retainingTime;
}

//Getter for the employee name
string Employee::getName()
{
	return this->employeeName;
}

//Getter for the priority
int Employee::getPriority()
{
	return this->priority;
}

//This updates the priority of the employee in the queue
void Employee::updatePriority()
{
	this->priority = waitTime - retainingTime;
}
