#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter order of matrix (n): ";
    cin >> n;

    double A[20][40]; // Augmented matrix (A | I)

    cout << "Enter the matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Augment with identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            if (j - n == i)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }

    // Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Pivot check
        if (fabs(A[i][i]) < 1e-9) {
            cout << "Matrix is singular, cannot be inverted!" << endl;
            return -1;
        }

        // Make pivot = 1
        double pivot = A[i][i];
        for (int j = 0; j < 2 * n; j++) {
            A[i][j] /= pivot;
        }

        // Make other entries in column = 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }

    // Extract inverse matrix
    cout << "\nInverse of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
