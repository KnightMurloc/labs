#include "Polynomial.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<double> v1 = {1, 2, 3};

    Polynomial p1(v1);
    Polynomial p2(v1);
    Polynomial p3 = p1--;

    cout << p3[1] << endl;

    return 0;
}