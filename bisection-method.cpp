// 4. Develop a simple algorithm and program code in C/C++ to find a real root of a non linear equation for a given function (hard-coded) from user input values of the interval (a, b) and error tolerance (E). 

#include <iostream>
#include <iomanip>
#include <cmath>

float func(float x) {
	//return exp(x) - 3 * x;
	return x * sin(x) + cos(x);
}

void bisection(float a, float b, float epsilon, int NMAX = 50) {
	if (func(a) * func(b) > 0) {
		std::cout << "No real root exists in given interval" << std::endl;
		exit(1);
	}

	int count = 0;
	while (++count <= NMAX) {
		float c = (a + b) / 2;

		std::cout << "Iteration-" << count << ":\t a = " << std::fixed << std::setprecision(6) << a << " b = " << b << " c=" << c << " and f(c) = " << func(c) << std::endl;

		if (fabs(func(c)) <= epsilon || fabs(b - a) <= epsilon) {
			std::cout << "Root is: " << c << std::endl;
			exit(0);
		}
		if (func(c) * func(a) > 0)
			a = c;
		else
			b = c;
	}
	std::cout << "Solution did not converge" << std::endl;
}

int main() {
	float a, b, epsilon;
	std::cout << "Enter interval (a, b) :" << std::endl;
	std::cin >> a >> b;
	std::cout << "Enter tolerance : " << std::endl;
	std::cin >> epsilon;

	bisection(a, b, epsilon);

	return 0;
}
