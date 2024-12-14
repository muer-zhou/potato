#include "DateTime.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

// Constructor with time zone offset
DateTime::DateTime(int y, int m, int d, int h, int mi, int s, int tz)
    : Date(y, m, d), Time(h, mi, s), timeZoneOffset(tz) {}

// Adjust time zone
void DateTime::adjustTimeZone(int newOffset) {
    int hourDifference = newOffset - timeZoneOffset;
    addHours(hourDifference); // Adjust the hours
    timeZoneOffset = newOffset; // Update the offset
}

// Apply daylight saving time adjustment
void DateTime::applyDaylightSaving(bool addOneHour) {
    addHours(addOneHour ? 1 : -1);
}

// Determine the day of the week using Zeller's Congruence
std::string DateTime::getDayOfWeek() const {
    int adjustedMonth = (month < 3) ? month + 12 : month;
    int adjustedYear = (month < 3) ? year - 1 : year;

    int K = adjustedYear % 100;
    int J = adjustedYear / 100;

    int f = day + (13 * (adjustedMonth + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J);
    int dayOfWeek = ((f % 7) + 7) % 7;

    const std::string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return days[dayOfWeek];
}

// Return the number of days in the current month
int DateTime::daysInMonth() const {
    return daysInMonth(month, year);
}

// Serialize the DateTime object to a string
std::string DateTime::serialize() const {
    std::ostringstream oss;
    oss << year << "-" << (month < 10 ? "0" : "") << month << "-"
        << (day < 10 ? "0" : "") << day << " "
        << (hours < 10 ? "0" : "") << hours << ":"
        << (minutes < 10 ? "0" : "") << minutes << ":"
        << (seconds < 10 ? "0" : "") << seconds
        << " TZ=" << timeZoneOffset;
    return oss.str();
}

// Deserialize a string into a DateTime object
DateTime DateTime::deserialize(const std::string &data) {
    int y, m, d, h, mi, s, tz;
    char dummy;
    std::istringstream iss(data);
    if (!(iss >> y >> dummy >> m >> dummy >> d >> h >> dummy >> mi >> dummy >> s >> dummy >> tz)) {
        throw std::invalid_argument("Invalid DateTime format");
    }
    return DateTime(y, m, d, h, mi, s, tz);
}

// Add date and time
void DateTime::addDateTime(int y, int m, int d, int h, int mi, int s) {
    addDate(y, m, d);
    addTime(h, mi, s);
}

// Compute the difference between two DateTime objects
void DateTime::difference(const DateTime& other) {
    int totalSecondsThis = toDays() * 86400 + timeToSeconds();
    int totalSecondsOther = other.toDays() * 86400 + other.timeToSeconds();

    int diffSeconds = std::abs(totalSecondsThis - totalSecondsOther);

    int days = diffSeconds / 86400;
    diffSeconds %= 86400;

    int hours = diffSeconds / 3600;
    diffSeconds %= 3600;

    int minutes = diffSeconds / 60;
    int seconds = diffSeconds % 60;

    std::cout << "Difference: "
              << days << " days, "
              << hours << " hours, "
              << minutes << " minutes, "
              << seconds << " seconds.\n";
}

// Convert time to total seconds
int DateTime::timeToSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}
