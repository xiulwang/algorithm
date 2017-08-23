#include<iostream>
#include "StackList.h"
#include "QueueList.h"
#include "DoubleList.h"
using namespace std;

void StackListTest()
{
	StackList test;
	test.push(1);
	test.push(2);
	test.push(3);
	cout << "pop the number:" << test.pop() << endl;
	cout << "number: " << test.getNum() << endl;
	test.itr();
}

void QueueListTest()
{
	QueueList test;
	test.enqueue(1);
	test.enqueue(2);
	test.enqueue(3);
	cout << "pop the number:" << test.dequeue() << endl;
	cout << "number: " << test.getNum() << endl;
	test.itr();
}

void DoubleListTest()
{
	DoubleList test;
	test.insertFirst(1);
	test.insertFirst(2);
	test.insertLast(3);
	test.iteration();
	test.insert(3, 10);
	test.iteration();
	test.deleteFirst();
	test.deleteLoc(2);
	test.iteration();
}

int main()
{
	DoubleListTest();
	system("pause");
	return 0;
}
 
