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
    float k = 0;
    for (int i = 0; i < n; i++) {
        k = h * func_prime(x, y);
        y += k;
        x += h;
        cout << "x = " << x << ", y = " << y << endl;
    }
    return 0;
}