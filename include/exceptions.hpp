#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

class UnableToOpenLogFileException : public std::exception {
public:
    const char* what() const noexcept {
        return "Error: unable to open log file.";
    }
};

class InvalidGameCellException : public std::exception {
public:
    const char* what() const noexcept {
        return "Error: value of game cell must be 1-9.";
    }
};

#endif
