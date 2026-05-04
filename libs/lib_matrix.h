
#ifndef LIB_MATRIX_H_INCLUDED
#define LIB_MATRIX_H_INCLUDED

#include "matrix.h"

class Lib_matrix
{
private:        
    Lib_matrix() = delete; // Prevent to instantiate the class.
public:
    /** @brief Function to calculate the sum of two matrices. 
     *          The sum only can be calculated if both matrices
     *          have the same order. 
     *  @param a First matrix.
     *  @param b Second matrix.
    */
    static Matrix sumMatrix(const Matrix& a, const Matrix& b);
    
    /** @brief Function to calculate the difference of two matrices. 
     *          The function subtract Matrix b from Matrix a. 
     *          The difference only can be calculated if both matrices
     *          have the same order. 
     *  @param a First matrix.
     *  @param b Second matrix.
     *  @return The difference matrix of a and b.
     */
    static Matrix subtractMatrix(const Matrix& a, const Matrix& b);

    /** @brief Function to calculate the product of two matrices. 
     *          The product only can be calculated if the number of columns
     *          of the first matrix is equal to the number of rows of the second matrix. 
     *  @param a First matrix.
     *  @param b Second matrix.
     *  @return The product matrix of a and b.
     */
    static Matrix multiplyMatrix(const Matrix& a, const Matrix& b);

    /**
     * @brief Function to verify if a matriz is a triangular matrix.
     * @param a Test matrix.
     * @return True if matrix is lower or upper triangular matrix.       
     */
    static bool isTriangular(const Matrix& a);
};      


#endif // LIB_MATRIX_H_INCLUDED