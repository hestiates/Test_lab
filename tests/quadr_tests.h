#ifndef QUADR_H
#define QUADR_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>

extern "C" {
#include "myfunc.h"
}

float x1, x2;
int flag;

TEST(root, num1)
{
    quadr(2, -6, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(2, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

TEST(root, num2)
{
    quadr(1, -4, 3, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(3, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

TEST(pointroots, num1)
{
    quadr(2, -9, 7, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(3.5, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

TEST(pointroots, num2)
{
    quadr(2, 3, 1, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.5, x1);
    ASSERT_FLOAT_EQ(-1, x2);
    ASSERT_EQ(0, flag);
}

TEST(zero_dis, num1)
{
    quadr(2, 4, 2, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-1, x1);
    ASSERT_FLOAT_EQ(-1, x2);
    ASSERT_EQ(0, flag);
}

TEST(zero_dis, num2)
{
    quadr(4.5, 6 , 2, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.66666669, x1);
    ASSERT_FLOAT_EQ(-0.66666669, x2);
    ASSERT_EQ(0, flag);
}

TEST(noroots, num1)
{
    quadr(2, 6, 14, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

TEST(noroots, num2)
{
    quadr(-10, -13, -25, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

TEST(zero_coeff, num1)
{
    quadr(0, 0, 0, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

#endif // QUADR_H
