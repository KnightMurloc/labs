//
// Created by Victor on 10.11.2020.
//
#include "gtest/gtest.h"
#include "../Polynomial_lib/Polynomial.h"
#include "../Polynomial_lib/PolynomialString.h"

class PolynomialStringTest : public testing::Test{};

TEST(PolynomialStringTest,CreateTest){
    PolynomialString p = "1+2x^1+4x^5";
    ASSERT_EQ(p.toString(),std::string("1+2x^1+4x^5"));

    ASSERT_EQ(p[0],1);
    ASSERT_EQ(p[1],2);
    ASSERT_EQ(p[2],0);
    ASSERT_EQ(p[3],0);
    ASSERT_EQ(p[4],0);
    ASSERT_EQ(p[5],4);
}

TEST(PolynomialStringTest,CreateTest2){
    double arr[] = {1,2,3};
    unsigned int len = 3;
    PolynomialString p(arr,len);

    ASSERT_EQ(p.toString(),std::string("1+2x^1+3x^2"));

    ASSERT_EQ(p[0],1);
    ASSERT_EQ(p[1],2);
    ASSERT_EQ(p[2],3);
}

TEST(PolynomialStringTest,IncDecTest){
    {
        PolynomialString p = "1+2x^1+3x^2";
        PolynomialString p2 = p++;


        ASSERT_EQ(p2[0],1);
        ASSERT_EQ(p2[1],2);
        ASSERT_EQ(p2[2],3);

        ASSERT_EQ(p[0],1);
        ASSERT_EQ(p[1],2);
        ASSERT_EQ(p[2],3);
        ASSERT_EQ(p[3],0);
    }

    {
        PolynomialString p = "1+2x^1+3x^2";
        PolynomialString p2 = ++p;


        ASSERT_EQ(p2[0],1);
        ASSERT_EQ(p2[1],2);
        ASSERT_EQ(p2[2],3);
        ASSERT_EQ(p2[3],0);

        ASSERT_EQ(p[0],1);
        ASSERT_EQ(p[1],2);
        ASSERT_EQ(p[2],3);
        ASSERT_EQ(p[3],0);
    }

    {
        PolynomialString p = "1+2x^1+3x^2";
        PolynomialString p2 = p--;

        ASSERT_EQ(p2[0],1);
        ASSERT_EQ(p2[1],2);
        ASSERT_EQ(p2[2],3);

        ASSERT_EQ(p[0],1);
        ASSERT_EQ(p[1],2);
        try {
            ASSERT_EQ(p[2],3);
            FAIL() << "should be Exception: \"Out of Range Array\"\n";
        }catch(PolynomialException& e){
            EXPECT_EQ(e.what(), std::string("Out of Range Array"));
        }
    }

    {
        PolynomialString p = "1+2x^1+3x^2";
        PolynomialString p2 = --p;

        ASSERT_EQ(p2[0],1);
        ASSERT_EQ(p2[1],2);

        ASSERT_EQ(p[0],1);
        ASSERT_EQ(p[1],2);

        try {
            ASSERT_EQ(p[2],3);
            ASSERT_EQ(p2[2],3);
            FAIL() << "should be Exception: \"Out of Range Array\"\n";
        }catch(PolynomialException& e){
            EXPECT_EQ(e.what(), std::string("Out of Range Array"));
        }
    }
}

TEST(PolynomialStringTest,SetTest){
    PolynomialString p = "1+2x^1+4x^2";
    p.setCoefficient(5,1);
    ASSERT_EQ(p.toString(),std::string("1+5x^1+4x^2"));

    ASSERT_EQ(p[0],1);
    ASSERT_EQ(p[1],5);
    ASSERT_EQ(p[2],4);
}

//int main() {
//    testing::InitGoogleTest();
//    return RUN_ALL_TESTS();
//}