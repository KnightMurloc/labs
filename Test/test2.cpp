//
// Created by Victor on 25.10.2020.
//

#include "gtest/gtest.h"
#include "../Polynomial_lib/Polynomial.h"

class PolynomialTestOperator : public ::testing::Test {
};

TEST(PolynomialTestOperator, operatorPlusTest) {
    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        double array2[5] = {-1, 2, 5, -7, 9};
        unsigned int len2 = 5;
        Polynomial polynomial2(array2, len2);

        Polynomial p3 = polynomial + polynomial2;

        ASSERT_EQ(p3[0], 3);
        ASSERT_EQ(p3[1], 8);
        ASSERT_EQ(p3[2], 8);
        ASSERT_EQ(p3[3], 0);
        ASSERT_EQ(p3[4], 15);
    }

    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial p(array, len);

        Polynomial p3 = p + p;

        ASSERT_EQ(p3[0], 8);
        ASSERT_EQ(p3[1], 12);
        ASSERT_EQ(p3[2], 6);
        ASSERT_EQ(p3[3], 14);
        ASSERT_EQ(p3[4], 12);
    }

    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        double array2[] = {-1, 2, 5, -7, 9, 10, 15};
        unsigned int len2 = sizeof(array2) / sizeof(double);
        Polynomial polynomial2(array2, len2);
        Polynomial p3 = polynomial + polynomial2;

        ASSERT_EQ(p3[0], 3);
        ASSERT_EQ(p3[1], 8);
        ASSERT_EQ(p3[2], 8);
        ASSERT_EQ(p3[3], 0);
        ASSERT_EQ(p3[4], 15);
        ASSERT_EQ(p3[5], 10);
        ASSERT_EQ(p3[6], 15);
    }
}

TEST(PolynomialTestOperator, operatorMinusTest) {
    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        double array2[5] = {-1, 2, 5, -7, 9};
        unsigned int len2 = 5;
        Polynomial polynomial2(array2, len2);

        Polynomial p3 = polynomial - polynomial2;

        ASSERT_EQ(p3[0], 5);
        ASSERT_EQ(p3[1], 4);
        ASSERT_EQ(p3[2], -2);
        ASSERT_EQ(p3[3], 14);
        ASSERT_EQ(p3[4], -3);
    }

    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial p(array, len);

        Polynomial p3 = p - p;

        ASSERT_EQ(p3[0], 0);
        ASSERT_EQ(p3[1], 0);
        ASSERT_EQ(p3[2], 0);
        ASSERT_EQ(p3[3], 0);
        ASSERT_EQ(p3[4], 0);
    }

    {
        double array[5] = {4, 6, 3, 7, 6};
        unsigned int len = 5;
        Polynomial polynomial(array, len);

        double array2[] = {-1, 2, 5, -7, 9, 10, 15};
        unsigned int len2 = sizeof(array2) / sizeof(double);
        Polynomial polynomial2(array2, len2);
        Polynomial p3 = polynomial - polynomial2;

        ASSERT_EQ(p3[0], 5);
        ASSERT_EQ(p3[1], 4);
        ASSERT_EQ(p3[2], -2);
        ASSERT_EQ(p3[3], 14);
        ASSERT_EQ(p3[4], -3);
        ASSERT_EQ(p3[5], -10);
        ASSERT_EQ(p3[6], -15);
    }
}

TEST(PolynomialTestOperator, incrementDecrementTest) {
    {
        double array[] = {4, 6, 3};
        unsigned int len = 3;
        Polynomial p(array, len);
        Polynomial p2 = p++;

        ASSERT_EQ(p2[0], 4);
        ASSERT_EQ(p2[1], 6);
        ASSERT_EQ(p2[2], 3);

        ASSERT_EQ(p[0], 4);
        ASSERT_EQ(p[1], 6);
        ASSERT_EQ(p[2], 3);
        ASSERT_EQ(p[3], 0);
    }

    {
        double array[] = {4, 6, 3};
        unsigned int len = 3;
        Polynomial p(array, len);
        Polynomial p2 = ++p;

        ASSERT_EQ(p2[0], 4);
        ASSERT_EQ(p2[1], 6);
        ASSERT_EQ(p2[2], 3);
        ASSERT_EQ(p2[3], 0);

        ASSERT_EQ(p[0], 4);
        ASSERT_EQ(p[1], 6);
        ASSERT_EQ(p[2], 3);
        ASSERT_EQ(p[3], 0);
    }

    {
        double array[] = {4, 6, 3};
        unsigned int len = 3;
        Polynomial p(array, len);
        Polynomial p2 = p--;

        ASSERT_EQ(p2[0], 4);
        ASSERT_EQ(p2[1], 6);
        ASSERT_EQ(p2[2], 3);
        try {
            p[2];
            FAIL() << "should be Exception: \"Out of Range Array\"";
        } catch (PolynomialException &e) {
            EXPECT_EQ(e.what(), std::string("Out of Range Array"));
        }
    }

    {
        double array[] = {4, 6, 3};
        unsigned int len = 3;
        Polynomial p(array, len);
        Polynomial p2 = --p;

        try {
            p2[2];
            FAIL() << "should be Exception: \"Out of Range Array\"";
        } catch (PolynomialException &e) {
            EXPECT_EQ(e.what(), std::string("Out of Range Array"));
        }

        try {
            p[2];
            FAIL() << "should be Exception: \"Out of Range Array\"";
        } catch (PolynomialException &e) {
            EXPECT_EQ(e.what(), std::string("Out of Range Array"));
        }
    }
}

TEST(PolynomialTestOperator, correctIndexTest) {
    double array[3] = {4, 6, 3};
    unsigned int len = 3;
    Polynomial p(array, len);

    ASSERT_EQ(p[0], 4);
    ASSERT_EQ(p[1], 6);
    ASSERT_EQ(p[2], 3);
}

TEST(PolynomialTestOperator, inCorrectIndexTest) {
    double array[3] = {4, 6, 3};
    unsigned int len = 3;
    Polynomial p(array, len);

    try {
        p[3];
        FAIL() << "should be Exception: \"Out of Range Array\"";
    } catch (PolynomialException &e) {
        EXPECT_EQ(e.what(), std::string("Out of Range Array"));
    }

}

TEST(PolynomialTestOperator, assignmentCorrectTest) {
    double array[] = {4, 6, 3};
    unsigned int len = 3;
    Polynomial p(array, len);
    p = "1+2x^1+3x^5";
    for (int i = 0; i < p.getOrder(); ++i) {
        printf("%lf ",p[i]);
    }
    printf("\n");
    ASSERT_EQ(p[0], 1);
    ASSERT_EQ(p[1], 2);
    ASSERT_EQ(p[2], 0);
    ASSERT_EQ(p[3], 0);
    ASSERT_EQ(p[4], 0);
    ASSERT_EQ(p[5], 3);

}

//int main() {
//    testing::InitGoogleTest();
//    return RUN_ALL_TESTS();
//}