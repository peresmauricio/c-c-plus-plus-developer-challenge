#include <iostream>
#include "matrix.h"
#include "prompt_hmi.h"


using namespace std;



void createMatrix() {

    double rows, cols, value;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    Matrix mat(rows, cols);

    std::cout << "Matrix created with " << mat.getRows() << " rows and " << mat.getCols() << " columns." << std::endl; 

    //inserir os valores da matriz
    for(int i = 0; i < mat.getRows(); i++) {
        for(int j = 0; j < mat.getCols(); j++) {
            std::cout << "Enter value for position (" << i << ", " << j << "): ";
            std::cin >> value;
            mat.setValue(i, j, value);
        }
    }
    
    // Exibir a matriz
    std::cout << "Matrix entered:" << std::endl;
    printMatrix(mat);

    //calcular o determinante
    try {
        double det = mat.determinant();
        std::cout << "Determinant: " << det << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error calculating determinant: " << e.what() << std::endl;
    }

}


int main() {

    OperationType op;
    std::cout << "Artimethical operations Software" << std::endl;

    displayMenu();
    op = getOperationChoice();

    switch (op)
    {
    case OperationType::DETERMINANT:
        /* code */
        std::cout << "Calculation of determinant" << std::endl;

        //inserir a ordem da matriz
        createMatrix();

        break;
    case OperationType::ADDITION:
        std::cout << "Addition selected" << std::endl;
        break;
    case OperationType::SUBTRACTION:
        std::cout << "Subtraction selected" << std::endl;
        break;
    case OperationType::MULTIPLICATION:
        std::cout << "Multiplication selected" << std::endl;
        break;
    case OperationType::DIVISION:
        std::cout << "Division selected" << std::endl;
        break;
    case OperationType::INVALID:
        std::cout << "Invalid operation number. Exiting." << std::endl;
        break;
    default:
        std::cout << "Not implemented yet" << std::endl;
        break;
    }   

    return 0;
}
