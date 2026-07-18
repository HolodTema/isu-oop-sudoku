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

class InvalidGameFieldRowException : public std::exception {
public:
    const char* what() const noexcept {
        return "Error: row index of game field must be 0-8.";
    }
};

class InvalidGameFieldColumnException : public std::exception {
public:
    const char* what() const noexcept {
        return "Error: column index of game field must be 0-8.";
    }
};

class UnableToSetNumberToBusyGameCellException : public std::exception {
public:
    const char* what() const noexcept {
        return "Error: this game cell has already had number. It is unable to set the number again.";
    }
};

#endif
