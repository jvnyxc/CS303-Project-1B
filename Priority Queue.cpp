#include "Priority Queue.h"

//Constructor 
PriorityQueue::PriorityQueue()
{
	head = nullptr;
	numberOfEmployee = 0;
}

//Destructor
PriorityQueue::~PriorityQueue()
{
	Node* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void PriorityQueue::push(Employee* employee)
{
	Node* temp;
	Node* higherThanTemp;
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
		}
		temp->next = higherThanTemp->next;
		higherThanTemp->next = temp;
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
		delete temp;
		numberOfEmployee--;
	}
}

void PriorityQueue::swap(struct Node* ptr1, struct Node* ptr2)
{
	Node* temp;
	temp = new Node;
	temp->data = ptr1->data;
	ptr1->data = ptr2->data;
	ptr2->data = temp->data;
}

void PriorityQueue::updateQueue()
{
	bool swapped;
	Node* temp;
	Node* ptr1 = NULL;

	if (head == NULL)
	{
		return;
	}

	do
	{
		swapped = false;
		temp = head;

		while (temp->next != ptr1)
		{
			if (temp->data->getPriority() < temp->next->data->getPriority())
			{
				cout << "Swapped: " << temp->data->getName() << " with " << temp->next->data->getName() << endl; 
				swap(temp, temp->next);
				swapped = true;
			}
			temp = temp->next;
		}
		ptr1 = temp;
	} while (swapped);
}

Employee* PriorityQueue::top()
{
	return head->data;
}