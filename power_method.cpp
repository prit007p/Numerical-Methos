#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the order of the square matrix: ";
    cin >> n;

    double A[10][10];
    double x[10], y[10];
    double tol;
    int maxIter;

    cout << "Enter the matrix A row by row:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter initial guess vector:" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    double lambda = 0, lambda_old;
    int iter = 0;

    while (iter < maxIter) {
        // Multiply A*x
        for (int i = 0; i < n; i++) {
            y[i] = 0;
            for (int j = 0; j < n; j++)
                y[i] += A[i][j] * x[j];
        }

        // Find new eigenvalue approximation
        lambda_old = lambda;
        lambda = fabs(y[0]);
        for (int i = 1; i < n; i++)
            if (fabs(y[i]) > lambda)
                lambda = fabs(y[i]);

        // Normalize y to get next x
        for (int i = 0; i < n; i++)
            x[i] = y[i] / lambda;

        // Check convergence
        if (fabs(lambda - lambda_old) < tol)
            break;

        iter++;
    }

    cout << "\nLargest Eigenvalue = " << lambda << endl;
    cout << "Corresponding Eigenvector: ";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;

    return 0;
}

