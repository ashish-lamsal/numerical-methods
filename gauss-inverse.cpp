#include <iostream>
#include <iomanip>
using namespace std;

float** getInput(int N) {
	// dynamically create array of pointers of size N
	float** arr = new float* [N];

	// dynamically allocate memory of size N + 1 for each row
	for (int i = 0; i < N; i++)
		arr[i] = new float[2 * N];

	// assign values to allocated memory
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "a(" << i + 1 << "," << j + 1 << ")" << " = ";
			cin >> arr[i][j];
		}
		for (int j = N; j < 2 * N; j++)
		{
			if (j == i + N)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	return arr;
}

void display(float** arr, int N) {
	// print the augmented matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
		{
			if (j == N)
				cout << " : ";
			cout << setw(10) << fixed << setprecision(3) << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}


void gaussInverse(float** arr, int N) {
	// diagonal form
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == j)
				continue;

			if (arr[j][j] == 0) {
				cout << "ERROR: Division by Zero" << endl;
				exit(1);
			}

			float ratio = arr[i][j] / arr[j][j];

			cout << "Operate R" << i + 1 << " <-- R" << i + 1 << " - (" << arr[i][j] << "/" << arr[j][j] << ")" << "*R" << j + 1 << endl;

			for (int k = j; k < 2 * N; k++)
			{
				arr[i][k] -= ratio * arr[j][k];
			}
		}
		display(arr, N);
	}

	// identity form
	for (int i = 0; i < N; i++) {
		for (int j = N; j < 2 * N; j++) {
			arr[i][j] /= arr[i][i];
		}
		arr[i][i] = 1;
	}
	cout << "Identity Form : " << endl;
	display(arr, N);
}

void result(float** arr, int N) {
	cout << "Inverse is : " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = N; j < 2 * N; j++)
		{
			cout << setw(10) << fixed << setprecision(3) << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}


int main() {
	int N;
	cout << "Enter order of square matrix :";
	cin >> N;

	float** arr = getInput(N);

	cout << "Augmented Coefficient Matrix: " << endl;
	display(arr, N);

	gaussInverse(arr, N);

	// result
	result(arr, N);

	// deallocate memory using delete[] operator
	for (int i = 0; i < N; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}