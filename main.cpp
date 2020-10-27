#include "Polynomial.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
//    double array[] = {1,2,5};
//    unsigned int len = sizeof(array) / sizeof(double);
//    Polynomial p(array,len);
//
//    fstream stream("1.txt");
//
//    stream >> p;
//    cout << p.toString() << endl;
////    stream.flush();
//    stream.close();
////
//////    p = "2x^1+3x^2";
////
////    stringstream stream("2x^1+3x^2");
////
////    stream >> p;
////
////    cout << p.toString() << endl;

//    double array[] = {0,2,3};
//    unsigned int len = sizeof(array) / sizeof(double);
//    Polynomial p(array, len);
//
//    std::ifstream stream("test3_1.txt");
//
//    try {
//        stream >> p;
//    }catch(PolynomialException& e){
//        cout << e.what() << endl;
//    }

//    REQUIRE(std::string("1+2x^1+3x^2") == p.toString());

    double array[] = {1, 2, 3};
    unsigned int len = sizeof(array) / sizeof(double);
    Polynomial p(array, len);

    std::ofstream stream("test3_1.bin", std::ios::binary);
    stream.flags((ios_base::fmtflags) ios::binary);
    printf("%d\n", stream.flags());
    if (stream.flags() & ios::binary) {
        printf("test\n");
    }

    stream << p;
    stream.flush();
    stream.close();

    return 0;
}
