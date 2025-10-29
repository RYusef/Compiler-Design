#include <iostream>
using namespace std;

int findMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < minVal)
            minVal = arr[i];
    return minVal;
}

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Minimum value = " << findMin(arr, n) << endl;
    cout << "Maximum value = " << findMax(arr, n) << endl;

    return 0;
}
