#include "../include/LogHelper.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

void LogHelper::statusMessage(const std::string& msg) {
    ofs_ << getLocalDateTimeString() << "STATUS: " << msg << "\n";
}

void LogHelper::warningMessage(const std::string& msg) {
    ofs_ << getLocalDateTimeString() << "WARNING: " << msg << "\n";
}

void LogHelper::errorMessage(const std::string& msg) {
    ofs_ << getLocalDateTimeString() << "ERROR: " << msg << "\n";
}

std::string LogHelper::getLocalDateTimeString() const {
    std::time_t secondsSinceEpoch = std::time(nullptr);
    std::tm tm = *std::localtime(&secondsSinceEpoch);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
