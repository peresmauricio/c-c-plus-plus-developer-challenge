#ifndef HMI_H_INCLUDED
#define HMI_H_INCLUDED

#include <vector>
#include <optional>
#include "operations.h"
#include "lib_menu.h"

/**
 * @brief Abstract Human Machine Interface class. Concept class of base 
 *        user interaction.
 */
class HMI {
public:
    HMI() = default;
    virtual void displayMenu(const Menu& m) = 0;
    virtual int getUserChoice(std::string msg) = 0;
    //virtual std::pair<double, double> getSingleValues();
    virtual std::vector<double> getArrayValues() = 0;
    virtual std::vector<std::vector<double>> getMatrix() = 0;
    //virtual void displayResult(double result);    
    virtual ~HMI() = default;
};



#endif // HMI_H_INCLUDED