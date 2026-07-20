#ifndef LOG_HELPER_HPP
#define LOG_HELPER_HPP

#include <string>
#include <fstream>
#include "exceptions.hpp"

class LogHelper {
public:

    explicit LogHelper(const std::string& filename):
        filename_(filename)
    {
        ofs_.open(filename_);
        if (!ofs_.is_open()) {
            throw UnableToOpenLogFileException();
        }
    }

    ~LogHelper() {
        ofs_.close();
    }

    void statusMessage(const std::string& msg);

    void warningMessage(const std::string& msg);

    void errorMessage(const std::string& msg); 

private:
    std::string filename_;
    std::ofstream ofs_;

    std::string getLocalDateTimeString() const;
};

#endif
