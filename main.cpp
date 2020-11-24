#include "Polynomial.h"
#include "PolynomialQueue.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    PolynomialQueue queue;
    double arr[] = {1,2,3};
    unsigned int len = sizeof(arr) / sizeof(double);
    auto* p1 = new Polynomial(arr,len);
    auto* p2 = new Polynomial(arr,len);
    auto* p3 = new Polynomial(arr,len);
    p2->setCoefficient(5,0);
    p3->setCoefficient(10,0);
    queue.push(p1);
    queue.push(p2);
    queue.insert(p3,1);


//    queue.remove(2);
//    Polynomial* p = queue.pop();
//    cout << p1 << "\n" << p2 << endl;
    cout << queue << endl;

    return 0;
}
