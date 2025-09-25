
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter order of matrix (n): ";
    cin >> n;

    double A[20][20], L[20][20] = {0}, U[20][20] = {0};
    double b[20], x[20], y[20];

    cout << "Enter matrix A (row by row):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter constants vector b:" << endl;
    for (int i = 0; i < n; i++) cin >> b[i];

    // Decomposition into L and U
    for (int i = 0; i < n; i++) {
        // Upper triangular U
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];
            U[i][k] = A[i][k] - sum;
        }

        // Lower triangular L
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    // Forward substitution (Ly = b)
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * y[j];
        y[i] = b[i] - sum;
    }

    // Back substitution (Ux = y)
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
            sum += U[i][j] * x[j];
        x[i] = (y[i] - sum) / U[i][i];
    }

    // Output
    cout << "\nLower triangular matrix L:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << L[i][j] << " ";
        cout << endl;
    }

    cout << "\nUpper triangular matrix U:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << U[i][j] << " ";
        cout << endl;
    }

    cout << "\nSolution (x vector):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i+1 << "] = " << x[i] << endl;
    }

    return 0;
}
