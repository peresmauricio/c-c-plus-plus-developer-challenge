
#ifndef APP_MATRIX_H_INCLUDED
#define APP_MATRIX_H_INCLUDED

#include <string>

/**
 * @file app_matrix.h
 * @brief Header file for the matrix application.
 * This module provides the interface for the matrix application that allow
 * to perform matrix operations. 
 */

/**
 * @brief Initializes the matrix application.
 * @details Initialize modules and database requered to the 
 * application.
 */
void app_matrix_init();

/**
 * @brief Function to perform a expression
 * @details The function receive a string expression. Analise the sintaxe of that and 
 * construct the precedence execution to reach the final resul.
 * The string expression should has operatons and values sapareted with a space " ".
 * The string expression can identify operation precedence with "()" parenteses caracteres.
 * Ex: ( A + B ) * C
 * @param expression String of math expression.Ex A + B.
 */
void app_matrix_perform_operation(const std::string expression);

/**
 * @brief Function to perform a determinat calculation
 * @details The function request to the user a input of a matrix, calculate the 
 * determinant result and show the value.
 */
void app_matrix_perform_determinant();

#endif // APP_MATRIX_H_INCLUDED