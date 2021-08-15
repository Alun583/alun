#include<iostream>
#include<ctime>
#include<fstream>
#include<random>
using namespace std;

int arr[100010];

void BubleSort(int arr[], int length)
{
	for (int i = length - 1; i != 0; --i) {   
		for (int j = 0; j != i; ++j) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	ifstream in("test.txt");
	ofstream out("test.txt");
	uniform_int_distribution<unsigned> u(0, 200000);
	default_random_engine e;
	for (size_t i = 0; i < 100000; ++i) {
		out << u(e) << " ";            
	} 
	int N, num; 
	cin >> N;        
	int k = N / 2; 
	clock_t t;
	t = clock(); 
	for (int i = 0; i != k; ++i) {
		in >> num;
		arr[i] = num;
	}
	BubleSort(arr, k);
	int temp = k;
	while (temp--) {
		in >> num;
		if (num <= arr[k - 1])	continue;
		else {
			for (int i = k - 2; i >= 0; --i) {
				if (arr[i] >= num) {
					for(int j = k - 1;j != i + 1;--j) {
						arr[j] = arr[j - 1];
					}
					arr[i + 1] = num;
					break;
				}
			}
		}
	}
	cout << arr[k - 1] << endl;
	t = clock() - t;
	cout << "It took " << static_cast<float>(t) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}
