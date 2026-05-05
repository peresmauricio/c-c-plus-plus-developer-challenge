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
    virtual void displayMenu(const Menu& m);
    virtual int getOperationChoice();
    //virtual std::pair<double, double> getSingleValues();
    virtual std::vector<double> getArrayValues();
    virtual std::vector<std::vector<double>> getMatrix();
    //virtual void displayResult(double result);    
    virtual ~HMI(){};
};



#endif // HMI_H_INCLUDED