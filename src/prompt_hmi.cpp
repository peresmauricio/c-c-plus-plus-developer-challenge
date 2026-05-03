#include "prompt_hmi.h"
#include "matrix.h"


void displayMenu() {
    std::cout << "\n--- Dynamox Calculator ---\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Determinant of a matrix\n";
    std::cout << "0. Exit\n";
}

OperationType getOperationChoice() {
    int choice;
    std::cout << "Choose an operation: ";
    std::cin >> choice;
    
    return static_cast<OperationType>(choice);
}

void printMatrix(const Matrix &matrix)
{
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            std::cout << matrix.getValue(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

    