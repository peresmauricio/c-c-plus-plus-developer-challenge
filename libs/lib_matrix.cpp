#include "matrix.h"
#include "lib_matrix.h"


static Matrix sumMatrix(const Matrix &a, const Matrix &b){
    return a + b;
}    

static Matrix subtractMatrix(const Matrix &a, const Matrix &b){
    return a - b;
}

static Matrix multiplyMatrix(const Matrix& a, const Matrix& b){
    return a * b;
}



