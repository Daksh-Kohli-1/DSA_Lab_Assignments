#include <iostream>
using namespace std;

int main(){
    //Take input and sort array
    cout << "Enter the length of the array: \n";
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "The array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The sorted array elements are: ";
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
     for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //a)
    int ans = 0;
    int sum = 0;
    int arr_sum =0 ;
    for(int i=1;i<=size+1;i++){
        sum += i;
    }
    for(int i=0;i<size;i++){
        arr_sum += arr[i];
    }
    ans = sum - arr_sum;
    cout << "Missing element is: " << ans << endl;

    //b)
    int start = 0;
    int end = size - 1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == mid+1){
            start = mid + 1;
        }
        else {
            if(mid == 0 || arr[mid - 1] == mid ){
                cout << "Missing elemenet is(binary search): " << mid + 1 << endl;
                return 0;
            }
            end = mid - 1;
        }
    }
    cout << "No missing element : " ;
    return 0;
}