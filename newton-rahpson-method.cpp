// Newton-Rahpson Method
#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return exp(x) + cos(x) - 5;
    //return x * sin(x) + cos(x);
}

double func_prime(double x) {
    return exp(x) - sin(x);
    //return x * cos(x);
}

void calcualte_root(double x0, double epsilon, int nmax = 20) {
    for (int n = 1; n <= nmax; n++) {
        if (func_prime(x0) == 0) {
            cout << "Mathematical error" << endl;
            exit(1);
        }
        double x = x0 - func(x0) / func_prime(x0);

        //cout << n << "\t" << x0 << "\t" << x << "\t" << (x - x0) << endl;

        if (fabs(x - x0) < epsilon) {
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
	
    cout << "Enter initial guess : "; cin >> x0;
	cout << "Enter tolerance : "; cin >> tolerance;
    
    calcualte_root(x0, tolerance);

    return 0;
}
