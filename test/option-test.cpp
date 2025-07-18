#include <gtest/gtest.h>

#include "dependences.h"

TEST(ArgsParserOptionTest, OptionTest_0) {
    int argc = 2;
    const char* argv[] = { "test.exe", "--version" };
    Program::restart();

    args::ArgsParser args_parser(argc, argv);

    args_parser.addOption<VersionOption>(std::string("1.0.0"));
    args_parser.callOptions();

    ASSERT_EQ("version: 1.0.0", Program::getVersion());
}

TEST(ArgsParserOptionTest, OptionTest_1) {
    int argc = 4;
    const char* argv[] = { "test.exe", "--version", "--print", "hello" };
    Program::restart();

    args::ArgsParser args_parser(argc, argv);

    args_parser.addOption<VersionOption>(std::string("1.0.0"));
    args_parser.addOption<PrintOption>();
    args_parser.callOptions();

    ASSERT_EQ("version: 1.0.0", Program::getVersion());
    ASSERT_EQ("hello", Program::getPrint());
}
