// Code to determine a real root of a non - linear equation using secant method

#include <iostream>
#include <iomanip>
#include <cmath>

double func(double x) {
	//return pow(x,3) - 3*pow(x,2) + 2*x - 2;
	return x*sin(x)+cos(x);
	//return pow(x,2)+4*x+5;
}

void secant(double a, double b, double epsilon, int NMAX) {
	for (int N = 1; N <= NMAX; N++) {
		double c = (a * func(b) - b * func(a)) / (func(b) - func(a));

		std::cout << "Iteration-" << N << ":\t a = " << std::fixed << std::setprecision(6) << a <<  " b = " << b << " c=" << c << " and f(c) = " << func(c) << std::endl;

		if (std::abs(func(c)) <= epsilon)
		{
			std::cout << "After " << N <<" iterations, root is: " << c << std::endl;
			exit(0);
		}
		a = b;
		b = c;
	}
	std::cout << "Solution did not converge" << std::endl;
}

int main() {
	double a, b;
	double tolerance;
	int maxIterations = 100;

	std::cout << "Enter interval (a, b) :";
	std::cin >> a >> b;
	std::cout << "Enter tolerance : ";
	std::cin >> tolerance;

	secant(a, b, tolerance, maxIterations);

	return 0;
}
