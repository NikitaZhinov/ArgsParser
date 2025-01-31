#pragma once

#include <string>

namespace args {
    /**
     * @brief A class for options.
     */
    class IOption {
        /**
         * @brief The name of the option.
         * If the name is empty, then the option is considered the default option.
         * For more information, see Readme.md on GitHub.
         */
        std::string _name;

    protected:
        /**
         * @brief Sets a new name for the option.
         */
        void setName(const std::string& name);

    public:
        /**
         * @brief Default constructor.
         */
        IOption() = default;

        /**
         * @brief Returns the option name.
         */
        std::string getName() const;

        /**
         * @brief A virtual method for determining what an option will do.
         * @param args - a pointer to the current command line argument.
         */
        virtual void call(const char** args) const = 0;
    };
}  // namespace args
