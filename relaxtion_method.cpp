#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    double A[20][20], b[20], x[20], tol, omega;
    int maxIter;

    cout << "Enter coefficient matrix A:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter constants vector b:" << endl;
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << "Enter initial guesses for x:" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter relaxation factor omega (0 < omega < 2): ";
    cin >> omega;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    double x_old[20];

    for (int i = 0; i < n; i++)
        x_old[i] = x[i];

    int iter = 0;
    while (iter < maxIter) {
        for (int i = 0; i < n; i++) {
            double sum1 = 0, sum2 = 0;
            for (int j = 0; j < i; j++) sum1 += A[i][j] * x[j];
            for (int j = i+1; j < n; j++) sum2 += A[i][j] * x_old[j];

            double xi = (b[i] - sum1 - sum2) / A[i][i];
            x[i] = (1 - omega) * x_old[i] + omega * xi;
        }

        // Check convergence
        bool converged = true;
        for (int i = 0; i < n; i++) {
            if (fabs(x[i] - x_old[i]) > tol) {
                converged = false;
                break;
            }
        }

        for (int i = 0; i < n; i++)
            x_old[i] = x[i];

        if (converged) break;
        iter++;
    }

    if (iter == maxIter)
        cout << "\nDid not converge within maximum iterations." << endl;
    else
        cout << "\nConverged solution after " << iter+1 << " iterations:" << endl;

    for (int i = 0; i < n; i++)
        cout << "x[" << i+1 << "] = " << x[i] << endl;

    return 0;
}

