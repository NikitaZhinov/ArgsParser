#include "dependences.h"

std::string Program::text;
std::string Program::version;
std::string Program::output;

void Program::restart() {
    text = "";
    version = "";
    output = "";
}

void Program::setText(const std::string& str) {
    text = str;
}

std::string Program::getText() {
    return text;
}

void Program::setVersion(const std::string& ver) {
    version = ver;
}

std::string Program::getVersion() {
    return version;
}

void Program::print(const std::string& out) {
    output = out;
}

std::string Program::getPrint() {
    return output;
}

void DefaultOption::call(const char** args) const {
    Program::setText(std::format("call: {}", args[0]));
}

VersionOption::VersionOption(const std::string& ver) : _ver(ver) {
    this->setName("--version");
}

void VersionOption::call(const char** args) const {
    Program::setVersion(std::format("version: {}", _ver));
}

PrintOption::PrintOption() {
    this->setName("--print");
    this->setNumberOfArgummentsUsed(1);
}

void PrintOption::call(const char** args) const {
    Program::print(args[1]);
}
