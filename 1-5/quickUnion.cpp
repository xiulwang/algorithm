#include "quickUnion.h"
#include<iostream>


quickUnion::quickUnion(int N)
{
	componet = N;
	size = N;
	id = new int[N];
	for (int i = 0; i < N; ++i)
		id[i] = i;
}


quickUnion::~quickUnion()
{
}

int quickUnion::find(int p)
{
	while (p != id[p])
		p = id[p];
	return p;
}

int quickUnion::count()
{
	return componet;
}

bool quickUnion::connected(int p, int q)
{
	return find(p) == find(q);
}

void quickUnion::unions(int p, int q)
{
	int pRoot = find(p);
	int qRoot = find(q);
	if (pRoot == qRoot)
		return;
	else{
		id[pRoot] = qRoot;
		--componet;
	}
}

void quickUnion::itr()
{
	for (int i = 0; i < size; ++i)
		std::cout << id[i] << std::endl;
}

