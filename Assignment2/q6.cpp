#include <iostream>
using namespace std;

#define MAX 100

// Function to read sparse matrix into triplet form
int readSparse(int triplet[MAX][3]) {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int k = 0;
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int x;
            cin >> x;
            if (x != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = x;
                k++;
            }
        }
    }

    // First row stores meta info: rows, cols, non-zero count
    for (int i = k; i >= 1; i--) {
        triplet[i][0] = triplet[i-1][0];
        triplet[i][1] = triplet[i-1][1];
        triplet[i][2] = triplet[i-1][2];
    }
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = k;

    return k+1; // total rows in triplet
}

// Function to print triplet form
void printTriplet(int triplet[MAX][3], int size) {
    cout << "Row Col Val\n";
    for (int i = 0; i < size; i++) {
        cout << triplet[i][0] << "   " << triplet[i][1] << "   " << triplet[i][2] << endl;
    }
}

// (a) Transpose
void transpose(int triplet[MAX][3], int trans[MAX][3]) {
    int rows = triplet[0][0], cols = triplet[0][1], nonzero = triplet[0][2];
    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonzero;

    int k = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= nonzero; i++) {
            if (triplet[i][1] == col) {
                trans[k][0] = triplet[i][1];
                trans[k][1] = triplet[i][0];
                trans[k][2] = triplet[i][2];
                k++;
            }
        }
    }
}

// (b) Addition
void add(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices cannot be added!" << endl;
        return;
    }

    int i=1, j=1, k=1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2]; i++; k++;
        } else if (B[j][0] < A[i][0] || (B[j][0]==A[i][0] && B[j][1]<A[i][1])) {
            C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2]; j++; k++;
        } else {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2]; i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2]; j++; k++;
    }

    C[0][2] = k-1;
}

// (c) Multiplication
void multiply(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrices cannot be multiplied!" << endl;
        return;
    }

    int transB[MAX][3];
    transpose(B, transB);

    int k = 1;
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= transB[0][2]; j++) {
            if (A[i][1] == transB[j][1]) {
                int r = A[i][0];
                int c = transB[j][0];
                int val = A[i][2] * transB[j][2];

                // Check if already exists in C
                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (C[x][0] == r && C[x][1] == c) {
                        C[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    C[k][0] = r; C[k][1] = c; C[k][2] = val;
                    k++;
                }
            }
        }
    }

    C[0][2] = k-1;
}

// ---------------- Main ----------------
int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3], T[MAX][3];
    int sizeA, sizeB, sizeC;

    cout << "--- Read Matrix A ---\n";
    sizeA = readSparse(A);
    printTriplet(A, sizeA);

    cout << "\nTranspose of A:\n";
    transpose(A, T);
    printTriplet(T, T[0][2]+1);

    cout << "\n--- Read Matrix B ---\n";
    sizeB = readSparse(B);
    printTriplet(B, sizeB);

    cout << "\nAddition (A+B):\n";
    add(A,B,C);
    printTriplet(C, C[0][2]+1);

    cout << "\nMultiplication (A*B):\n";
    multiply(A,B,C);
    printTriplet(C, C[0][2]+1);

    return 0;
}
