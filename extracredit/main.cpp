#include "DateTime.h"
#include <iostream>

int main() {
    // Create a DateTime object with a time zone offset
    DateTime dt1(2024, 12, 13, 14, 30, 45, -8); // PST
    DateTime dt2(2024, 12, 14, 10, 25, 30, 0);  // UTC

    // Adjust time zone
    dt1.adjustTimeZone(0); // Convert PST to UTC
    std::cout << "After time zone adjustment: " << dt1.serialize() << std::endl;

    // Apply daylight saving time
    dt1.applyDaylightSaving(true);
    std::cout << "After DST adjustment: " << dt1.serialize() << std::endl;

    // Get day of the week
    std::cout << "Day of the week: " << dt1.getDayOfWeek() << std::endl;

    // Serialize and deserialize
    std::string serialized = dt1.serialize();
    std::cout << "Serialized: " << serialized << std::endl;

    DateTime deserialized = DateTime::deserialize(serialized);
    std::cout << "Deserialized: " << deserialized.serialize() << std::endl;

    return 0;
}
