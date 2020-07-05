#include <iostream>
#include "Priority Queue.h"
using namespace std;

PriorityQueue::PriorityQueue()
{
	head = NULL;
	numberOfEmployee = 0;
}

void PriorityQueue::push(Employee* employee)
{
	Node * temp;
	Node * higherThanTemp;
	temp = new Node;
	temp->data = employee;
	if (head == NULL || temp->data->getPriority() > head->data->getPriority())
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		higherThanTemp = head;
		while (higherThanTemp->next != NULL && higherThanTemp->next->data->getPriority() >= temp->data->getPriority())
		{
			higherThanTemp = higherThanTemp->next;
			temp->next = higherThanTemp->next;
			higherThanTemp->next = temp;
		}
	}
	numberOfEmployee++;
}

bool PriorityQueue::isEmpty()
{
	if (numberOfEmployee == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PriorityQueue::pop()
{
	Node* temp;
	if (head == NULL)
	{
		cout << "Queue is empty nothing to pop" << endl;
	}
	else
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}