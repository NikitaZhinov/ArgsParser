#include "../include/args-parser/option.h"

void args::IOption::setName(const std::string& name) {
    _name = name;
}

void args::IOption::setNumberOfArgummentsUsed(int n) {
    _number_of_arguments_used = n;
}

std::string args::IOption::getName() const {
    return _name;
}

int args::IOption::getNumberOfArgummentsUsed() const {
    return _number_of_arguments_used;
}
