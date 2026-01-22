#include <iostream>
using namespace std;

// a) Reverse elements of an array
/*int main(){
    int size;
    cout << "Enter size of array" << endl;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout << "Enter the element" << i+1 << endl;
        cin >> arr[i];
    }
    int start = 0;
    int end = size - 1;
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for(int i=0;i<size;i++){
        cout << arr[i] << ",";
    }
}*/

// b) Matrix Multiplication
/*int main()
{
    int row1, col1, row2, col2;
    cout << "Enter the number of rows and columns for both matrices respectively" << endl;
    cin >> row1;
    cin >> col1;
    cin >> row2;
    cin >> col2;
    int mat1[row1][col1];
    int mat2[row2][col2];
    // Take matrix 1 input
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << "Enter element of matrix:";
            cin >> mat1[i][j];
        }
        cout << endl;
    }
    // Take input of matrix 2
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << "Enter element of matrix:";
            cin >> mat2[i][j];
        }
        cout << endl;
    }

    // Find multiplication
    int ans[row1][col2];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            ans[i][j] = 0;
        }
    }

    if (col1 == row2)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                for (int k = 0; k < col2; k++)
                {
                    ans[i][k] += mat1[i][j] * mat2[j][k];
                }
            }
        }
    }
    else
    {
        cout << "Cannot perform multiplication on these 2 matrices";
    }

    // Print ans
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}*/

// C) Transpose of a matrix
int main(){
    int row1,col1;
    cout << "Enter the dimensions of matrix";
    cin >> row1;
    cin >> col1;
    int mat1[row1][col1];
    //Input the matrix
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << "Enter element of matrix:";
            cin >> mat1[i][j];
        }
        cout << endl;
    }
    //Display matrix
    cout << "The matrix is : " << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << mat1[i][j] << " ";
        }
    //Print transpose
    cout << "The transpose is: " << endl;
    for (int i = 0; i < col1; i++)
    {
        for (int j = 0; j < row1; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

}
