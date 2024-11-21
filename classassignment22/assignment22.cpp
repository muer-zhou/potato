#include "assignment22.h"
#include <sstream> // For stringstream

namespace methods {
    std::pair<std::string, std::string> extractFirstAndLastName(const std::string& fullName) {
        std::istringstream stream(fullName);
        std::string firstName, lastName, word;
        
        // Extract the first name (first word in the stream)
        stream >> firstName;

        // Extract the last name (last word in the stream)
        while (stream >> word) {
            lastName = word;
        }

        return {firstName, lastName};
    }
}
