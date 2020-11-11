//
// Created by Victor on 10.11.2020.
//

#include "gtest/gtest.h"
#include "../Polynomial_lib/Polynomial.h"
#include "../Polynomial_lib/PolynomialExp.h"

class PolynomialExpTest : public testing::Test {};

TEST(PolynomialExpTest, CreatePolynomialExp){
    double arr[] = {1,2,3};
    int exps[] = {1,2,3};
    unsigned int len = 3;
    PolynomialExp p(arr,exps,len);

    ASSERT_EQ(p[0],1);
    ASSERT_EQ(p[1],2);
    ASSERT_EQ(p[2],3);

    ASSERT_EQ(p.getExp(0),1);
    ASSERT_EQ(p.getExp(1),2);
    ASSERT_EQ(p.getExp(2),3);

    ASSERT_EQ(p.toString(),std::string("1+2^2x^1+3^3x^2"));
}

TEST(PolynomialExpTest,GetValueTest){
    double arr[] = {1,2,3};
    int exps[] = {1,2,3};
    unsigned int len = 3;
    PolynomialExp p(arr,exps,len);

    ASSERT_EQ(p(1),32);
}

TEST(PolynomialExpTest,SetTest){
    double arr[] = {1,2,3};
    int exps[] = {1,2,3};
    unsigned int len = 3;
    PolynomialExp p(arr,exps,len);
    
    p.setExp(0,0);
    p.setExp(1,1);
    p.setExp(2,2);
    
    ASSERT_EQ(p.getExp(0),0);
    ASSERT_EQ(p.getExp(1),1);
    ASSERT_EQ(p.getExp(2),2);
}

TEST(PolynomialExpTest, IncDecTest){
    {
        double arr[] = {1,2,3};
        int exps[] = {1,2,3};
        unsigned int len = 3;
        PolynomialExp p(arr,exps,len);

        PolynomialExp p2 = p++;

        ASSERT_EQ(p2[0],1);
        ASSERT_EQ(p2[1],2);
        ASSERT_EQ(p2[2],3);

        ASSERT_EQ(p2.getExp(0),1);
        ASSERT_EQ(p2.getExp(1),2);
        ASSERT_EQ(p2.getExp(2),3);

        ASSERT_EQ(p[0],1);
        ASSERT_EQ(p[1],2);
        ASSERT_EQ(p[2],3);
        ASSERT_EQ(p[3],0);

        ASSERT_EQ(p.getExp(0),1);
        ASSERT_EQ(p.getExp(1),2);
        ASSERT_EQ(p.getExp(2),3);
        ASSERT_EQ(p.getExp(3),1);
    }

    {
        double arr[] = {1,2,3};
        int exps[] = {1,2,3};
        unsigned int len = 3;
        PolynomialExp p(arr,exps,len);

        PolynomialExp p2 = p--;

        ASSERT_EQ(p2[0],1);
        ASSERT_EQ(p2[1],2);
        ASSERT_EQ(p2[2],3);

        ASSERT_EQ(p2.getExp(0),1);
        ASSERT_EQ(p2.getExp(1),2);
        ASSERT_EQ(p2.getExp(2),3);

        ASSERT_EQ(p[0],1);
        ASSERT_EQ(p[1],2);

        ASSERT_EQ(p.getExp(0),1);
        ASSERT_EQ(p.getExp(1),2);

        try {
            ASSERT_EQ(p[2],3);
            ASSERT_EQ(p.getExp(2),3);
            FAIL() << "should be Exception: \"Out of Range Array\"\n";
        }catch(PolynomialException& e){
            EXPECT_EQ(e.what(), std::string("Out of Range Array"));
        }

    }

    {
        double arr[] = {1,2,3};
        int exps[] = {1,2,3};
        unsigned int len = 3;
        PolynomialExp p(arr,exps,len);

        PolynomialExp p2 = ++p;

        ASSERT_EQ(p2[0],1);
        ASSERT_EQ(p2[1],2);
        ASSERT_EQ(p2[2],3);
        ASSERT_EQ(p2[3],0);

        ASSERT_EQ(p2.getExp(0),1);
        ASSERT_EQ(p2.getExp(1),2);
        ASSERT_EQ(p2.getExp(2),3);
        ASSERT_EQ(p2.getExp(3),1);

        ASSERT_EQ(p[0],1);
        ASSERT_EQ(p[1],2);
        ASSERT_EQ(p[2],3);
        ASSERT_EQ(p[3],0);

        ASSERT_EQ(p.getExp(0),1);
        ASSERT_EQ(p.getExp(1),2);
        ASSERT_EQ(p.getExp(2),3);
        ASSERT_EQ(p.getExp(3),1);
    }

    {
        double arr[] = {1,2,3};
        int exps[] = {1,2,3};
        unsigned int len = 3;
        PolynomialExp p(arr,exps,len);

        PolynomialExp p2 = --p;

        ASSERT_EQ(p[0],1);
        ASSERT_EQ(p[1],2);
        ASSERT_EQ(p.getExp(0),1);
        ASSERT_EQ(p.getExp(1),2);

        try {
            ASSERT_EQ(p[2],3);
            ASSERT_EQ(p.getExp(2),3);
            FAIL() << "should be Exception: \"Out of Range Array\"\n";
        }catch(PolynomialException& e){
            EXPECT_EQ(e.what(), std::string("Out of Range Array"));
        }

    }
}

