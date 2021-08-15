#include<iostream>                
#include<random>
#include <ctime>
#include <vector>
#include<algorithm>
using namespace std;

int RandInt(int beg,int end)        
{
	static default_random_engine generator(time(NULL));
	static uniform_int_distribution<int> distribution(beg,end);
	return distribution(generator);
}

void Swap(int* m,int* n)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}

int main()
{
	int N;
	cin >> N;
	vector<int> A;
	for(int i = 0;i != N;++i)
		A.push_back(i+1);
	for(int i = 1; i != N;++i)
		Swap(&A[i],&A[RandInt(0,i)]);
	for(const int& i : A)
		cout<< i <<" ";
	return 0;
}
