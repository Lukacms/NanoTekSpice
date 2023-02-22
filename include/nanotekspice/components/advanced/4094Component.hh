/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4094Component
*/

#pragma once

#include "nanotekspice/components/AGate.hh"
#include <string>

namespace nts
{
    class EightBitShifterComponent : public AGate
    {
        public:
            EightBitShifterComponent(const std::string &pname);
            EightBitShifterComponent(EightBitShifterComponent const &to_copy) = default;
            EightBitShifterComponent(EightBitShifterComponent &&to_move) = default;

            ~EightBitShifterComponent() override = default;

            EightBitShifterComponent &operator=(EightBitShifterComponent const &to_copy) = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