TEST(PolynomialExpTest,PlusMinuxTest){
    {
        double arr[] = {1,2,3};
        int len = 3;
        Polynomial p(arr,len);

        int exps[] = {1,2,3};
        PolynomialExp p2(arr,exps,len);

        Polynomial p3 = p + p2;

        ASSERT_EQ(p3[0],2);
        ASSERT_EQ(p3[1],6);
        ASSERT_EQ(p3[2],30);
    }

    {
        double arr[] = {1,2,3};
        int len = 3;
        Polynomial p(arr,len);

        int exps[] = {1,2,3};
        PolynomialExp p2(arr,exps,len);

        Polynomial p3 = p2 + p;

        ASSERT_EQ(p3[0],2);
        ASSERT_EQ(p3[1],6);
        ASSERT_EQ(p3[2],30);
    }

    {
        double arr[] = {1,2,3};
        int len = 3;
        Polynomial p(arr,len);

        int exps[] = {1,2,3};
        PolynomialExp p2(arr,exps,len);

        Polynomial p3 = p2 + p2;

        ASSERT_EQ(p3[0],2);
        ASSERT_EQ(p3[1],8);
        ASSERT_EQ(p3[2],54);
    }
    {
        double arr[] = {1,2,3};
        int len = 3;
        Polynomial p(arr,len);

        int exps[] = {1,2,3};
        PolynomialExp p2(arr,exps,len);

        Polynomial p3 = p - p2;

        ASSERT_EQ(p3[0],0);
        ASSERT_EQ(p3[1],-2);
        ASSERT_EQ(p3[2],-24);
    }

    {
        double arr[] = {1,2,3};
        int len = 3;
        Polynomial p(arr,len);

        int exps[] = {1,2,3};
        PolynomialExp p2(arr,exps,len);

        Polynomial p3 = p2 - p;

        ASSERT_EQ(p3[0],0);
        ASSERT_EQ(p3[1],2);
        ASSERT_EQ(p3[2],24);
    }

    {
        double arr[] = {1,2,3};
        int len = 3;
        Polynomial p(arr,len);

        int exps[] = {1,2,3};
        PolynomialExp p2(arr,exps,len);

        Polynomial p3 = p2 - p2;

        ASSERT_EQ(p3[0],0);
        ASSERT_EQ(p3[1],0);
        ASSERT_EQ(p3[2],0);
    }
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}