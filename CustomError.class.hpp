#ifndef CUSTOM_ERROR_HPP
#define CUSTOM_ERROR_HPP

#include <iostream>

class CustomError {
public:
    class WrongSize : public std::exception {
        virtual const char *what() const throw() {
            return "Wrong size";
        }
    };

    class SizeNotSpecified : public std::exception {
        virtual const char *what() const throw() {
            return "The Map size is not specified";
        }
    };

    class TooMuchValues : public std::exception {
        virtual const char *what() const throw() {
            return "Too much values";
        }
    };

    class SyntaxError : public std::exception {
        virtual const char *what() const throw() {
            return "Syntax Error";
        }
    };

    class NumberOfValuesError : public std::exception {
        virtual const char *what() const throw() {
            return "Number of values Error";
        }
    };

    class UnknownFile : public std::exception {
        virtual const char *what() const throw() {
            return "File doesn't exist";
        }
    };
    class Unsolvable : public std::exception {
        virtual const char *what() const throw() {
            return "This puzzle is unsolvable.";
        }
    };


};

#endif