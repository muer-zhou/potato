#include <iostream>
#include "assignment29.h"

using namespace std;
using namespace assignment29;

int main() {
    string input = "24 s2,2014";

    // Parse the movie string
    Movie movie = parseMovie(input);

    // Display the parsed movie information
    cout << "Movie ID: " << movie.id << endl;
    cout << "Title: " << movie.title << endl;
    cout << "Year: " << movie.year << endl;

    return 0;
}
