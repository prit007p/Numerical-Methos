#include <iostream>
#include <cmath>
using namespace std;

// Example function: f(x) = x^3 - x - 2
double f(double x) {
    return x*x*x - x - 2;
}

// Derivative: f'(x) = 3x^2 - 1
double df(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(double x0, double tol, int maxIter) {
    double x1;
    int iter = 0;

    cout << "Iter\tApproximation" << endl;

    while (iter < maxIter) {
        double fx = f(x0);
        double dfx = df(x0);

        if (fabs(dfx) < 1e-9) {
            cout << "Derivative near zero. Method fails." << endl;
            return;
        }

        x1 = x0 - fx / dfx;
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
    double x0, tol;
    int maxIter;

    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    newtonRaphson(x0, tol, maxIter);

    return 0;
}
