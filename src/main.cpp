
#include <iostream>

enum class OperationType {
    INVALID = 0,
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    DETERMINANT
};

OperationType getOperationChoice() {
    int choice;
    std::cout << "Select an operation to perform:" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Determinant of a matrix" << std::endl;
    std::cout << "Enter the operation number: ";
    std::cin >> choice;

    switch (choice) {
        case 1: return OperationType::ADDITION;
        case 2: return OperationType::SUBTRACTION;
        case 3: return OperationType::MULTIPLICATION;
        case 4: return OperationType::DIVISION;
        case 5: return OperationType::DETERMINANT;
        default:
            return OperationType::INVALID;
            //throw std::invalid_argument("Invalid operation number");
    }
}

int main() {

    OperationType op;
    std::cout << "Artimethical operations Software" << std::endl;

    op = getOperationChoice();

    switch (op)
    {
    case OperationType::DETERMINANT:
        /* code */
        std::cout << "Calculation of determinant" << std::endl;
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
