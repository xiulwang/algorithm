#pragma once
#include<string>

class StackArray
{
public:
	StackArray() = default;
	StackArray(const int N) :size(N), items(new std::string[N]){};
	bool isEmpty();
	int getNum();
	int getSize();
	void push(std::string item);
	void resize(const int max);
	std::string pop();
	~StackArray();
private:
	int size;
	int num;
	std::string *items;
};
