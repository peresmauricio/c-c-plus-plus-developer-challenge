#include "HmiCli.h"
#include "matrix.h"
#include "lib_menu.h"

    
    void HmiCli::displayMenu(const Menu& m ) {
        
        std::cout << "\n"<< m.getTitle() << "\n" << std::endl;
        for (const auto& item : m.getItems()) {
            std::cout << item.getId() << " - " << item.getName() << std::endl;
        }
    }

    int HmiCli::getUserChoice(std::string msg){
        int choice;
        std::cout << msg; 
        std::cin >> choice;
        std::cout << "Choice Operation: " << choice;
        return choice;
    }

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
        std::cout << "Enter matrix order: ";
        std::cin >> n;
        std::cout << std::endl;
        std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
        for (int i = 0; i < n; ++i) {
            std::cout << "Enter row " << (i + 1) << ": ";
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
        return matrix;
    }

    void HmiCli::showMatrix(std::vector<std::vector<double>> matrix)
    {
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();

        for (int i = 0; i < rows; ++i) {
            std::cout << "| ";
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << " |" << std::endl;
        }
    }

    