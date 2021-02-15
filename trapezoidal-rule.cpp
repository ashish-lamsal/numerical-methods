#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Enter number of strips :";
    cin >> N;

    float a, b;
    cout << "Enter limit of integration : ";
    cin >> a >> b;

    cout << "Enter Y ordinates : \n";
    float* Y = new float[N + 1];

    for (int i = 0; i < N + 1; i++) {
        cout << "Y" << i + 1 << " = ";
        cin >> Y[i];
    }

    float h = (b - a) / N;
    
    float sum = Y[0] + Y[N];
    for (int i = 1; i < N; i++) {
        sum += 2 * Y[i];
    }

    sum *= h / 2;
    cout << "sum = " << sum << endl;

    delete[] Y;

    return 0;
}