#include <iostream>
#include <cmath>
using namespace std;

// Example function: g(x) = sqrt(x + 2)
// Solves equation x^2 - x - 2 = 0  →  x = sqrt(x+2)
double g(double x) {
    return sqrt(x + 2);
}

void fixedPoint(double x0, double tol, int maxIter) {
    double x1;
    int iter = 0;

    cout << "Iter\tApproximation" << endl;

    while (iter < maxIter) {
        x1 = g(x0);
        cout << iter + 1 << "\t" << x1 << endl;

        if (fabs(x1 - x0) < tol) {
            cout << "\nConverged to root: " << x1 << endl;
            return;
        }

        x0 = x1;
        iter++;
    }

    cout << "\nDid not converge within " << maxIter << " iterations." << endl;
}

int main() {
    double x0 = 1.5;   // Initial guess
    double tol = 1e-6; // Tolerance
    int maxIter = 50;  // Maximum iterations

    fixedPoint(x0, tol, maxIter);

    return 0;
}
