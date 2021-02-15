#include <iostream>
#include <cmath>

using namespace std;

float func(float x) {
    return 1 / (1 + pow(x, 2));
}

int main() {
    int N;
    cout << "Enter number of strips :";
    cin >> N;
    
    if (N % 3 != 0) {
        cout << "Error : Couldnot compute" << endl;
        exit(0);
    }

    float a, b;
    cout << "Enter limit of integration : ";
    cin >> a >> b;

    float h = (b - a) / N;
    float sum = func(a) + func(b);
    
    float x = 0;
    for (int i = 1; i < N; i++) {
        int m = (i % 3 == 0) ? 2 : 3;
        x = a + i * h;
        sum += m * func(x);
    }
    
    sum *= 3 * h / 8;
    cout << "sum = " << sum << endl;

    return 0;
}