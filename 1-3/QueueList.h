#pragma once
class QueueList
{
private:
	struct Node
	{
		int item;
		Node *next;
	};
	Node *first;
	Node *last;
	int num;
public:
	QueueList() :first(nullptr), last(nullptr), num(0) {};
	~QueueList();
	bool isEmpty();
	int getNum();
	void enqueue(int val);
	int dequeue();
	void itr();
};
