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
    //int getUserChoice(std::string msg) override;
    std::string getUserChoice(std::string msg);
    std::vector<double> getArrayValues() override;
    std::vector<std::vector<double>> getMatrix() override;
    void showMatrix(std::vector<std::vector<double>> matrix) override;
    /**
     * @brief Method to show a info user popup message.
     * @param psMsg string message to show to user.
     * @param piTime_sec Time that message should be showed to the user. 
     */
    void show_message(std::string psMsg, int piTime_sec);
};

#endif // HMI_CLI_H_INCLUDED

