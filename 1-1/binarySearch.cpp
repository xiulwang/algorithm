#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void read(string input_text, vector<int>&inputNum)
{
	ifstream in(input_text);
	int num;
	while (in>>num){
		inputNum.push_back(num);
	}
}


int binarySearch(int key, vector<int>inputNum)
{
	vector<int>::size_type left = 0;
	auto right = inputNum.size() - 1;
	while (left <= right){
		auto mid = (right - left) / 2+left;
		if (key == inputNum[mid])
			return mid;
		else if (key < inputNum[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int main()
{
	vector<int>inputNum;
	read("input.txt",inputNum);
	sort(inputNum.begin(), inputNum.end());
	for (auto i : inputNum){
		cout << i << endl;
	}
	int key;
	cin >> key;
	int ind = binarySearch(key, inputNum);
	cout << ind;
	system("pause");
	return 0;
}
