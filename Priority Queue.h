#pragma once
#include <iostream>
#include "Employee.h"
using namespace std;

struct Node
{
	Employee data;
	struct Node* next;
};

class PriorityQueue
{
public:
	PriorityQueue();
	void push(Employee* employee);
	bool isEmpty();
	void pop();

private:
	int numberOfEmployee;
	Node* head;
};