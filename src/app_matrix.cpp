
#include "app_matrix.h"
#include "matrix.h"
#include "lib_matrix.h"
#include "lib_menu.h"
#include "HmiCli.h"
#include <cstdlib>
#include <thread>
#include "symbol.h"
#include "string.h"
#include <sstream>
#include "parser.h"
#include "tree_expression.h"
#include "app_progs.hpp"
#include "app_menu.hpp"

/// Local definitions  -------------------------------

/** @brief Define the menu options of matrix application */
enum MatrixOptions {
    EXIT = 0,
    ADDITION = 1,
    SUBTRACTION,
    MULTIPLICATION,
    DETERMINANT,
    MAX_OPTIONS
};

enum MatrixState {
    APP_WAITING_FOR_INPUT = 0,
    APP_INVALID_INPUT,
    APP_PROCESSING,
    APP_DISPLAYING_RESULT,
    APP_FINALIZANDO
};



/// Local Variables -----------------------------------
unsigned char gucCtrMachine = 0; // Global variable to control the state of the application.
unsigned char gucCtrProcessMachine = 0;

static HmiCli gHmi;   // Create a interface 

/// Local Functions -----------------------------------

/**
 * @brief Function to process a equation and show the respectively value.
 * @param equation A list of equation simbols.
 */
void matrix_perform_operation(const std::string expression);

/**
 * @brief Function to request all data of each element of equation.
 * @param node Pointer to the symbol node tree with all operations and values.
 *             Values means matricies in this app.
 */
void getMatrizData(exprlib::Node* node);


/// Implementation -----------------------------------------


void matrix_perform_operation(const std::string expression)
{
    exprlib::NodePtr node;
    std::ostringstream oss;

    // create the tree of tokens.
    node = exprlib::Parser::parseInfix(expression);
    
    exprlib::printTree(node.get(),oss);
    std::cout << oss.str() << std::endl;
    
    //Solicita os elementos das matrizes.
    getMatrizData(node.get()); 

    gHmi.showMatrix( (exprlib::perform_tree_expression(node.get())).getData());
} 

void getMatrizData(exprlib::Node* node) {
    if (!node) return;

    std::cout << (node->sym.getName()) << "\n";

    // If value request data elements of matrix
    if(node->sym.getType() == exprlib::Symbol::Type::VALUE)
    {
        std::cout << "\n Insira os dados da Matriz: " << node->sym.getName() << std::endl;
        Matrix dataMatrix(gHmi.getMatrix());
        node->sym.setValue(dataMatrix); 
        gHmi.showMatrix(dataMatrix.getData());
    }
    // Request data to childrens 
    getMatrizData(node->left.get());
    getMatrizData(node->right.get());
}




void app_matrix_init() {
    
    int optionSelected = 0;

    app_progs_init();

    app_menu_init();

    app_menu_control();
    //testar show menu

    return;

    do{
        std::string equation;  // store the operation expression to execute.  
        
        switch(gucCtrMachine)
        {
            case APP_WAITING_FOR_INPUT:
                system("clear"); // Clear the console for better readability. 
//                gHmi.displayMenu(mainMenu);
                
//                optionSelected = gHmi.getUserChoice("Select an option: ");

                if(optionSelected >= MatrixOptions::MAX_OPTIONS) {
                    gucCtrMachine = APP_INVALID_INPUT;
                }
                else if(optionSelected == MatrixOptions::EXIT){
                    gucCtrMachine = APP_FINALIZANDO;
                }
                else {
                    gucCtrMachine = APP_PROCESSING;
                }

                break;
            case APP_INVALID_INPUT:
                std::cout << "\nInvalid input. Please try again." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                gucCtrMachine = APP_WAITING_FOR_INPUT;
                break;
            case APP_PROCESSING:{   
                std::cout << "Request to Execution Option." << std::endl;
  
                switch (optionSelected)
                {
                case MatrixOptions::DETERMINANT:
                    
                    std::cout << "Calculation of determinant" << std::endl;
                    equation = "det A";                                                                                                    

                    break;
                case MatrixOptions::ADDITION:
                    std::cout << "Addition selected" << std::endl;
                    equation = "A + B"; //"";
                    break;
                case MatrixOptions::SUBTRACTION:
                    std::cout << "Subtraction selected" << std::endl;
                    equation = "A - B";
                    break;
                case MatrixOptions::MULTIPLICATION:
                    std::cout << "Multiplication selected" << std::endl;
                    equation = "A * B";
                    break;
                default:
                    std::cout << "Not implemented yet"; 
                    break;
                }   
                // Execute the operation.
                matrix_perform_operation(equation);
                
                std::this_thread::sleep_for(std::chrono::seconds(5));

                gucCtrMachine = APP_WAITING_FOR_INPUT;
                break;   
            }        
            case APP_FINALIZANDO:
                std::cout << "App Finalizando" << std::endl;
                break;
        }


        
    } while (optionSelected != MatrixOptions::EXIT);

}

/*
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
    //printMatrix(mat);

    //calcular o determinante
    try {
        double det = mat.determinant();
        std::cout << "Determinant: " << det << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error calculating determinant: " << e.what() << std::endl;
    }

}
*/