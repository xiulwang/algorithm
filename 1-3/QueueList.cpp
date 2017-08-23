#include "QueueList.h"
#include<iostream>

QueueList::~QueueList()
{
}

bool QueueList::isEmpty()
{
	return num == 0;
}

int QueueList::getNum()
{
	return num;
}

void QueueList::enqueue(int val)
{
	Node *oldlast = last;
	last = new Node();
	last->item = val;
	last->next = nullptr;
	if (isEmpty())
		first = last;
	else
		oldlast->next = last;
	++num;
}

int QueueList::dequeue()
{
	int val = first->item;
	first = first->next;
	--num;
	if (isEmpty())
		last = first;
	return val;
}

void QueueList::itr()
{
	Node *itr = first;
	while (itr != last){
		std::cout << itr->item << std::endl;
		itr = itr->next;
	}
	std::cout << itr->item;
}
