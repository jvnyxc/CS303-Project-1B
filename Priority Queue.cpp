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

//Used to add employee to the queue
//This is set up to automatically put the employee in the right spot of the queue assuming the queue is already sorted. 
//In the main function this feature isn't used since all the employees started at 0 priority when pushed to the queue.
//If the priority is the same then it based on the first in rule.
void PriorityQueue::push(Employee* employee)
{
	Node* temp;
	Node* higherThanTemp;
	temp = new Node;
	temp->data = employee;
	//If the list wasn't created yet or if the pushed employee was higher priority than head
	if (head == NULL || temp->data->getPriority() > head->data->getPriority())
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		higherThanTemp = head;
		//Looks through each next data point to see if it higher than the pushed employee which then just moves to the next data point.
		//Once it finds a next data point where it smaller than priority than the push employee is place after that data point.
		while (higherThanTemp->next != NULL && higherThanTemp->next->data->getPriority() >= temp->data->getPriority())
		{
			higherThanTemp = higherThanTemp->next;
		}
		temp->next = higherThanTemp->next;
		higherThanTemp->next = temp;
	}
	numberOfEmployee++;
}

//Returns true if the queue is empty and false when it's not
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

//Removes the front of the queue
//This should be the highest assuming the queue is sorted
void PriorityQueue::pop()
{
	Node* temp;
	if (head == NULL)
	{
		cout << "Queue is empty nothing to pop" << endl;
	}
	else
	{
		//For testing purposes to see that the right employee was removed from the list
		//cout << "Popped " << head->data->getName() << endl;
		temp = head;
		head = head->next;
		delete temp;
		numberOfEmployee--;
	}
}

//A swap funtion for sorting the list
//This swaps the data values of the pointers not the pointers themselves
void PriorityQueue::swap(struct Node* ptr1, struct Node* ptr2)
{
	Node* temp;
	temp = new Node;
	temp->data = ptr1->data;
	ptr1->data = ptr2->data;
	ptr2->data = temp->data;
}

//This updates the queue or basically sorts the queue in decreasing order
//Used bubble sort
void PriorityQueue::updateQueue()
{
	bool swapped;
	Node* temp;
	Node* ptr1 = NULL;

	//If list is empty
	if (head == NULL)
	{
		return;
	}

	//Instead of for loops I used while statements since it was easier for me to implement the sort
	do
	{
		swapped = false;
		temp = head;

		while (temp->next != ptr1)
		{
			if (temp->data->getPriority() < temp->next->data->getPriority())
			{
				//For testing purposes to make sure the it is swapping the right positions
				//cout << "Swapped: " << temp->data->getName() << " with " << temp->next->data->getName() << endl;
				swap(temp, temp->next);
				swapped = true;
			}
			temp = temp->next;
		}
		ptr1 = temp;
	} while (swapped);
}

//Returns the employee at the top which should be the highest if sorted
Employee* PriorityQueue::top()
{
	return head->data;
}

//Just to show the queue with the employee name and priority
//This function is mostly used for testing purposes to make sure the queue was correct
/*
void PriorityQueue::showQueue()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data->getName() << ": " << temp->data->getPriority() << " -> ";
		temp = temp->next;
	}
}
*/

