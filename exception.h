#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>

class Exception {
    public:

    class UnknownCoord : public std::exception {
        const char * what() const throw() {
            return "Coordinates of the object are unknown";
        }
    };

    class UnknownVelocity : public std::exception {
        const char * what() const throw() {
            return "Velocity of the object are unknown";
        }
    };

    class UnknownTimeStep : public std::exception {
        const char * what() const throw() {
            return "Time step are unknown";
        }
    };
};

#endif // EXCEPTION_H
