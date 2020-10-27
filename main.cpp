#include "Polynomial.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
//    ifstream stream("1.txt");
//    {
//        double array[] = {1,2,3};
//        unsigned int len = sizeof(array) / sizeof(double);
//        Polynomial p(array,len);
//
//        stream << p;
//    }
//
//    {
//        double array[] = {3,2,1};
//        unsigned int len = sizeof(array) / sizeof(double);
//        Polynomial p(array,len);
//
//        stream << p;
//    }
//
//    stream.flush();
//    stream.close();

//    {
//        Polynomial p;
//
//        stream >> p;
//
//        cout << p << endl;
//    }
//
//    {
//        Polynomial p;
//
//        stream >> p;
//
//        cout << p[2] << endl;
//    }

//    {
//        Polynomial p;
//        p = "3+2x^1+1x^2";
//        cout << p[2] << endl;
//    }

//    stream.close();

    stringstream stream("1+2x^1+3x^2 3+2x^1+1x^2");

    {
        Polynomial p;

        stream >> p;

        cout << p << endl;
    }

    {
        Polynomial p;

        stream >> p;

        cout << p << endl;
    }

    return 0;
}
