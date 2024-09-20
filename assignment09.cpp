#include <iostream>
using namespace std;

int main() {
   string citizenship;
   string degree;
   int experience;

   cout << "Are you a US citizen? Please answer yes or no";
   cin >> citizenship;

   cout << "Do you have a bacherlor's degree? Please answer yes or no";
   cin >> degree;

   cout << "How many years of experience do you have?";
   cin >> experience;

   if (citizenship == "yes" && (degree == "yes" || experience >=2)) {
    cout << "You are eligible for the job!" << endl;
   } else {
    cout << "You are not eligible for the job." << endl;
   }
    
    return 0;
    
}