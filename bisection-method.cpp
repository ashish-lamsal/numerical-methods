// 4. Develop a simple algorithm and program code in C/C++ to find a real root of a non linear equation for a given function (hard-coded) from user input values of the interval (a, b) and error tolerance (E). 

#include <iostream>
#include <iomanip>
#include <cmath>

float func(float x) {
	//return pow(x,3) -7;
	return x * sin(x) + cos(x);
}

bool sign(float value) {
	return value >= 0;
}

void bisection(float a, float b, float epsilon) {
	const int NMAX = 1000;
	int N = 1;
	if (sign(func(a)) == sign(func(b))) {
		std::cout << "No real root exists in given interval" << std::endl;
		exit(1);
	}
	while (N <= NMAX) {
		float c = (a + b) / 2;

		std::cout << "Iteration-" << N << ":\t a = " << std::fixed << std::setprecision(6) << a <<  " b = " << b << " c=" << c << " and f(c) = " << func(c) << std::endl;

		if (fabs(func(c)) <= epsilon || fabs(b-a) <= epsilon)
		{
			std::cout << "Root is: " << c << std::endl;
			exit(1);
		}
		N = N + 1;
		if (sign(func(c)) == sign(func(a))) 
			a = c;
		else 
			b = c;
	}
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
