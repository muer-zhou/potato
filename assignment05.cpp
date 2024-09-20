#include <iostream>
#include <limits>
using namespace std;

int main() 
{
    double doubleType;
    short shortType;

    cout << "Size of double is: " << sizeof(doubleType) << endl;
    cout << "Size of short is: " << sizeof(shortType) << endl;


    cout << "The range of a double is: " << endl;
    cout << numeric_limits<double>::max() << endl;
    cout << numeric_limits<double>::min() << endl;

    cout << "The range of a short is: " << endl;
    cout << numeric_limits<short>::max() << endl;
    cout << numeric_limits<short>::min() << endl;

    return 0;
}