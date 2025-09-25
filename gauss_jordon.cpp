#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    double a[20][20]; // Augmented matrix
    cout << "Enter the augmented matrix (row by row):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Pivoting
        if (fabs(a[i][i]) < 1e-9) {
            cout << "Mathematical error: Zero pivot encountered!" << endl;
            return -1;
        }

        // Make pivot = 1
        double pivot = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= pivot;
        }

        // Make other entries in column = 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = a[k][i];
                for (int j = 0; j <= n; j++) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    // Output solution
    cout << "\nSolution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << a[i][n] << endl;
    }

    return 0;
}
