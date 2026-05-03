#ifndef PROMPT_HMI_H_INCLUDED
#define PROMPT_HMI_H_INCLUDED

#include "matrix.h"

enum class OperationType {
    INVALID = 0,
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    DETERMINANT
};


OperationType getOperationChoice();
void displayMenu();
void printMatrix(const Matrix &matrix);    


#endif // PROMPT_HMI_H_INCLUDED

