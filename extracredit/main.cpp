#include <iostream>
#include "DateTime.hpp"

int main() {
    try {
        // Test basic functionality
        DateTime dt(2024, 3, 15, 14, 30, 45, -8.0);  // Pacific Time
        
        // Test formatting
        std::cout << "Original DateTime: " 
                  << dt.format("YYYY-MM-DD HH:MM:SS") << std::endl;
        
        // Test calendar operations
        std::cout << "Day of Week: " << dt.getDayOfWeek() << std::endl;
        std::cout << "Days in Month: " << dt.getDaysInMonth() << std::endl;
        
        // Test time zone adjustment
        dt.adjustTimeZone(-5.0);  // Convert to Eastern Time
        std::cout << "After timezone adjustment: " 
                  << dt.format("YYYY-MM-DD HH:MM:SS") << std::endl;
        
        // Test DST
        dt.applyDST(true);
        std::cout << "After applying DST: " 
                  << dt.format("YYYY-MM-DD HH:MM:SS") << std::endl;
        
        // Test serialization
        std::string serialized = dt.serialize();
        std::cout << "Serialized: " << serialized << std::endl;
        
        DateTime deserialized = DateTime::deserialize(serialized);
        std::cout << "Deserialized: " 
                  << deserialized.format("YYYY-MM-DD HH:MM:SS") << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}