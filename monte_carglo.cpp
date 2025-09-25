#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Example function: f(x) = x^2
double f(double x) {
    return x * x;
}

double monteCarlo(double a, double b, int N) {
    double sum = 0.0;

    for (int i = 0; i < N; i++) {
        double r = (double)rand() / RAND_MAX;   // random number in [0,1]
        double x = a + (b - a) * r;             // scale to [a,b]
        sum += f(x);
    }

    double integral = (b - a) * sum / N;
    return integral;
}

int main() {
    srand(time(0)); // Seed random generator

    double a, b;
    int N;

    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of random samples N: ";
    cin >> N;

    double result = monteCarlo(a, b, N);

    cout << "\nEstimated integral = " << result << endl;
    return 0;
}
