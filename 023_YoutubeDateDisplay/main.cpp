#include <iostream>
#include <ctime>
#include <string>

// Function to convert time difference in seconds to a human-readable format
std::string timeAgo(int seconds) {
    int minutes = seconds / 60;
    int hours = minutes / 60;
    int days = hours / 24;
    int weeks = days / 7;
    int months = days / 30;
    int years = days / 365;

    if (seconds < 60) return "Just now";
    if (minutes < 60) return std::to_string(minutes) + " mins ago";
    if (hours < 24) return std::to_string(hours) + " hours ago";
    if (days < 7) return std::to_string(days) + " days ago";
    if (weeks < 4) return std::to_string(weeks) + " weeks ago";
    if (months < 12) return std::to_string(months) + " months ago";
    return std::to_string(years) + " years ago";
}

// Function to calculate the difference between the current time and a given timestamp
int calculateTimeDifference(std::time_t uploadTime) {
    std::time_t currentTime = std::time(0); // Get the current time in seconds since Unix epoch
    return static_cast<int>(currentTime - uploadTime); // Calculate the difference in seconds
}

int main() {
    // Simulating different upload times for testing
    // You can change these values or take input from the user
    std::time_t uploadTime1 = std::time(0) - 60 * 60 * 24 * 6;    // 6 days ago
    std::time_t uploadTime2 = std::time(0) - 60 * 60 * 24 * 30;   // 1 month ago
    std::time_t uploadTime3 = std::time(0) - 60 * 60 * 24 * 365;  // 1 year ago
    std::time_t uploadTime4 = std::time(0) - 60 * 60 * 24 * 730;  // 2 years ago
    std::time_t uploadTime5 = std::time(0) - 4 * 60;              // 4 mins ago
    std::time_t uploadTime6 = std::time(0);                       // Just now

    // Calculating time differences and converting to human-readable format
    std::cout << timeAgo(calculateTimeDifference(uploadTime1)) << std::endl;
    std::cout << timeAgo(calculateTimeDifference(uploadTime2)) << std::endl;
    std::cout << timeAgo(calculateTimeDifference(uploadTime3)) << std::endl;
    std::cout << timeAgo(calculateTimeDifference(uploadTime4)) << std::endl;
    std::cout << timeAgo(calculateTimeDifference(uploadTime5)) << std::endl;
    std::cout << timeAgo(calculateTimeDifference(uploadTime6)) << std::endl;

    return 0;
}
