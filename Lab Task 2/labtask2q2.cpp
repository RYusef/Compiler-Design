#include <iostream>
using namespace std;

void avg(int n){
    int arr[n];
    int sum = 0;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double average = (double)sum / n;
    cout << "Average value = " << average << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    avg(n);
    return 0;
}
