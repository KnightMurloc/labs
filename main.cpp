#include "Tests/Test2.h"
#include "Polynomial.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    operatorPlusTest();
    operatorMinusTest();
    incrementDecrementTest();
    assignmentCorrectTest();
    inCorrectIndexTest();
    correctIndexTest();
    return 0;
}
