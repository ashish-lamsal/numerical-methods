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
	// print the 2D array
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
	cout << "Result: " << endl;
	for (int i = 0; i < N; i++)
		cout << "x" << i + 1 << " = " << arr[i][N] << "/" << arr[i][i] << " = " << arr[i][N] / arr[i][i] << endl;
}


int main() {
	int N;
	cout << "Enter order of square matrix :";
	cin >> N;

	float** arr = getInput(N);

	cout << "Given Augmented Matrix: " << endl;
	display(arr, N);

	gaussJordan(arr, N);

	// result
	result(arr, N);

	// deallocate memory using delete[] operator
	for (int i = 0; i < N; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}