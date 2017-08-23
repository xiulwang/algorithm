#include "StackList.h"
#include<iostream>

bool StackList::isEmpty()
{
	return num == 0;
}

int StackList::getNum()
{
	return num;
}

void StackList::push(int val)
{
	Node *oldfirst = first;
	first = new Node();
	first->item = val;
	first->next = oldfirst;
	++num;
}

int StackList::pop()
{
	int val = first->item;
	first = first->next;
	--num;
	return val;
}

void StackList::itr()
{
	Node *itr = first;
	while (itr != nullptr){
		std::cout << itr->item << std::endl;
		itr = itr->next;
	}
}
