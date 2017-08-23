#pragma once
class UF
{
private:
	int *id;
	int num;
	int size;
public:
	UF(int N);
	int count();
	int find(int p);
	bool connected(int p, int q);
	void unions(int p, int q);
	~UF();
};

