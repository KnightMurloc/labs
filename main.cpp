#include "Tests/test.h"
#include "Polynomial.h"
#include <vector>

using namespace std;

int main() {
    createCorrectTest();
    createIncorrectTest();
    getValueTest();
    getIncorrectCoefficientTest();
    setCorrectCoefficientTest();

    toStringTest();
    return 0;
}
