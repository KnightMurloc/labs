//
// Created by Victor on 25.10.2020.
//

#include "gtest/gtest.h"
#include "../Polynomial_lib/Polynomial.h"


class PolynomialTestBase : public ::testing::Test {
};

TEST(PolynomialTest, CreateCorrectTest) {
    double array[5] = {4, 6, 3, 7, 6};
    unsigned int len = 5;
    Polynomial p(array, len);

    ASSERT_EQ(p.getCoefficient(0), 4);
    ASSERT_EQ(p.getCoefficient(1), 6);
    ASSERT_EQ(p.getCoefficient(2), 3);
    ASSERT_EQ(p.getCoefficient(3), 7);
    ASSERT_EQ(p.getCoefficient(4), 6);
}

TEST(PolynomialTestBase, createIncorrectTest) {
    {
        try {
            double* array = nullptr;
            unsigned int len = 3;
            Polynomial polynomial(array, len);
            FAIL() << "should be Exception: \"coefficients is null\"";
        } catch (PolynomialException &e) {
            EXPECT_EQ(e.what(), std::string("coefficients is null"));
        }
    }

    {
        try {
            auto* array = new double[4];
            unsigned int len = 0;
            Polynomial polynomial(array, len);
            FAIL() << "should be Exception: \"coefficients is empty\"";
        } catch (PolynomialException &e) {
            EXPECT_EQ(e.what(), std::string("coefficients is empty"));
        }
    }
}

TEST(PolynomialTestBase, getValueTest) {
    double array[] = {2, 5, 7};
    unsigned int len = 3;
    Polynomial p(array, len);

    ASSERT_EQ(p.getValue(2), 40);
}

TEST(PolynomialTestBase, getIncorrectCoefficientTest) {
    try {
        double array[] = {2, 5, 7};
        unsigned int len = 3;
        Polynomial polynomial(array, len);
        polynomial.getCoefficient(100);
        FAIL() << "should be Exception: \"Out of Range Array\"";;
    } catch (PolynomialException &e) {
        EXPECT_EQ(e.what(), std::string("Out of Range Array"));
    }
}

TEST(PolynomialTestBase, setCorrectCoefficientTest) {
    double array[] = {2, 5, 7};
    unsigned int len = 3;
    Polynomial p(array, len);
    p.setCoefficient(10, 0);
    p.setCoefficient(16, 1);
    p.setCoefficient(17, 2);
    ASSERT_EQ(p.getCoefficient(0), 10);
    ASSERT_EQ(p.getCoefficient(1), 16);
    ASSERT_EQ(p.getCoefficient(2), 17);
}

TEST(PolynomialTestBase, setIncorrectCoefficientTest) {
    double array[] = {2, 5, 7};
    unsigned int len = 3;
    Polynomial polynomial(array, len);
    try {
        polynomial.setCoefficient(10, 200);
        FAIL() << "should be Exception: \"Out of Range Array\"";
    } catch (PolynomialException &e) {
        EXPECT_EQ(e.what(), std::string("Out of Range Array"));
    }
}

TEST(PolynomialTestBase, toStringTest) {
    double array[] = {2, -5, 7.654};
    unsigned int len = 3;
    Polynomial p(array, len);

    ASSERT_EQ(p.toString(), std::string("2-5x^1+7.654x^2"));
}

//int main(){
//
//    return RUN_ALL_TESTS();
//}