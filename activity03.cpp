#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    srand(time(0));

    const int MIN_VALUE = 1;
    const int MAX_VALUE = 6;
    int roll1 = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    int roll2 = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

    cout << "First roll: " << roll1 << endl;
    cout << "Second roll: " << roll2 << endl;

    return 0; 
}