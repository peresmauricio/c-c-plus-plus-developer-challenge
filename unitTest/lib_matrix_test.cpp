#include <gtest/gtest.h>
#include "matrix.h"
#include "lib_matrix.h"


TEST(LibMatrixTest, sumMatrix_order2)
{
    // Test the sum of two 2x2 matrices. 
    Matrix a(2, 2);
    a.at(0, 0) = 1; a.at(0, 1) = 2;
    a.at(1, 0) = 3; a.at(1, 1) = 4;

    Matrix b(2, 2);
    b.at(0, 0) = 5; b.at(0, 1) = 6;
    b.at(1, 0) = 7; b.at(1, 1) = 8;

    Matrix result = sumMatrix(a, b);

    EXPECT_DOUBLE_EQ(result.at(0, 0), 6.0);
    EXPECT_DOUBLE_EQ(result.at(0, 1), 8.0);
    EXPECT_DOUBLE_EQ(result.at(1, 0), 10.0);
    EXPECT_DOUBLE_EQ(result.at(1, 1), 12.0);
}