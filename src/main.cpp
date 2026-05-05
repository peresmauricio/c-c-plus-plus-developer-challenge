#include <iostream>
#include "matrix.h"
#include "prompt_hmi.h"
// Applicatons header files
#include "app_matrix.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>


using namespace std;


int main() {

    auto logger = spdlog::rotating_logger_mt(
        "app",
        "app.log",
        5 * 1024 * 1024, // 5 MB
        3               // 3 arquivos
    );

    logger->info("Aplicação iniciada");
    logger->warn("Algo estranho aconteceu");
    logger->error("Erro ao abrir arquivo");


    std::cout << "Artimethical operations Software" << std::endl;

    // Start the matrix applicaton
    app_matrix_init();

    return 0;
}
