#include <iostream>
using namespace std;

int main() {
    double income = 95000;
    double stateTaxRate = 0.04;
    double countyTaxRate = 0.02;

    double stateTax = income * stateTaxRate;
    double countyTax = income * countyTaxRate;
    double totalTax = stateTax + countyTax; 

    cout << "Total sales: $" << income << endl;
    cout << "State tax: $" << stateTax << endl;
    cout << "County tax: $" << countyTax << endl;
    cout << "Total tax: $" << totalTax << endl;
    
    return 0; 
}