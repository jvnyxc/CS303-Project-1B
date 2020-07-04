#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee
{
public:
	Employee();
	Employee(int waitTime, int retainingTime, string name);

	void setWaitTime(int waitTime);
	void setRetainingTime(int retainingTime);
	void setEmployeeName(string name);

	int getWaitTime();
	int getRetainingTime();
	string getName();
	int getPriority();

	void updatePriority();

private:
	int waitTime;
	int retainingTime;
	string employeeName;
	int priority;
};