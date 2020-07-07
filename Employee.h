#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee
{
public:
	//Constructor
	Employee();
	Employee(string name);

	//Setter
	void setWaitTime(int waitTime);
	void setRetainingTime(int retainingTime);
	void setEmployeeName(string name);

	//Getter
	int getWaitTime();
	int getRetainingTime();
	string getName();
	int getPriority();

	//Functions
	void updatePriority();
	void addWaitTime(int wait);
	void addRetainTime(int retain);

private:
	int waitTime;
	int retainingTime;
	string employeeName;
	int priority;
};