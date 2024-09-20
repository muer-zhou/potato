#include <iostream>
using namespace std;

int main() {
    double sales, commission;

    cout << "Enter the value of the sales: ";
    cin >> sales;

    if (sales <= 10000) {
        commission = sales * 0.10;  
    }
    else if (sales <= 15000) {
        commission = sales * 0.15;  
    }
    else {
        commission = sales * 0.20;  
    }

    cout << "The commission is: $" << commission << endl;

    return 0;
}
