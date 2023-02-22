/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4040Component
*/

#pragma once

#include "nanotekspice/components/AGate.hh"

namespace nts
{
    class TwelveBitCounterComponent : public AGate
    {
        public:
            TwelveBitCounterComponent(const std::string &name);
            TwelveBitCounterComponent(TwelveBitCounterComponent const &to_copy) = default;
            TwelveBitCounterComponent(TwelveBitCounterComponent &&to_move) = default;

            ~TwelveBitCounterComponent() override = default;

            TwelveBitCounterComponent &
            operator=(TwelveBitCounterComponent const &to_copy) = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
