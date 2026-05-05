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
/*
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
*/            
    };

#endif // MATRIX_H