#pragma once

#include "option.h"

#include <map>
#include <memory>

namespace args {
    /**
     * @brief The main class for manipulating command line arguments.
     */
    class ArgsParser {
        int _argc;

        const char** _argv;

        std::map<std::string, std::unique_ptr<IOption>> _option_list;

        std::unique_ptr<IOption> _default_option;

        bool _checkNotEnoughArguments(int count, int index);
        void _validateOption(const std::unique_ptr<IOption>& option, int& i);
        void _callOption(const std::unique_ptr<IOption>& option, int& i);

        void _validateOptions();
        void _callOptions();

    public:
        /**
         * @brief Initialize the ArgsParser class.
         */
        ArgsParser(int argc, const char** argv);

        /**
         * @brief Adds an option to the list of options.
         *
         * @param option - Pointer to an option.
         */
        void addOption(std::unique_ptr<IOption>&& option);

        /**
         * @brief Calls the options found in argv.
         *
         * @throw std::invalid_argument
         * @throw std::out_of_range
         */
        void callOptions();

        /**
         * @brief Creates an option.
         *
         * @tparam TOption - option class.
         * @tparam TArgs - a type list for constructor arguments.
         *
         * @param args - a list of constructor arguments.
         */
        template <class TOption, class... TArgs>
        static std::unique_ptr<TOption> createOption(TArgs&&... args) {
            return std::make_unique<TOption>(std::forward<TArgs>(args)...);
        }

        /**
         * @brief Creates and adds an option.
         *
         * @tparam TOption - option class.
         * @tparam TArgs - a type list for constructor arguments.
         *
         * @param args - a list of constructor arguments.
         */
        template <class TOption, class... TArgs> void addOption(TArgs&&... args) {
            addOption(std::move(createOption<TOption>(std::forward<TArgs>(args)...)));
        }
    };
}  // namespace args
