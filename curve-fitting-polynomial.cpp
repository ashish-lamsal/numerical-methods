#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float** getMatrix(float* X, float* Y, int N, int l) {
    float** arr = new float* [N];
    for (int i = 0; i < N; i++)
        arr[i] = new float[N + 1];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < l; k++) {
                arr[i][j] += pow(X[k], i + j);
            }
        }
        for (int k = 0; k < l; k++) {
            arr[i][N] += pow(X[k], i) * Y[k];
        }
    }
    return arr;
}

void display(float** arr, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (j == N)
				cout << " : ";
			cout << setw(10) << fixed << setprecision(3) << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}


void gaussJordan(float** arr, int N) {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (i == j)
				continue;

			if (arr[j][j] == 0) {
				cout << "ERROR: Division by Zero" << endl;
				exit(1);
			}

			float ratio = arr[i][j] / arr[j][j];

			cout << "Operate R" << i + 1 << " <-- R" << i + 1 << " - (" << arr[i][j] << "/" << arr[j][j] << ")" << "*R" << j + 1 << endl;

			for (int k = j; k < N + 1; k++) {
				arr[i][k] -= ratio * arr[j][k];
			}
		}
		display(arr, N);
	}
}

void result(float** arr, int N) {
	cout << "Coefficients of polynomial are: " << endl;
    for (int i = 0; i < N; i++)
        cout << "a" << i << " = " << arr[i][N] / arr[i][i] << endl;
}

int main() {
    int num;
    cout << "Enter number of data :";
    cin >> num;

    float* X = new float[num];
    float* Y = new float[num];

    for (int i = 0; i < num; i++) {
        cout << "X" << i + 1 << " = ";
        cin >> X[i];
    }

    for (int i = 0; i < num; i++) {
        cout << "Y" << i + 1 << " = ";
        cin >> Y[i];
    }

    int d;
    cout << "Enter degree of polynomial :";
    cin >> d;

    float** arr = getMatrix(X, Y, d + 1, num);

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