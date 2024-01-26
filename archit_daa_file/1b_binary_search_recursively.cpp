#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);
    return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) cout << "Element found at index " << result << endl;
    else cout << "Element not found." << endl;

    return 0;
}
