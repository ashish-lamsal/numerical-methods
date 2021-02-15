#include <iostream>
#include <iomanip>
using namespace std;

class Factorization
{
private:
	float** arr, ** lower, ** upper;
	float* b, * x, * y;
	int N;

public:
	Factorization()
	{
		getorder();

		arr = new float* [N];
		lower = new float* [N];
		upper = new float* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new float[N];
			lower[i] = new float[N];
			upper[i] = new float[N];
		}

		b = new float[N];
		x = new float[N];
		y = new float[N];
	}

	~Factorization()
	{
		for (int i = 0; i < N; i++)
		{
			delete[] arr[i];
			delete[] lower[i];
			delete[] upper[i];
		}
		delete[] arr;
		delete[] lower;
		delete[] upper;

		delete[] b;
		delete[] x;
		delete[] y;
	}

	void getorder()
	{
		cout << "Enter number of unknowns :";
		cin >> N;
	}

	void readdata()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << "a(" << i + 1 << "," << j + 1 << ")"
					<< " = ";
				cin >> arr[i][j];
			}
			cout << "b" << i + 1 << " = ";
			cin >> b[i];
		}
	}

	void factorize()
	{
		// factorize A into LU using Do-Little's Method
		float temp;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{

				if (i <= j)
				{
					temp = 0;
					for (int k = 0; k < i; k++)
						temp += lower[i][k] * upper[k][j];

					upper[i][j] = arr[i][j] - temp;

					if (i == j)
						lower[i][j] = 1;
					else
						lower[i][j] = 0;
				}

				else
				{
					if (upper[j][j] == 0) {
						cout << "ERROR: Division by Zero" << endl;
						exit(1);
					}

					temp = 0;
					for (int k = 0; k < j; k++)
						temp += lower[i][k] * upper[k][j];

					lower[i][j] = (arr[i][j] - temp) / upper[j][j];

					upper[i][j] = 0;
				}
			}
		}
	}

	void forwardSubstitution()
	{
		for (int i = 0; i < N; i++)
		{
			float temp = 0;
			for (int j = 0; j < i; j++)
				temp += lower[i][j] * y[j];

			y[i] = b[i] - temp;
		}
	}

	void backSubstitution()
	{
		for (int i = N - 1; i >= 0; i--)
		{
			float temp = 0;
			for (int j = i + 1; j < N; j++)
				temp += upper[i][j] * x[j];

			x[i] = (y[i] - temp) / upper[i][i];
		}
	}

	void display(float** matrix)
	{
		// print the matrix
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << setw(10) << fixed << setprecision(3) << matrix[i][j];
			cout << "\n";
		}
		cout << "\n";
	}

	void display(float** matrix, float* col)
	{
		// print the augmented matrix
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << setw(10) << fixed << setprecision(3) << matrix[i][j];
			cout << " : ";
			cout << col[i];
			cout << "\n";
		}
		cout << "\n";
	}

	void result()
	{
		cout << "Result: " << endl;
		for (int i = 0; i < N; i++)
			cout << "x" << i + 1 << " = " << x[i] << endl;
	}

	void solve()
	{
		readdata();

		factorize();
		cout << "1) Augmented Coefficient Matrix [A:B] : " << endl;
		display(arr, b);
		cout << "2) Factorize A = LU using Do-Little's Method ....." << endl;
		cout << "Lower Triangular Matrix (L) : " << endl;
		display(lower);
		cout << "Upper Triangular Matrix (U) : " << endl;
		display(upper);

		forwardSubstitution();
		cout << "\n3) Perform LY = B and calculate Y ....." << endl;
		cout << "Augmented Matrix [L:B] : " << endl;
		display(lower, b);
		cout << "Calculating Y via forward substitution : " << endl;
		for (int i = 0; i < N; i++)
			cout << "y" << i + 1 << " = " << y[i] << endl;

		backSubstitution();
		cout << "\n\n4) Perform UX = Y and calculate X ....." << endl;
		cout << "Augmented Matrix [U:Y] : " << endl;
		display(upper, y);
		cout << "Calculating X via backward substitution : " << endl;

		result();
	}
};

int main()
{
	Factorization f;
	f.solve();
	return 0;
}