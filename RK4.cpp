#include <iostream>
#include <cmath>

using namespace std;

float func_prime(float x, float y) {
    return 2 * x + sin(y);
}

int main() {
    float x0, y0, xn;
    cout << "Enter initial values (x0, y0): ";
    cin >> x0 >> y0;
    cout << "Enter final value of x (xn): ";
    cin >> xn;

    int n;
    cout << "Enter no of steps :";
    cin >> n;

    // step size
    float h = (xn - x0) / n;

    float x = x0, y = y0;
    float k1 = 0, k2 = 0, k3 = 0, k4 = 0, k = 0;
    for (int i = 0; i < n; i++) {
        k1 = h * func_prime(x, y);
        k2 = h * func_prime(x + h / 2, y + k1 / 2);
        k3 = h * func_prime(x + h / 2, y + k2 / 2);
        k4 = h * func_prime(x + h, y + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y += k;
        x += h;
        cout << "x = " << x << ", y = " << y << endl;
    }
    return 0;
}