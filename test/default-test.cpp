#include <gtest/gtest.h>

#include "dependences.h"

TEST(ArgsParserDefaltOptionTest, DefaltOptionTest_0) {
    int argc = 2;
    const char* argv[] = { "test.exe", "someoption" };
    Program::restart();

    args::ArgsParser args_parser(argc, argv);

    args_parser.addOption<DefaultOption>();
    args_parser.callOptions();

    ASSERT_EQ("call: someoption", Program::getText());
}

TEST(ArgsParserDefaltOptionTest, DefaltOptionTest_1) {
    int argc = 3;
    const char* argv[] = { "test.exe", "--version", "someoption" };
    Program::restart();

    args::ArgsParser args_parser(argc, argv);

    args_parser.addOption<DefaultOption>();
    args_parser.addOption<VersionOption>(std::string("1.0.0"));
    args_parser.callOptions();

    ASSERT_EQ("call: someoption", Program::getText());
    ASSERT_EQ("version: 1.0.0", Program::getVersion());
}

TEST(ArgsParserDefaltOptionTest, DefaltOptionTest_2) {
    int argc = 5;
    const char* argv[] = { "test.exe", "--version", "someoption", "--print",
                           "Hello, World!" };
    Program::restart();

    args::ArgsParser args_parser(argc, argv);

    args_parser.addOption<DefaultOption>();
    args_parser.addOption<VersionOption>(std::string("1.0.0"));
    args_parser.addOption<PrintOption>();
    args_parser.callOptions();

    ASSERT_EQ("call: someoption", Program::getText());
    ASSERT_EQ("version: 1.0.0", Program::getVersion());
    ASSERT_EQ("Hello, World!", Program::getPrint());
}
