#include "../include/LogHelper.hpp"
#include <chrono>
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
    auto timeNow = std::chrono::system_clock::now();
    auto localTimeNow = std::chrono::zoned_time("Asia/Irkutsk", timeNow).get_local_time();

    auto yearMonthDay = std::chrono::year_month_day(floor<days>(localTimeNow));
    auto hourMinuteSecond = std::chrono::hh_mm_ss(localTimeNow - floor<days>(localTimeNow));

    int year = static_cast<int>(yearMonthDay.year());
    int month = static_cast<int>(yearMonthDay.month());
    int day = static_cast<int>(yearMonthDay.day());
    int hour = hourMinuteSecond.hours().count();
    int minute = hourMinuteSecond.minutes().count();
    int second = hourMinuteSecond.seconds().count();

    std::ostringstream oss;
    oss << std::setfill('0');
    oss << std::setw(4) << year << "-";
    oss << std::setw(2) << month << "-";
    oss << std::setw(2) << day << " ";
    oss << std::setw(2) << hour << ":";
    oss << std::setw(2) << minute << ":";
    oss << std::setw(2) << second;
    return oss.str();
}
