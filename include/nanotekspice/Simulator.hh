/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Simulator
*/

#pragma once

#include <exception>
#include <nanotekspice/Circuit.hh>
#include <string>

constexpr char const *LOOP_INPUT_WRONG_ARG_NB = "Wrong number of arguments to change input.";
constexpr char const *LOOP_WRONG_TYPE =
    "Cannot change a composant that is not an input or a clock.";
constexpr char const *LOOP_WRONG_INPUT_VALUE = "Value to change an input must be 1, 0 or U";

namespace nts
{
    class LoopException : public std::exception
    {
        public:
            LoopException(const std::string &perrmsg) : errmsg{perrmsg} {}

            LoopException(LoopException const &to_copy) = default;
            LoopException(LoopException &&to_move) = default;

            ~LoopException() override = default;

            LoopException &operator=(LoopException const &to_copy) = default;

            const char *what() const noexcept override { return this->errmsg.c_str(); }

        private:
            std::string errmsg;
    };

    int main_loop(nts::Circuit &circuit);
    // functions to call during loop
    int simulate(nts::Circuit &circuit, std::string &line);
    int input_change(nts::Circuit &circuit, std::string &line);
    int display(nts::Circuit &circuit, std::string &line);
    int loop(nts::Circuit &circuit, std::string &line);
}; // namespace nts
