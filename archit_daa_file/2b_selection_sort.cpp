#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    cout << "enter size of array: ";
    int n; cin >> n;
    vector<int> arr(n);
    cout << "enter array: ";
    for (int idx = 0 ; idx < n ; idx++) 
        cin >> arr[idx];
    selectionSort(arr);
    cout << "Sorted array is:";
    for (int idx = 0 ; idx < n ; idx++) 
        cout << arr[idx] << " "; cout << endl;
    return 0;
}
