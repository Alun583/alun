#include <iostream>
using namespace std;
void insertSort(int a[], int n);
int main(){
    int a[] = {3,1,4,1,5,9,2,6,5};
    insertSort(a, 9);
    for(int i = 0; i < 9; i++){
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}
 
void insertSort(int a[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 && a[j] < a[j-1]; j--){
            swap(a[j], a[j-1]);
        }
    }
}
