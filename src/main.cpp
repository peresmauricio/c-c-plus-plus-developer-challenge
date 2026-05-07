#include <iostream>
#include "matrix.h"
// Applicatons header files
#include "app_matrix.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <filesystem>


using namespace std;


int main() {

    std::filesystem::create_directories("logs");
    auto logger = spdlog::rotating_logger_mt(
        "file_logger",
        "logs/app.log",
        5 * 1024 * 1024, // 5 MB
        3               // 3 arquivos
    );


    auto cpp_std = []() {
        switch (__cplusplus) {
            case 199711L: return "C++98/03";
            case 201103L: return "C++11";
            case 201402L: return "C++14";
            case 201703L: return "C++17";
            case 202002L: return "C++20";
            case 202302L: return "C++23";
            default:      return "Desconhecida";
        }
    }();

    // Padrão {fmt}
    logger->info("Aplicação iniciada. Padrão: {} (macro __cplusplus={})", cpp_std, __cplusplus);
    logger->warn("Algo estranho aconteceu");
    logger->error("Erro ao abrir arquivo");


    std::cout << "Artimethical operations Software" << std::endl;

    // Start the matrix applicaton
    app_matrix_init();

    return 0;
}
