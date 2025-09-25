#include <iostream>
using namespace std;

// Example: dy/dx = f(x,y) = x + y
double f(double x, double y) {
    return x + y;
}

int main() {
    double x0, y0, x, h;
    int n;

    cout << "Enter initial x0: ";
    cin >> x0;
    cout << "Enter initial y0: ";
    cin >> y0;
    cout << "Enter final x: ";
    cin >> x;
    cout << "Enter step size h: ";
    cin >> h;

    double y = y0;
    int steps = (int)((x - x0) / h);

    cout << "x\t\ty" << endl;
    cout << x0 << "\t" << y0 << endl;

    for (int i = 0; i < steps; i++) {
        double k1 = h * f(x0, y);
        double k2 = h * f(x0 + h/2, y + k1/2);
        double k3 = h * f(x0 + h/2, y + k2/2);
        double k4 = h * f(x0 + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x0 = x0 + h;

        cout << x0 << "\t" << y << endl;
    }

    cout << "\nEstimated solution at x = " << x << " is y = " << y << endl;
    return 0;
}
