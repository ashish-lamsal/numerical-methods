#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Enter number of data :";
    cin >> N;

    float* X = new float[N];
    float* Y = new float[N];

    for (int i = 0; i < N; i++) {
        cout << "X" << i + 1 << " = ";
        cin >> X[i];
    }

    for (int i = 0; i < N; i++) {
        cout << "Y" << i + 1 << " = ";
        cin >> Y[i];
    }

    float b;
    cout << "Enter X to interpolate f(X) :";
    cin >> b;

    float sum = 0;
    for (int i = 0; i < N; i++) {
        float temp = 1;
        for (int j = 0; j < N; j++) {
            if (i != j)
                temp *= (b - X[j]) / (X[i] - X[j]);
        }
        sum += temp * Y[i];
    }

    cout << "Y(" << b << ") = " << sum << endl;

    delete[] X;
    delete[] Y;

    return 0;
}