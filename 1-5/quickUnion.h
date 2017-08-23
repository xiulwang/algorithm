#pragma once
class quickUnion
{
private:
	int size;
	int componet;
	int *id;
public:
	quickUnion(int N);
	~quickUnion();
	int count();
	int find(int p);
	bool connected(int p, int q);
	void unions(int p, int q);
	void itr();
};
