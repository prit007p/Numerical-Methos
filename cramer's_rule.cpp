#include <iostream>
using namespace std;

int main() {
    double a1, b1, c1;
    double a2, b2, c2;

    cout << "Enter coefficients for equation 1 (a1 b1 c1): ";
    cin >> a1 >> b1 >> c1;

    cout << "Enter coefficients for equation 2 (a2 b2 c2): ";
    cin >> a2 >> b2 >> c2;

    // Determinants
    double D  = a1*b2 - a2*b1;
    double Dx = c1*b2 - c2*b1;
    double Dy = a1*c2 - a2*c1;

    if (D == 0) {
        if (Dx == 0 && Dy == 0)
            cout << "Infinite solutions (dependent equations)" << endl;
        else
            cout << "No solution (inconsistent equations)" << endl;
    } else {
        double x = Dx / D;
        double y = Dy / D;
        cout << "Solution: x = " << x << ", y = " << y << endl;
    }

    return 0;
}

