#include "exception.h"

Exception::Exception() {
        this->exception = "";
}

Exception::Exception(std::string exception) {
        this->exception = exception;
}

std::string Exception::what() {
        return this->exception;
}
