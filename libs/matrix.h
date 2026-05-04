#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

    class Matrix {
    private:
        std::vector<std::vector<double>> data;
        size_t rows, cols;

    public:
        Matrix(size_t r, size_t c);
        Matrix(const std::vector<std::vector<double>>& d);
        ~Matrix();

        size_t getRows() const;
        size_t getCols() const;

        double& at(size_t i, size_t j);
        const double& at(size_t i, size_t j) const;

        Matrix operator+(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
   
        void setValue(size_t row, size_t col, double value);
        double getValue(size_t row, size_t col) const;
        // Check if the matrix is square.
        bool isSquare() const {
            return rows == cols;
        }

        // Check if the square matrix is upper or lower triangular.    
        bool isTriangular() const {
            if (!isSquare()) return false;
            bool upper = true, lower = true;
            for (size_t i = 0; i < this->rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    if(i == j) continue; // Skip diagonal
                    if (data[i][j] != 0.0) {
                        // Check all upper triangular elements of matrix   
                        if (i < j) lower = false;
                        // Check all lower triangular elements of matrix   
                        if (i > j) upper = false; 
                    }
                }
            }
            return upper || lower;
        }
        // Only apply Gaussian if the pivot value is differente of zero, otherwise, the determinant is zero.
        double aplayGaussElimination(size_t pivotRow, size_t pivotCol) {
            double pivotValue = data[pivotRow][pivotCol];
            
            for (size_t i = pivotRow + 1; i < rows; ++i) {
                double factor = data[i][pivotCol] / pivotValue;
                for (size_t j = pivotCol; j < cols; ++j) {
                    data[i][j] -= factor * data[pivotRow][j];
                }
            }
            return pivotValue;
        }
        // Check if the matrix is a null matrix.
        bool isNull() const {
            for (size_t i = 0; i < rows; ++i) {
                for (size_t j = 0; j < cols; ++j) {
                    if (data[i][j] != 0.0) {
                        return false;
                    }
                }
            }
            return true;
        }

        double primaryDiagonalProduct(size_t pivotRow, size_t pivotCol) const {
            double product = 1.0;
            size_t i = pivotRow; 
            size_t j = pivotCol;
            std:: cout << "Primary diagonal: ";
            for (;((i < rows) && (j < cols)); i++, j++) {
                std::cout << data[i][j] << "*"; 
                product *= data[i][j];
            }
            // If not the main diagonal product, the rows ends without to reach the 
            // limit of the rows matrix.
            if(i != rows){
                product *= primaryDiagonalProduct(i,0);
            }

            return product;
        }

        double secondaryDiagonalProduct(size_t pivotRow, size_t pivotCol) const {
            double product = 1.0;
            double i = pivotRow; 
            double j = pivotCol;
            
            for (;((j < cols) && (i >= 0)); j++,i--) {
                std::cout << data[i][j] << "*"; 
                product *= data[i][j];
            }
            // If not reachs the limit of line means that it is a   
            // parcial product of the seconday diagonal.
            if(i >= 0){
                std::cout <<  " ===>"; 
                product *= secondaryDiagonalProduct(i,0);
            }

            return product;
        }

        // Determinant calculation based in Leibniz formule  
        double determinant() const {
            if (!isSquare()) {
                throw std::invalid_argument("Determinant is only defined for square matrices");
            }
            // Check if the matris is a null matrix, if so, the determinant is 0.0
            if (isNull()) {
                return 0.0;
            }

            if(isTriangular()){
                double det = 1.0;
                // If is a triangular matrix, the determinant is th product of the main diagonal  
                for (size_t i = 0; i < rows; i++) {
                    det *= data[i][i];
                }
                return det;
            }  
/*           
            for (size_t pivot = 0; pivot < rows - 1; pivot++) {
                // check if is possible to apply Gaussian elimination.
                if (data[pivot][pivot] == 0.0) {
                    continue; // Skip. Not possible to apply Gaussian elimination.
                //throw std::runtime_error("Pivot value is zero, cannot apply Gaussian elimination");
                }
                aplayGaussElimination(pivot, pivot);
            }
*/ 
            if((rows == 2) && (cols == 2)){
                return data[0][0] * data[1][1] - data[0][1] * data[1][0];
            } 
            else if((rows == 3) && (cols == 3))
            {
                // Regra de Sarrus for 3x3 matrices.
                // primary diaonal product  
                double det = 0.0;
                
                for (size_t j = 0; j < (cols); j++) {
                    det += primaryDiagonalProduct(0,j);
                }
                for(size_t j = 0, i = rows-1; j < (cols); j++) {
                    det -= secondaryDiagonalProduct(i,j);
                }

                return det;
            }else{
                return determinantLaplaceExpansion();
            }
            
        }

        double determinantLaplaceExpansion() const {
            if (!isSquare()) {
                throw std::invalid_argument("Determinant is only defined for square matrices");
            }
            // Check if the matris is a null matrix, if so, the determinant is 0.0
            if (isNull()) {
                return 0.0;
            }

            if(isTriangular()){
                double det = 1.0;
                // If is a triangular matrix, the determinant is th product of the main diagonal  
                for (size_t i = 0; i < rows; i++) {
                    det *= data[i][i];
                }
                return det;
            }  
            // if the matrix is 1x1, the determinant is the single value of the matrix.
            if((rows ==1) && (cols == 1)){
                return data[0][0];
            }
            else if((rows == 2) && (cols == 2)){
                return data[0][0] * data[1][1] - data[0][1] * data[1][0];
            } 
            else if((rows == 3) && (cols == 3))
            {
                // Regra de Sarrus for 3x3 matrices.
                // primary diaonal product  
                double det = 0.0;
                
                for (size_t j = 0; j < (cols); j++) {
                    det += primaryDiagonalProduct(0,j);
                }
                for(size_t j = 0, i = rows-1; j < (cols); j++) {
                    det -= secondaryDiagonalProduct(i,j);
                }

                return det;
            }
            else{
                double det = 0.0;
                for (size_t j = 0; j < cols; ++j) {
                    // Create submatrix for cofactor expansion
                    std::vector<std::vector<double>> submatrix(rows - 1, std::vector<double>(cols - 1));
                    // Select the first row and the j-th column to create the submatrix
                    for (size_t i = 1; i < rows; ++i) {
                        for (size_t k = 0; k < cols; ++k) {
                            if (k < j) {
                                submatrix[i - 1][k] = data[i][k];
                            } else if (k > j) {
                                submatrix[i - 1][k - 1] = data[i][k];
                            }
                        }
                    }
                    // Recursive call for determinant of submatrix
                    det += (j % 2 == 0 ? 1 : -1) * data[0][j] * Matrix(submatrix).determinantLaplaceExpansion();
                }
                return det;
            }
        }     
    };

#endif // MATRIX_H