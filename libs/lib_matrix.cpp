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

// Check if the matrix is a null matrix.
bool Lib_matrix::isNull(const Matrix& a) {
    for (size_t i = 0; i < a.getRows(); ++i) {
        for (size_t j = 0; j < a.getCols(); ++j) {
            if (a.getValue(i,j) != 0.0) {
                return false;
            }
        }
    }
    return true;
}

double Lib_matrix::primaryDiagonalProduct(const Matrix& a, size_t pivotRow, size_t pivotCol) {
    double product = 1.0;
    size_t i = pivotRow; 
    size_t j = pivotCol;
    std:: cout << "Primary diagonal: ";
    for (;((i < a.getRows()) && (j < a.getCols())); i++, j++) {
        std::cout << a.getValue(i,j) << "*"; 
        product *= a.getValue(i,j);
    }
    // If not the main diagonal product, the rows ends without to reach the 
    // limit of the rows matrix.
    if(i != a.getRows()){
        product *= primaryDiagonalProduct(a,i,0);
    }

    return product;
}

double Lib_matrix::secondaryDiagonalProduct(const Matrix& a, size_t pivotRow, size_t pivotCol) {
    double product = 1.0;
    double i = pivotRow; 
    double j = pivotCol;
    
    for (;((j < a.getCols()) && (i >= 0)); j++,i--) {
        std::cout << a.getValue(i,j) << "*"; 
        product *= a.getValue(i,j);
    }
    // If not reachs the limit of line means that it is a   
    // parcial product of the seconday diagonal.
    if(i >= 0){
        std::cout <<  " ===>"; 
        product *= secondaryDiagonalProduct(a,i,0);
    }

    return product;
}