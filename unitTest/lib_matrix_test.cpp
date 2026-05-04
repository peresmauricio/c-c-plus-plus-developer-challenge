#include <gtest/gtest.h>
#include "matrix.h"
#include "lib_matrix.h"

/// @brief Test the sum of two second order matrices.
TEST(LibMatrixTest, sumMatrix_order2)
{
    // Test the sum of two 2x2 matrices. 
    Matrix a(2, 2);
    a.at(0, 0) = 1; a.at(0, 1) = 2;
    a.at(1, 0) = 3; a.at(1, 1) = 4;

    Matrix b(2, 2);
    b.at(0, 0) = 5; b.at(0, 1) = 6;
    b.at(1, 0) = 7; b.at(1, 1) = 8;

    Matrix result = Lib_matrix::sumMatrix(a, b);

    EXPECT_DOUBLE_EQ(result.at(0, 0), 6.0);
    EXPECT_DOUBLE_EQ(result.at(0, 1), 8.0);
    EXPECT_DOUBLE_EQ(result.at(1, 0), 10.0);
    EXPECT_DOUBLE_EQ(result.at(1, 1), 12.0);
}

/// @brief Test the difference of two second order matrices.
TEST(LibMatrixTest, subtractMatrix_order2)
{
    // Test the difference of two 2x2 matrices. 
    Matrix a(2, 2);
    a.at(0, 0) = 1; a.at(0, 1) = 2;
    a.at(1, 0) = 3; a.at(1, 1) = 4;

    Matrix b(2, 2);
    b.at(0, 0) = 5; b.at(0, 1) = 6;
    b.at(1, 0) = 7; b.at(1, 1) = 8;

    Matrix result = Lib_matrix::subtractMatrix(a, b);

    EXPECT_DOUBLE_EQ(result.at(0, 0), -4.0);
    EXPECT_DOUBLE_EQ(result.at(0, 1), -4.0);
    EXPECT_DOUBLE_EQ(result.at(1, 0), -4.0);
    EXPECT_DOUBLE_EQ(result.at(1, 1), -4.0);
}

/// @brief Test the function to check triangular feature
TEST(LibMatrixTest, triangular_matrix_check)
{
    // Check lower triangular matrix
    Matrix a(2,2);
    a.at(0, 0) = 1; a.at(0, 1) = 2;
    a.at(1, 0) = 0; a.at(1, 1) = 4;

    EXPECT_EQ(true, Lib_matrix::isTriangular(a));
}

/// @brief Verify the integrit of isNull function.
TEST(LibMatrixTest, null_matrix_false_check)
{
    Matrix a(2,2);
    a.at(0, 0) = 1; a.at(0, 1) = 0;
    a.at(1, 0) = 0; a.at(1, 1) = 0;

    EXPECT_EQ(false, Lib_matrix::isNull(a));
}

/// @brief Verify the integrit of isNull function.
TEST(LibMatrixTest, null_matrix_true_check)
{
    Matrix a(2,2);
    
    a.at(0, 0) = 0; a.at(0, 1) = 0;
    a.at(1, 0) = 0; a.at(1, 1) = 0;

    EXPECT_EQ(true, Lib_matrix::isNull(a));
}