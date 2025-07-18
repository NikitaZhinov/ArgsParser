#pragma once

#include <string>
#include <memory>

namespace args {
    /**
     * @brief A class for options.
     */
    class IOption {
        std::string _name;
        int _number_of_arguments_used = 0;

    protected:
        /**
         * @brief Sets a new name for the option.
         *
         * @param name - the new name of the option.
         */
        void setName(const std::string& name);

        /**
         * @brief Sets a number of arguments used.
         *
         * @param n - a number of arguments used.
         */
        void setNumberOfArgummentsUsed(int n);

    public:
        /**
         * @brief Default constructor.
         */
        IOption() = default;

        /**
         * @brief Returns the option name.
         * 
         * @return std::string - the option name.
         */
        std::string getName() const;

        /**
         * @brief Returns a number of arguments used.
         * 
         * @return int - a number of arguments used.
         */
        int getNumberOfArgummentsUsed() const;

        /**
         * @brief A virtual method for determining what an option will do.
         * @param args - a pointer to the current command line argument.
         */
        virtual void call(const char** args) const = 0;
    };
}  // namespace args
