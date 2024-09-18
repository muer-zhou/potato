#include <iostream>
#include <vector>
#include <string>  
using namespace std;

int main() {
    vector<vector<string>> table = {
        {"Course", "student"},
        {"C++", "100"},
        {"JavaScript", "50"}
    };

    for (int i = 0; i < table.size(); ++i) {            
        for (int j = 0; j < table[i].size(); ++j) {     
            cout << table[i][j] << "\t";                
        }
        cout << endl;                                   
    }

    return 0;
}
