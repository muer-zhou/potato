#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    int secretnumber = rand() % 100 + 1;
    int guess = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100" << endl;
    cout << "Can you guess what it is?"<< endl;

    while (guess != secretnumber) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < secretnumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretnumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed it: " << secretnumber << endl;

        }
    }
    return 0; 
}