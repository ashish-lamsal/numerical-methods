#include <iostream>
#include <cmath>

using namespace std;

float f_prime(float x, float y, float z) {
    return z;
}

float g_prime(float x, float y, float z) {
    return x * z - y;
}

int main() {
    float x0, y0, z0, xn;
    cout << "Enter initial values (x0, y0, z0): ";
    cin >> x0 >> y0 >> z0;
    cout << "Enter final value of x (xn): ";
    cin >> xn;

    float h;
    cout << "Enter step-size :";
    cin >> h;

    int n = (xn - x0) / h;

    float x = x0, y = y0, z = z0;
    float k1 = 0, k2 = 0, k3 = 0, k4 = 0, k = 0;
    float l1 = 0, l2 = 0, l3 = 0, l4 = 0, l = 0;
    for (int i = 0; i < n; i++) {
        k1 = h * f_prime(x, y, z);
        l1 = h * g_prime(x, y, z);
        
        k2 = h * f_prime(x + h / 2, y + k1 / 2, z + l1 / 2);
        l2 = h * g_prime(x + h / 2, y + k1 / 2, z + l1 / 2);
        
        k3 = h * f_prime(x + h / 2, h + k2 / 2, z0 + l2 /2);
        l3 = h * g_prime(x + h / 2, h + k2 / 2, z0 + l2 /2);
        
        k4 = h * f_prime(x + h, y + k3, z0 + l3);
        l4 = h * g_prime(x + h, y + k3, z0 + l3);
        
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        
        x += h;
        y += k;
        z += l;
        cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    }
    return 0;
}