#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <chrono>
#include <ctime>
#include <iomanip> 
#include <sstream>


bool authenticated = false;



void Authorize() {
    const std::string AUTH_FILE = "auth.txt";
    std::string authMarker = "T2fer3er7";

    std::ofstream authWrite(AUTH_FILE);
    if (!authWrite) {
        std::cerr << "Error: Cannot open file '" << AUTH_FILE << "' for writing.\n";
        authenticated = false;
        return;
    }
    authWrite << authMarker;
    authWrite.close();

    std::cout << "Auth marker written to " << AUTH_FILE << "\n";
    authenticated = true;
}




std::string getIllinoisTime12h() {
    using namespace std::chrono;
    auto now = system_clock::now();
    std::time_t now_time = system_clock::to_time_t(now);

    // Convert to UTC tm struct
    std::tm utc_tm;
#ifdef _WIN32
    gmtime_s(&utc_tm, &now_time);
#else
    utc_tm = *std::gmtime(&now_time);
#endif

    int month = utc_tm.tm_mon + 1;
    int day = utc_tm.tm_mday;
    int wday = utc_tm.tm_wday; // days since Sunday [0-6]

    // Rough DST period: second Sunday in March to first Sunday in November
    // Calculate second Sunday of March
    int second_sunday_march = 8 + ((7 - ((utc_tm.tm_wday + 6) % 7)) % 7);
    // Calculate first Sunday of November
    int first_sunday_nov = 1 + ((7 - ((utc_tm.tm_wday + 6) % 7)) % 7);

    // Using simplified DST check (better than nothing)
    bool dst = false;
    if (month > 3 && month < 11) {
        dst = true;
    }
    else if (month == 3) {
        // If day on or after second Sunday of March
        // We approximate second Sunday as day >= 8 (simple)
        dst = (day >= 8);
    }
    else if (month == 11) {
        // If day before first Sunday of November
        dst = (day < 7);
    }

    int offset = dst ? 5 : 6; // UTC-5 during DST, UTC-6 otherwise

    int hour = utc_tm.tm_hour - offset;
    if (hour < 0) hour += 24;

    std::string am_pm = "AM";
    if (hour == 0)
        hour = 12;
    else if (hour >= 12) {
        am_pm = "PM";
        if (hour > 12)
            hour -= 12;
    }
    std::ostringstream oss;
    oss << hour << ":" << std::setfill('0') << std::setw(2) << utc_tm.tm_min << " " << am_pm;
    return oss.str();
}
