#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr[], int n) {
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] > arr[minIndex])
                minIndex = j;
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < a.size(); i++) {
		cin >> a[i];
	}
    selectionSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i]<<" ";
	}
	return 0;
}