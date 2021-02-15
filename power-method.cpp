#include <iostream>
#include <cmath>
using namespace std;

class PowerMethod {
private:
    float** matrix;
    float* EigenVector;
    float* temp;
    float* error;

    int N;
    float lambda;

    float tolerance;
    int threshold;
    int count;

public:
    PowerMethod() : lambda(0), tolerance(0.0005), threshold(100), count(0) {
        getorder();

        matrix = new float* [N];
        for (int i = 0; i < N; i++) {
            matrix[i] = new float[N];
        }

        readdata();

        // initial guess to the Eigen vector
        EigenVector = new float[N];
        for (int i = 0; i < N; i++)
            EigenVector[i] = 1;

        temp = new float[N];
        error = new float[N];
    }

    ~PowerMethod() {
        for (int i = 0; i < N; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] EigenVector;

        delete[] temp;
        delete[] error;
    }

    void getorder() {
        cout << "Enter order of square matrix :";
        cin >> N;
    }

    void readdata() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << "a(" << i + 1 << "," << j + 1 << ")" << " = ";
                cin >> matrix[i][j];
            }
        }

        // matrix[0][0] = 2;
        // matrix[0][1] = 3;
        // matrix[0][2] = 2;
        // matrix[1][0] = 3;
        // matrix[1][1] = 4;
        // matrix[1][2] = 1;
        // matrix[2][0] = 2;
        // matrix[2][1] = 1;
        // matrix[2][2] = 7;
    }

    float get_largest_element(float* arr) {
        float largest = fabs(arr[0]);
        for (int i = 0; i < N;i++) {
            if (largest < fabs(arr[i]))
                largest = arr[i];
        }
        return largest;
    }

    void product() {
        for (int i = 0; i < N; i++) {
            temp[i] = 0;
            for (int j = 0; j < N; j++) {
                temp[i] += matrix[i][j] * EigenVector[j];
            }
        }
    }

    void normalize() {
        float normal = 0;
        for (int i = 0; i < N;i++) {
            normal += pow(EigenVector[i], 2);
        }

        for (int i = 0; i < N;i++) {
            EigenVector[i] /= sqrt(normal);
        }
    }

    void solve() {
        while (true) {
            if (++count > threshold) {
                cout << "Error : Unable to Compute";
                exit(0);
            }

            // product of given matrix and Eigen Vector 
            product();

            lambda = get_largest_element(temp);
            for (int i = 0; i < N; i++) {

                // scaling
                temp[i] /= lambda;

                // error calculation
                error[i] = fabs(temp[i] - EigenVector[i]);

                // updating Eigen Vector
                EigenVector[i] = temp[i];
            }

            // largest error must be less than tolerance
            float dmax = get_largest_element(error);
            if (dmax < tolerance) {
                break;
            }
        }

        // normalize the Eigen Vector
        normalize();
    }

    void result() {
        cout << "Dominant Eigen Value : " << lambda << endl;
        cout << "Corresponging Eigen Vector : \n";
        for (int i = 0; i < N; i++)
            cout << EigenVector[i] << endl;
    }
};

int main() {
    PowerMethod p;
    p.solve();
    p.result();
    return 0;
}