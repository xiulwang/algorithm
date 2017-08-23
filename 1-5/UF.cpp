#include "UF.h"
#include<iostream>

UF::UF(int N)
{
	num = N;
	size = N;
	id = new int[N];
	for (int i = 0; i < N; ++i)
		*(id + i) = i;
}

int UF::count()
{
	return num;
}

int UF::find(int p)
{
	return *(id + p);
}

bool UF::connected(int p, int q)
{
	return find(p) == find(q);
}

void UF::unions(int p, int q)
{
	int pID = find(p);
	int qID = find(q);
	if (pID != qID){
		for (int i = 0; i < size; ++i){
			if (*(id + i) == pID)
				*(id + i) = qID;
		}
		--num;
	}
}

UF::~UF()
{
}

