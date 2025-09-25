#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    double a[20][20]; // Augmented matrix
    double x[20];     // Solution array

    cout << "Enter the augmented matrix (row by row):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for (int i = 0; i < n; i++) {
        // Pivoting
        if (fabs(a[i][i]) < 1e-9) {
            cout << "Mathematical error: Zero pivot encountered!" << endl;
            return -1;
        }

        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Output solution
    cout << "\nSolution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }

    return 0;
}

