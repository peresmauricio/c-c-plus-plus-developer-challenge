#include "HmiCli.h"
#include "matrix.h"
#include "lib_menu.h"

    
    void HmiCli::displayMenu(const Menu& m ) {
        
        std::cout << "\n"<< m.getTitle() << "\n" << std::endl;
        for (const auto& item : m.getItems()) {
            std::cout << item.getId() << " - " << item.getName() << std::endl;
        }
    }
    int HmiCli::getOperationChoice() {
        int choice;
        std::cin >> choice;
        return choice;
    }
    //std::pair<double, double> HmiCli::getSingleValues() {
    //}

    std::vector<double> HmiCli::getArrayValues() {
        int size;
        std::cout << "Enter number of values: ";
        std::cin >> size;
        std::vector<double> values(size);
        for (int i = 0; i < size; ++i) {
            std::cout << "Enter value " << (i + 1) << ": ";
            std::cin >> values[i];
        }
        return values;
    }

    std::vector<std::vector<double>> HmiCli::getMatrix(){
        int n;
        std::cout << "Enter matrix size (2 or 3): ";
        std::cin >> n;
        std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
        for (int i = 0; i < n; ++i) {
            std::cout << "Enter row " << (i + 1) << ": ";
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
        return matrix;
    }

    //void HmiCli::displayResult(double result) override {
    //}

/*
    void HmiCli::display() const {
        std::cout << "\n"<< getTitle() << "\n" << std::endl;
        for (const auto& item : getItems()) {
            std::cout << item.getId() << " - " << item.getName() << std::endl;
        }
    }


int HmiCli::getOperationChoice() {
    int choice;
    std::cout << "Choose an operation: ";
    std::cin >> choice;
    
    return static_cast<int>(choice);
}

void HmiCli::printMatrix(const Matrix &matrix)
{
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            std::cout << matrix.getValue(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
*/
    