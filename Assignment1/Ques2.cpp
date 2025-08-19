#include <iostream>
#include <vector>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter " << size << " elements:" << endl;
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i] == arr[j]){
                arr.erase(arr.begin() + j);
                j--;
                size--;
            }
        }
    }
    cout << "Unique Array is" << endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }
    return 0;
}