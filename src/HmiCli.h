#ifndef HMI_CLI_H_INCLUDED
#define HMI_CLI_H_INCLUDED

#include "matrix.h"
#include "lib_menu.h"
#include "Hmi.h"


class HmiCli : public HMI {
public:
    //HMICli(std::string strTitle) : Menu(strTitle) {};
    HmiCli(){};
    ~HmiCli() = default;
    void displayMenu(const Menu& m ) override;
    int getUserChoice(std::string msg) override;
    //std::pair<double, double> getSingleValues() override;
    std::vector<double> getArrayValues() override;
    std::vector<std::vector<double>> getMatrix() override;
    //void displayResult(double result) override;    
    //int getOperationChoice();
    //void printMatrix(const Matrix &matrix);
    //void display() const override;
};

#endif // HMI_CLI_H_INCLUDED

