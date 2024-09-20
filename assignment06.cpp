#include <iostream>
using namespace std;

int main() {
    string street;
    string city;
    string state;
    string zipcode;

    cout << "Where do you live? Please name the street, city and zipcode" << endl;
    cout << "Please enter street" << endl;
    cin >> street;
    cout << "Please enter city" << endl;
    cin >> city;
    cout << "Please enter state" << endl;
    cin >> state;
    cout << "Please enter zip code" << endl;
    cin >> zipcode;

    cout << city << " , " << state << " , " << zipcode << endl;

    return 0;
}