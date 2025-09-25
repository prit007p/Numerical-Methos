#include <iostream>
#include <cmath>
using namespace std;

// Example function: f(x) = x^2
double f(double x) {
    return x * x;
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of sub-intervals n (even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Number of sub-intervals must be even!" << endl;
        return 1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }

    double integral = sum * h / 3.0;
    cout << "\nEstimated integral = " << integral << endl;

    return 0;
}
