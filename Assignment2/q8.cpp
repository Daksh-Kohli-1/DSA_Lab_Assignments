#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i=0; i<n; i++) cin >> arr[i];

    set<int> s;
    for (int i=0; i<n; i++) {
        s.insert(arr[i]);
    }

    cout << "Total distinct elements: " << s.size() << endl;

    return 0;
}
