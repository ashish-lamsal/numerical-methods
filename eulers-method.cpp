#include <iostream>
#include <cmath>

using namespace std;

float func_prime(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, xn;
    cout << "Enter initial values (x0, y0): ";
    cin >> x0 >> y0;
    cout << "Enter final value of x (xn): ";
    cin >> xn;

    float h;
    cout << "Enter step-size :";
    cin >> h;

    int n = (xn - x0) / h;

    float x = x0, y = y0;
    float k = 0;
    for (int i = 0; i < n; i++) {
        k = h * func_prime(x, y);
        y += k;
        x += h;
        cout << "x = " << x << ", y = " << y << endl;
    }
    return 0;
}