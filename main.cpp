#include "Tests/test.h"
#include "Polynomial.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    double array[] = {1, 2, 3};
    unsigned int len = sizeof(array) / sizeof(double);

    Polynomial p(array, len);

    cout << p.toString() << endl;
    try {
        p = "3x^1+4x^2+10.5-5";
    } catch (PolynomialException &e) {
        cout << e.what();
        return 0;
    }
    cout << p.toString() << endl;
    return 0;
}
