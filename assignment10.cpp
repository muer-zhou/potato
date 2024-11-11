#include <iostream>
#include <iomanip>  // For fixed and setprecision
using namespace std;

double calculateCommission(double sales) {
    double commissionRate;

    if (sales <= 10000) {
        commissionRate = 0.10;
    } else if (sales <= 15000) {
        commissionRate = 0.15;
    } else {
        commissionRate = 0.20;
    }

    return sales * commissionRate;
}

int main() {
    double salesAmount;
    cout << "Enter the sales amount: $";
    cin >> salesAmount;

    double commission = calculateCommission(salesAmount);

    // Output with two decimal precision
    cout << fixed << setprecision(2);
    cout << "The commission for sales of $" << salesAmount << " is: $" << commission << endl;

    return 0;
}
