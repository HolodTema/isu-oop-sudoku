#include "../include/LogHelper.hpp"
#include <chrono>

void LogHelper::statusMessage(const std::string& msg) {
    ofs_ << "STATUS " << msg << "\n";
}

void LogHelper::warningMessage(const std::string& msg) {

}

void LogHelper::errorMessage(const std::string& msg) {

}


std::string LogHelper::getLocalDateTimeString() {
    auto timeNow = std::chrono::system_clock::now();
    std::chrono::zoned_time localTimeNow("Asia/Irkutsk", timeNow);
    auto yearMonthDay = std::chrono::year_month_day(floor<days>(localTimeNow.get_local_time()));
    auto hourMinuteSecond = std::chrono::hh_mm_ss(localTimeNow.get_local_time() - floor<days>(
    
     
}


