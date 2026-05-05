
#include "app_matrix.h"
#include "matrix.h"
#include "lib_matrix.h"
#include "lib_menu.h"
#include "HmiCli.h"
#include <cstdlib>
#include <thread>

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

/// Local Functions -----------------------------------
void matrix_processing_operation(int operation);



void matrix_processing_operation(int operation)
{
    //do{
    //    ler a primeira matriz (perguntar se elemento por elemento ou array)
    //    executar operacao 
    //
    //}while(gucCtrProcessMachine);
} 


void app_matrix_init() {
    
    int optionSelected = 0;

    HmiCli hmi;   // Start HMI

    // Creating the main menu of operations
    Menu mainMenu("Matrix Operations"); 
    
    mainMenu.addItem(MenuItem("Addition", MatrixOptions::ADDITION));
    mainMenu.addItem(MenuItem("Subtraction", MatrixOptions::SUBTRACTION));
    mainMenu.addItem(MenuItem("Multiplication", MatrixOptions::MULTIPLICATION));
    mainMenu.addItem(MenuItem("Determinant", MatrixOptions::DETERMINANT));
    mainMenu.addItem(MenuItem("Exit", MatrixOptions::EXIT));

    do{
        switch(gucCtrMachine)
        {
            case APP_WAITING_FOR_INPUT:
                system("clear"); // Clear the console for better readability. 
                hmi.displayMenu(mainMenu);
                
                std::cout << "Select an option: ";
                std::cin >> optionSelected;
                std::cout << "You selected: " << optionSelected << std::endl;
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
            case APP_PROCESSING:   
                std::cout << "Request to Execution Option." << std::endl;

                


                break;
            case APP_FINALIZANDO:
                std::cout << "App Finalizando" << std::endl;
                break;
        }


        switch (optionSelected)
        {
        case MatrixOptions::DETERMINANT:
            /* code */
            std::cout << "Calculation of determinant" << std::endl;

            //inserir a ordem da matriz
            //createMatrix();

            break;
        case MatrixOptions::ADDITION:
            std::cout << "Addition selected" << std::endl;

            // check if matrices have the same order.

            break;
        case MatrixOptions::SUBTRACTION:
            std::cout << "Subtraction selected" << std::endl;

            // Check if matrices have the same order.

            break;
        case MatrixOptions::MULTIPLICATION:
            std::cout << "Multiplication selected" << std::endl;
            break;
        
        default:
            std::cout << "Not implemented yet" << std::endl;
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