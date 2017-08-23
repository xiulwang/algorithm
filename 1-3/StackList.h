class StackList{
private:
	struct Node{
		int item;
		Node *next;
	};
	Node *first;
	int num;
public:
	StackList() :first(nullptr), num(0){}
	bool isEmpty();
	int getNum();
	void push(int val);
	int pop();
	void itr();
};
