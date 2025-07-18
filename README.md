# ArgsParser
A library for manipulating command line arguments.

## About
The library makes it convenient to work with command-line arguments and easily extend your application.

## Usage
An ArgsParser class object is created, to which argc and argv are passed. Then pointers are added to objects of classes inherited from the abstract class IOption. If an option has no name specified, it is considered the default option and is called if there are no matches with other options of the current argument.

## Example
main.cpp:
```cpp
#include <iostream>
#include <args-parser/args-parser.h>

class DefaultOption : public args::IOption {
public:
  void call(const char** args) const override {
    std::cout << "Hello " << args[0] << std::endl;
  }
};

class VersionOption : public args::IOption {
public:
  VersionOption() {
    this->setName("--version");
  }

  void call(const char** args) const override {
    std::cout << "Your application version: 1.0.0" << std::endl;
  }
};

class PrintOption : public args::IOption {
public:
  PrintOption() {
    this->setName("--print");
    this->setNumberOfArgummentsUsed(3);
  }

  void call(const char** args) const override {
    for (int i = 1; i <= getNumberOfArgummentsUsed(); ++i)
      std::cout << args[i] << " ";
    std::cout << std::endl;
  }
};

int main(int argc, const char** argv) {
  // create ArgsParser object
  args::ArgsParser args_parser(argc, argv);

  // add options
  args_parser.addOption<DefaultOption>();
  args_parser.addOption<VersionOption>();
  args_parser.addOption<PrintOption>();

  // call options
  args_parser.callOptions();
}
```
CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 3.20)

project(MyApp)

include(FetchContent)
FetchContent_Declare(
  ArgsParser
  GIT_REPOSITORY "https://github.com/NikitaZhinov/ArgsParser"
  GIT_TAG v2.0
)
FetchContent_MakeAvailable(ArgsParser)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ArgsParser)
target_include_directories(${PROJECT_NAME} PRIVATE ${ArgsParser_SOURCE_DIR}/include)
```
Run:
```bash
./MyApp --print Fish like water --version World
```
Output:
```
Fish like water
Your application version: 1.0.0
Hello World
```
