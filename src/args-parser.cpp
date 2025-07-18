#include "../include/args-parser/args-parser.h"

#include <stdexcept>

bool args::ArgsParser::_checkNotEnoughArguments(int count, int index) {
    for (int i = 1; i <= count; ++i) {
        if (_option_list.find(_argv[index + i]) != _option_list.end()) {
            return true;
        }
    }
    return false;
}

void args::ArgsParser::_validateOption(const std::unique_ptr<IOption>& option, int& i) {
    if (_argc <= option->getNumberOfArgummentsUsed() + i ||
        _checkNotEnoughArguments(option->getNumberOfArgummentsUsed(), i)) {
        throw std::out_of_range("not enough arguments");
    }
    i += option->getNumberOfArgummentsUsed();
}

void args::ArgsParser::_callOption(const std::unique_ptr<IOption>& option, int& i) {
    option->call(&_argv[i]);
    i += option->getNumberOfArgummentsUsed();
}

void args::ArgsParser::_validateOptions() {
    for (int i = 1; i < _argc; ++i) {
        auto option_it = _option_list.find(_argv[i]);
        if (option_it != _option_list.end()) {
            _validateOption(option_it->second, i);
        } else if (_default_option != nullptr) {
            _validateOption(_default_option, i);
        } else {
            throw std::invalid_argument("undefined option");
        }
    }
}

void args::ArgsParser::_callOptions() {
    for (int i = 1; i < _argc; ++i) {
        auto option_it = _option_list.find(_argv[i]);
        if (option_it != _option_list.end()) {
            _callOption(option_it->second, i);
        } else {
            _callOption(_default_option, i);
        }
    }
}

args::ArgsParser::ArgsParser(int argc, const char** argv) :
    _argc(argc),
    _argv(argv),
    _default_option(nullptr) {}

void args::ArgsParser::addOption(std::unique_ptr<IOption>&& option) {
    if (_default_option == nullptr && option->getName() == std::string()) {
        _default_option = std::move(option);
    } else {
        _option_list.insert(std::pair(option->getName(), std::move(option)));
    }
}

void args::ArgsParser::callOptions() {
    _validateOptions();
    _callOptions();
}
