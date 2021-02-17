#include <iostream>
#include <iomanip>
using namespace std;

float** getInput(int N) {
	// dynamically create array of pointers of size N
	float** arr = new float* [N];

	// dynamically allocate memory of size N + 1 for each row
	for (int i = 0; i < N; i++)
		arr[i] = new float[N + 1];

	// assign values to allocated memory
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "a(" << i + 1 << "," << j + 1 << ")" << " = ";
			cin >> arr[i][j];
		}
		cout << "b" << i + 1 << " = ";
		cin >> arr[i][N];
	}

	return arr;
}

void display(float** arr, int N) {
	// print the augmented matrix
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

void toUpperTriangular(float** arr, int N) {
	// conversion to upper triangular form
	for (int j = 0; j < N - 1; j++)	{
		for (int i = j + 1; i < N; i++)	{
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

float* backSubstitution(float** arr, int N) {
	// calculate result via back substitution
	float* x = new float[N];
	for (int i = N - 1; i >= 0; i--) {
		float temp = 0;
		for (int j = i + 1; j < N; j++)
			temp += arr[i][j] * x[j];

		x[i] = (arr[i][N] - temp) / arr[i][i];
	}
	return x;
}

void result(float* x, int N) {
	cout << "Result (Back Substitution) : " << endl;
	for (int i = 0; i < N; i++)
		cout << "x" << i + 1 << " = " << x[i] << endl;
}

int main() {
	int N;
	cout << "Enter order of square matrix :";
	cin >> N;

	float** arr = getInput(N);

	cout << "Augmented Coefficient Matrix : " << endl;
	display(arr, N);

	toUpperTriangular(arr, N);
	float* x = backSubstitution(arr, N);

	// result
	result(x, N);

	// deallocate memory using delete[] operator
	delete[] x;
	for (int i = 0; i < N; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}