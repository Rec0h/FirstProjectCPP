	#include "Queue.h"
	#include <iostream> 

	const int SIZE = 5;

	int main()
	{
		int* queue = new int[SIZE]; //an array dynamic
	}

	void initQueue(Queue* q, unsigned int size)
	{ 
		q->_maxSize = size;
		q->_elements = new int[q->_maxSize];
		q->_count = 0; //setting default values in each thing

	}

	void cleanQueue(Queue* q)
	{
		int i = 0;

		for (i = 0; i < q->_maxSize; i++) //making everything -1 so we know (-1 = empty)
		{
			q->_elements[i] = -1;
		}
	}

	void enqueue(Queue* q, unsigned int newValue)
	{

		if (q->_count == q->_maxSize)
		{	
			std::cout << "Err: Max Size Reached!" << std::endl; //if we reached max allocated size
		}

		if (q->_count != q->_maxSize) //basically if its okay to put something
		{
			q->_elements[q->_count] = newValue;
			q->_count++;
		}
	}

	int dequeue(Queue* q)
	{
		int i = 0;
		int first = 0;

		if (q->_count == 0)
		{
			std::cout << "Err: Can't delete an empty queue." << std::endl;
		}

		first = q->_elements[0];

		for (i = 0; i < q->_maxSize; i++)
		{
			q->_elements[i] = q->_elements[i + 1]; //moving the entire thing when we want to delete
		}

		return first;
	
	}

	bool isEmpty(Queue* s)
	{
		int count = 0;
		int i = 0;

		for (i = 0; i < s->_maxSize; i++) //loops until the end of the array
		{
			if (s->_elements[i] == -1) //if it is empty 
			{
				count++;
			}
		}

		if (count == s->_maxSize) // if everything is empty return true
		{
			return true;
		}
	
		else
		{
			return false;
		}
	}

	bool isFull(Queue* s)
	{
		//same thing in this function but opposite, if there is no -1 then return true
		int count = 0;
		int i = 0;

		for (i = 0; i < s->_maxSize; i++)
		{
			if (s->_elements[i] != -1)
			{
				count++;
			}
		}

		if (count == s->_maxSize)
		{
			return true;
		}

		else
		{
			return false;
		}