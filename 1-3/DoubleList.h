#pragma once
class DoubleList
{
private:
	struct Node
	{
		int item;
		Node *next;
		Node *before;
	};
	int num;
	Node *first;
	Node *last;
public:
	DoubleList() :num(0), first(nullptr), last(nullptr){};
	~DoubleList();
	bool isEmpty();
	int getNum();
	void insertFirst(int val);
	void insertLast(int val);
	void insert(int loc, int val);
	int deleteFirst();
	int deleteLast();
	int deleteLoc(int loc);
	void iteration();
};

