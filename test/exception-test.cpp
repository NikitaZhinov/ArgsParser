#include <gtest/gtest.h>

#include "dependences.h"

TEST(ArgsParserExceptionTest, ExceptionTest_0) {
    int argc = 5;
    const char* argv[] = { "test.exe", "--version", "undefined", "--print",
                           "Hello, World!" };
    Program::restart();

    args::ArgsParser args_parser(argc, argv);

    args_parser.addOption<VersionOption>(std::string("1.0.0"));
    args_parser.addOption<PrintOption>();
    ASSERT_THROW(args_parser.callOptions(), std::invalid_argument);

    ASSERT_EQ("", Program::getText());
    ASSERT_EQ("", Program::getVersion());
    ASSERT_EQ("", Program::getPrint());
}

TEST(ArgsParserExceptionTest, ExceptionTest_1) {
    int argc = 5;
    const char* argv[] = { "test.exe", "--version", "--print", "Hello, World!",
                           "undefined" };
    Program::restart();

    args::ArgsParser args_parser(argc, argv);

    args_parser.addOption<VersionOption>(std::string("1.0.0"));
    args_parser.addOption<PrintOption>();
    ASSERT_THROW(args_parser.callOptions(), std::invalid_argument);

    ASSERT_EQ("", Program::getText());
    ASSERT_EQ("", Program::getVersion());
    ASSERT_EQ("", Program::getPrint());
}

TEST(ArgsParserExceptionTest, ExceptionTest_2) {
    int argc = 3;
    const char* argv[] = { "test.exe", "--version", "--print" };
    Program::restart();

    args::ArgsParser args_parser(argc, argv);

    args_parser.addOption<VersionOption>(std::string("1.0.0"));
    args_parser.addOption<PrintOption>();
    ASSERT_THROW(args_parser.callOptions(), std::out_of_range);

    ASSERT_EQ("", Program::getText());
    ASSERT_EQ("", Program::getVersion());
    ASSERT_EQ("", Program::getPrint());
}
