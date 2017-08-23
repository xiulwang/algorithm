#include "StackArray.h"

StackArray::~StackArray()
{
}

bool StackArray::isEmpty()
{
	return num == 0;
}

int StackArray::getNum()
{
	return num;
}

int StackArray::getSize()
{
	return size;
}

void StackArray::resize(const int max)
{
	std::string *temp = new std::string[max];
	for (int i = 0; i < size; ++i)
		*(temp + i) = *(items + i);
	items = temp;
	size = max;
}

void StackArray::push(std::string item)
{
	if (num == size){
		if (num==0)
			resize(2);
		else
			resize(2 * num);
	}
	*(items + num) = item;
	++num;
}

std::string StackArray::pop()
{
	std::string item = *(items + num - 1);
	--num;
	if (num > 0 && num <= size / 4)
		resize(size / 2);
	return item;
}
