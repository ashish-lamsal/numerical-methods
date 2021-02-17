#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float** getMatrix(float* X, float* Y, int size, int N) {
    float** arr = new float* [size];
    for (int i = 0; i < size; i++)
        arr[i] = new float[size + 1];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < N; k++) {
                arr[i][j] += pow(X[k], i + j);
            }
        }
        for (int k = 0; k < N; k++) {
            arr[i][size] += pow(X[k], i) * Y[k];
        }
    }
    return arr;
}

void display(float** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size + 1; j++) {
            if (j == size)
                cout << " : ";
            cout << setw(10) << fixed << setprecision(3) << arr[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}


void gaussJordan(float** arr, int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (i == j)
                continue;

            if (arr[j][j] == 0) {
                cout << "ERROR: Division by Zero" << endl;
                exit(1);
            }

            float ratio = arr[i][j] / arr[j][j];

            cout << "Operate R" << i + 1 << " <-- R" << i + 1 << " - (" << arr[i][j] << "/" << arr[j][j] << ")" << "*R" << j + 1 << endl;

            for (int k = j; k < size + 1; k++) {
                arr[i][k] -= ratio * arr[j][k];
            }
        }
        display(arr, size);
    }
}

void result(float** arr, int size) {
    cout << "Coefficients of polynomial (d=" << size - 1 << ") are:  " << endl;
    for (int i = 0; i < size; i++)
        cout << "a" << i << " = " << arr[i][size] / arr[i][i] << endl;
}

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

    int d;
    cout << "Enter degree of polynomial :";
    cin >> d;

    float** arr = getMatrix(X, Y, d + 1, N);

    cout << "Augmented Matrix: " << endl;
    display(arr, d + 1);

    gaussJordan(arr, d + 1);

    result(arr, d + 1);

    for (int i = 0; i < d + 1; i++)
        delete[] arr[i];
    delete[] arr;

    delete[] X;
    delete[] Y;

    return 0;
}