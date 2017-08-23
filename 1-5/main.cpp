#include <iostream>
#include "UF.h"
#include"quickUnion.h"
using namespace std;

void UFTest()
{
	cout << "please input the number: " << endl;
	int N;
	cin >> N;
	UF uf(N);
	int a, b;
	while (cin >> a >> b){
		if (a == -1 && b == -1)
			break;
		uf.unions(a, b);
	}
	cout << uf.count() << endl;
}

void quickUFTest()
{
	cout << "please input the number: " << endl;
	int N;
	cin >> N;
	quickUnion uf(N);
	int a, b;
	while (cin >> a >> b){
		if (a == -1 && b == -1)
			break;
		uf.unions(a, b);
		uf.itr();
	}
	cout << uf.count() << endl;
}

int main()
{
	quickUFTest();
	system("pause");
	return 0;
}
