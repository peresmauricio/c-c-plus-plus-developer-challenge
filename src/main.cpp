#include <iostream>
#include "app_matrix.h"
#include "app_logger.hpp"
#include <spdlog/spdlog.h>


using namespace std;


int main() {
    // Initialization of the system. 
    app_logger_init();
    // Initialization of application
    app_matrix_init();

    return 0;
}
