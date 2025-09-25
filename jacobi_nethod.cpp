#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    double a[20][20], b[20], x[20], newX[20];
    double tol;
    int maxIter;

    cout << "Enter the coefficients of the equations (matrix A):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter constants (vector b):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << "Enter initial guesses for variables:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    cout << "\nIter\t";
    for (int i = 0; i < n; i++) cout << "x[" << i+1 << "]\t";
    cout << endl;

    // Jacobi Iteration
    for (int iter = 1; iter <= maxIter; iter++) {
        for (int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            newX[i] = sum / a[i][i];
        }

        cout << iter << "\t";
        for (int i = 0; i < n; i++) {
            cout << newX[i] << "\t";
        }
        cout << endl;

        // Check convergence
        bool converged = true;
        for (int i = 0; i < n; i++) {
            if (fabs(newX[i] - x[i]) > tol) {
                converged = false;
                break;
            }
        }

        for (int i = 0; i < n; i++) x[i] = newX[i];

        if (converged) {
            cout << "\nConverged solution found after " << iter << " iterations:" << endl;
            for (int i = 0; i < n; i++) {
                cout << "x[" << i+1 << "] = " << x[i] << endl;
            }
            return 0;
        }
    }

    cout << "\nDid not converge within " << maxIter << " iterations." << endl;
    return 0;
}
