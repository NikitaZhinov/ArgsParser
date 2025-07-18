#pragma once

#include "../include/args-parser/args-parser.h"

#include <format>
#include <string>

class Program {
    static std::string text;
    static std::string version;
    static std::string output;

public:
    static void restart();

    static void setText(const std::string& str);

    static std::string getText();

    static void setVersion(const std::string& ver);

    static std::string getVersion();

    static void print(const std::string& out);

    static std::string getPrint();
};

class DefaultOption : public args::IOption {
public:
    void call(const char** args) const override;
};

class VersionOption : public args::IOption {
    std::string _ver;

public:
    VersionOption(const std::string& ver);

    void call(const char** args) const override;
};

class PrintOption : public args::IOption {
public:
    PrintOption();

    void call(const char** args) const override;
};
