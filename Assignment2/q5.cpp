#include <iostream>
using namespace std;

// ---------------- Diagonal Matrix ----------------
void diagonalMatrix(int n) {
    int A[n];  // store only diagonal
    for (int i = 0; i < n; i++) A[i] = 0;

    cout << "\nEnter diagonal elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << A[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// ---------------- Tri-diagonal Matrix ----------------
void triDiagonalMatrix(int n) {
    int A[3*n - 2]; // store 3 diagonals
    for (int i = 0; i < 3*n-2; i++) A[i] = 0;

    cout << "\nEnter tri-diagonal elements (lower, main, upper):\n";
    for (int i = 0; i < 3*n-2; i++) {
        cin >> A[i];
    }

    cout << "Tri-diagonal Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i-j == 0) cout << A[n-1 + i-1] << " ";         // main diagonal
            else if (i-j == 1) cout << A[i-2] << " ";          // lower diagonal
            else if (j-i == 1) cout << A[2*n-1 + i-1] << " ";  // upper diagonal
            else cout << "0 ";
        }
        cout << endl;
    }
}

// ---------------- Lower Triangular Matrix ----------------
void lowerTriangularMatrix(int n) {
    int A[n*(n+1)/2]; // store only lower part
    for (int i = 0; i < n*(n+1)/2; i++) A[i] = 0;

    cout << "\nEnter lower triangular elements:\n";
    for (int i = 0; i < n*(n+1)/2; i++) {
        cin >> A[i];
    }

    cout << "Lower Triangular Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) cout << A[i*(i-1)/2 + j-1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// ---------------- Upper Triangular Matrix ----------------
void upperTriangularMatrix(int n) {
    int A[n*(n+1)/2]; // store only upper part
    for (int i = 0; i < n*(n+1)/2; i++) A[i] = 0;

    cout << "\nEnter upper triangular elements:\n";
    for (int i = 0; i < n*(n+1)/2; i++) {
        cin >> A[i];
    }

    cout << "Upper Triangular Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) cout << A[j*(j-1)/2 + i-1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// ---------------- Symmetric Matrix ----------------
void symmetricMatrix(int n) {
    int A[n*(n+1)/2]; // store only lower part
    for (int i = 0; i < n*(n+1)/2; i++) A[i] = 0;

    cout << "\nEnter symmetric matrix elements (lower triangle including diagonal):\n";
    for (int i = 0; i < n*(n+1)/2; i++) {
        cin >> A[i];
    }

    cout << "Symmetric Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) cout << A[i*(i-1)/2 + j-1] << " ";
            else cout << A[j*(j-1)/2 + i-1] << " ";
        }
        cout << endl;
    }
}

// ---------------- Main ----------------
int main() {
    int n;
    cout << "Enter dimension of matrix: ";
    cin >> n;

    diagonalMatrix(n);
    triDiagonalMatrix(n);
    lowerTriangularMatrix(n);
    upperTriangularMatrix(n);
    symmetricMatrix(n);

    return 0;
}
