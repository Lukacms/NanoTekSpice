/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** LoggerComponent
*/

#pragma once

#include <nanotekspice/components/AGate.hh>
#include <string>

namespace nts
{
    class LoggerComponent : public AGate
    {
        public:
            LoggerComponent(const std::string &pname);
            LoggerComponent(LoggerComponent const &to_copy) = default;
            LoggerComponent(LoggerComponent &&to_move) = default;
            ~LoggerComponent() override = default;
            LoggerComponent &operator=(LoggerComponent const &to_copy) = default;

            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) override;
            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
