#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int change_x[8] = { 1,1,0,-1,-1,-1,0,1 };    
int change_y[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<vector<char>> list; 
vector<string> dict; 

int main()
{
	int dict_n, table_n;
	string word;
	char letter;
	cin >> dict_n;  
	while (dict_n--) {
		cin >> word;
		dict.push_back(word);
	}
	cin >> table_n;   
	list.resize(table_n);     
	for (int i = 0; i != table_n; ++i) {
		for (int j = 0; j != table_n; ++j) {
			cin >> letter;
			list[i].push_back(letter);
		}
	}
	for (int i = 0; i != table_n; ++i) { 
		for (int j = 0; j != table_n; ++j) {
			for (int k = 0; k != 8; ++k) { 
				string s;
				int x = i;
				int y = j;
				for (int l = 0; l != table_n; ++l) {   
					s += list[x][y];
					x += change_x[k];
					y += change_y[k];
					if (find(dict.cbegin(), dict.cend(), s) != dict.cend())  
						cout << s << endl;
					if (x < 0 || x >= table_n || y < 0 || y >= table_n)	break;  
				}
			}
		}
	}
	return 0;
}
