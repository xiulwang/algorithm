#include "DoubleList.h"
#include <iostream>

DoubleList::~DoubleList()
{
}

bool DoubleList::isEmpty()
{
	return num == 0;
}

int DoubleList::getNum()
{
	return num;
}

void DoubleList::insertFirst(int val)
{
	Node *oldfirst = first;
	first = new Node();
	first->item = val;
	first->before = nullptr,
	first->next = oldfirst;
	if (!isEmpty())
		oldfirst->before = first;
	else
		last = first;
	++num;
}

void DoubleList::insertLast(int val)
{
	Node *oldlast = last;
	last = new Node();
	last->item = val;
	last->next = nullptr;
	last->before = oldlast;
	if (!isEmpty())
		oldlast->next = last;
	else
		first = last;
	++num;
}

void DoubleList::insert(int loc, int val)
{
	if (loc == 1)
		insertFirst(val);
	else if (loc == num + 1)
		insertLast(val);
	else{
		Node *itr = first;
		for (int i=1; i < loc - 1; ++i)
			itr = itr->next;
		Node *newnode = new Node();
		newnode->item = val;
		newnode->before = itr;
		newnode->next = itr->next;
		itr->next->before = newnode;
		itr->next = newnode;
		++num;
	}
}

int DoubleList::deleteFirst()
{
	int val = first->item;
	first = first->next;
	--num;
	if (isEmpty())
		last = nullptr;
	else
		first->before = nullptr;
	return val;
}

int DoubleList::deleteLast()
{
	if (first == last){
		int val = first->item;
		first = nullptr;
		last = nullptr;
		--num;
		return val;
	}
	else{
		Node *itr = first;
		while (itr->next != last)
			itr = itr->next;
		int val = last->item;
		last = itr;
		last->next = nullptr;
		--num;
		return val;
	}
}

int DoubleList::deleteLoc(int loc)
{
	int val;
	if (loc == 1)
		val = deleteFirst();
	else if (loc == getNum())
		val = deleteLast();
	else{
		Node *itr = first;
		for (int i = 1; i < loc; ++i)
			itr = itr->next;
		val = itr->item;
		itr->before->next = itr->next;
		itr->next->before = itr->before;
		--num;
	}
	return val;
}

void DoubleList::iteration()
{
	Node *itr = first;
	while (itr != last){
		std::cout << itr->item << std::endl;
		itr = itr->next;
	}
	std::cout << itr->item << std::endl<<std::endl;
}
