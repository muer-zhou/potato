#ifndef ASSIGNMENT29_H
#define ASSIGNMENT29_H

#include <string>

namespace assignment29 {
    struct Movie {
        int id;
        std::string title;
        int year;
    };

    Movie parseMovie(const std::string& movieString);
}

#endif // ASSIGNMENT29_H
