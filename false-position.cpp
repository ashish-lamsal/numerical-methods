// Code to determine a real root of a non - linear equation using False Position method

#include <iostream>
#include <iomanip>
#include <cmath>

double func(double x) {
	//return pow(x,3) - 3*pow(x,2) + 2*x - 2;
	return x * sin(x) + cos(x);
	//return pow(x,2)+4*x+5;
}

void false_position(double a, double b, double epsilon, int NMAX) {
	if (func(a) * func(b) >= 0) {
		std::cout << "No real root exists in given interval" << std::endl;
		exit(1);
	}
	for (int N = 1; N <= NMAX; N++) {
		double c = (a * func(b) - b * func(a)) / (func(b) - func(a));

		std::cout << "Iteration-" << N << ":\t a = " << std::fixed << std::setprecision(6) << a << " b = " << b << " c=" << c << " and f(c) = " << func(c) << std::endl;

		if (std::abs(func(c)) <= epsilon)
		{
			std::cout << "After " << N << " iterations, root is: " << c << std::endl;
			exit(0);
		}
		if (func(a) * func(c) >= 0)
			a = c;
		else
			b = c;
	}
	std::cout << "Solution did not converge" << std::endl;
}

int main() {
	double a, b;
	double tolerance;
	int maxIterations = 100;

	std::cout << "Enter interval (a, b) :" << std::endl;
	std::cin >> a >> b;
	std::cout << "Enter tolerance : " << std::endl;
	std::cin >> tolerance;

	false_position(a, b, tolerance, maxIterations);

	return 0;
}
