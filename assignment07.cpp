#include <iostream>
#include <string>
using namespace std;

int main() {
    string names[3];

    for (int i = 0; i < 3; i++) {
        cout << "Enter name " << i + 1 << ": ";
        getline(cin, names[i]);
    }

    cout << "The first name is: " << names[0] << endl;

    return 0;
}
