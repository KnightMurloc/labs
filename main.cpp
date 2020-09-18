#include <iostream>

#include "Polynomial.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<double> vec = {1.1, -2, 3};

    Polynomial polynomial(vec);

    cout << polynomial << endl;

    return 0;
}