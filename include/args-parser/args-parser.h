#pragma once

#include "option.h"

#include <list>

namespace args {
    /**
     * @brief The main class for manipulating command line arguments..
     */
    class ArgsParser {
        /**
         * @brief Number of command line arguments.
         */
        int _argc;

        /**
         * @brief Pointer to command line arguments.
         */
        const char** _argv;

        /**
         * @brief A list of options that can be found in command line arguments.
         * It is recommended that the first item in the list be the default value.
         * For more information, see Readme.md on GitHub.
         */
        std::list<IOption*> _option_list;

        /**
         * @brief Whether there is a default value.
         * For the "default value", see Readme.md on GitHub.
         */
        bool _default_option_exist;

    public:
        /**
         * @brief Initialize the _argv = argc, _argv = argv, _default_option_exist = false field.
         */
        ArgsParser(int argc, const char** argv);

        /**
         * @brief Returns a list of options.
         * @return A list of options.
         */
        std::list<IOption*> getOptions() const;

        /**
         * @brief Adds an option to the list of options.
         * @param option - Pointer to an option.
         */
        void addOption(IOption* option);

        /**
         * @brief Calls the options found in argv.
         */
        void callOptions();
    };
}  // namespace args
