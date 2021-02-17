// Develop an algorithm and program in C/C++ to find a real root of a polynomial equation of any degree given it�s co - efficients.Hint: construct different functions for the evaluation of polynomial and it�s derivative at a given point given the co - efficients.

#include <iostream>
#include <cmath>

using namespace std;

double func(float x, int degree, int arr[]) {
	double sum = arr[0];
	for (int i = 1; i <= degree ; i++) {
		sum += static_cast<double>(arr[i]) * pow(x, i);
	}
	return sum;
}

double func_prime(float x,int degree, int arr[]) {
	double sum = arr[1];
	for (int i = 2; i <= degree; i++) {
		sum += static_cast<double>(i) * arr[i] * pow(x, i - 1);
	}
	return sum;
}

void calcualte_root(double x0, double epsilon, int nmax, int degree, int arr[]) {
	for (int n = 1; n <= nmax; n++) {
		if (func_prime(x0, degree, arr) == 0) {
			cout << "Mathematical error" << endl;
			exit(1);
		} 
		double x = x0 - func(x0, degree, arr) / func_prime(x0, degree, arr);

		//cout << n << "\t" << x0 << "\t" << x << "\t" << (x - x0) << endl;

		if (abs(x - x0) < epsilon) {
			cout << "Required root  = " << x << endl;
			exit(0);
		}
		x0 = x;
	}
	cout << "Solution did not converge" << endl;
}


int main() {
	double x0;		
	double tolerance;	
	double maxIterations = 20;	

	int degree;
	cout << "Enter degree of a polynomial equation : " << endl;
	cin >> degree;

	int* arr = new int[degree + 1];
	cout << "Enter coefficients :" << endl;
	for (int i = 0; i <= degree; i++) {
		cout << "a" << i << " = "; cin >> arr[i];
	}
	cout << "Enter tolerance : "; cin >> tolerance;
	cout << "Enter initial guess : "; cin >> x0;

	calcualte_root(x0, tolerance, maxIterations, degree, arr);

	delete[] arr;
	return 0;
}
