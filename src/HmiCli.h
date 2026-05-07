#ifndef HMI_CLI_H_INCLUDED
#define HMI_CLI_H_INCLUDED

#include "matrix.h"
#include "lib_menu.h"
#include "hmi.h"


class HmiCli : public HMI {
public:
    
    HmiCli(){};
    ~HmiCli() = default;
    void displayMenu(const Menu& m ) override;
    int getUserChoice(std::string msg) override;
    std::vector<double> getArrayValues() override;
    std::vector<std::vector<double>> getMatrix() override;
    void showMatrix(std::vector<std::vector<double>> matrix) override;
};

#endif // HMI_CLI_H_INCLUDED

