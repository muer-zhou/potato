#include "assignment29.h"
#include <sstream>
#include <iostream>

namespace assignment29 {
    Movie parseMovie(const std::string& movieString) {
        Movie movie;
        std::stringstream stream(movieString);

        // Parse the ID
        stream >> movie.id;

        // Parse the title (up to the comma)
        std::getline(stream, movie.title, ',');

        // Trim leading space from the title if needed
        if (!movie.title.empty() && movie.title[0] == ' ') {
            movie.title = movie.title.substr(1);
        }

        // Parse the year
        stream >> movie.year;

        return movie;
    }
}
