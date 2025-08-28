#include <iostream>
using namespace std;

int countInversionsNaive(int arr[], int n) {
    int inv = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) inv++;
        }
    }
    return inv;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i=0; i<n; i++) cin >> arr[i];

    cout << "Number of inversions : " << countInversionsNaive(arr, n) << endl;

    return 0;
}
