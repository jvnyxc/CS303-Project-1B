#pragma once
#include <iostream>
#include "Employee.h"
using namespace std;

struct Node
{
	Employee* data;
	struct Node* next;
};

class PriorityQueue
{
public:
	//Constructor
	PriorityQueue();

	//Destructor
	~PriorityQueue();

	//Functions
	void push(Employee* employee);
	bool isEmpty();
	void pop();
	void swap(struct Node* ptr1, struct Node* ptr2);
	void updateQueue();
	Employee* top();
	//void showQueue();

private:
	int numberOfEmployee;
	Node* head;
};