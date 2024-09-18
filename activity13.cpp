#include <iostream>
using namespace std;

int main() {
    int count = 0;            
    double temperature = 0.0;  
    double sum = 0.0;         

    cout << "Enter temperatures (type -1 to finish): " << endl;

    while (true) {
        cin >> temperature;
        if (temperature == -1) {
            break; 
        }
        sum += temperature; 
        count++;            
    }

    if (count > 0) {
        double average = sum / count;
        cout << "The average temperature is: " << average << endl;
    } else {
        cout << "No temperatures were entered." << endl;
    }

    return 0;
}
