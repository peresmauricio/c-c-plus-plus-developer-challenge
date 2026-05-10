#include <iostream>
#include "app_matrix.h"
#include "app_logger.hpp"
#include <spdlog/spdlog.h>


using namespace std;


int main() {

    app_logger_init();
    
    app_matrix_init();

    return 0;
}
