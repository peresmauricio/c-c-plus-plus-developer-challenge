#include "matrix.h"
#include "lib_matrix.h"


Matrix Lib_matrix::sumMatrix(const Matrix &a, const Matrix &b){
    return a + b;
}    

Matrix Lib_matrix::subtractMatrix(const Matrix &a, const Matrix &b){
    return a - b;
}

Matrix Lib_matrix::multiplyMatrix(const Matrix& a, const Matrix& b){
    return a * b;
}

// Check if the square matrix is upper or lower triangular.    
bool Lib_matrix::isTriangular(const Matrix& a) {
    if (!a.isSquare()) return false;
    bool upper = true, lower = true;
    for (size_t i = 0; i < a.getRows(); ++i) {
        for (size_t j = 0; j < a.getCols(); ++j) {
            if(i == j) continue; // Skip diagonal
            if (a.getValue(i,j) != 0.0) {
                // Check all upper triangular elements of matrix   
                if (i < j) lower = false;
                // Check all lower triangular elements of matrix   
                if (i > j) upper = false; 
            }
        }
    }
    return upper || lower;
}

