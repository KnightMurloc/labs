#include "Polynomial.h"
#include "PolynomialString.h"
#include "PolynomialExp.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    double coef[] = {1,2,3};
    int exp[] = {1,2,3};
    unsigned int len = 3;
    PolynomialExp p(coef,exp,len);
    PolynomialExp p2(coef,exp,len);


    cout << *p3 << endl;

    return 0;
}
