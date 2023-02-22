/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4013Component
*/

#pragma once

#include "nanotekspice/components/AGate.hh"

namespace nts
{
    class DualFlipFlopComponent : public AGate
    {
        public:
            DualFlipFlopComponent(const std::string &name);
            DualFlipFlopComponent(DualFlipFlopComponent const &to_copy) = default;
            DualFlipFlopComponent(DualFlipFlopComponent &&to_move) = default;

            ~DualFlipFlopComponent() override = default;

            DualFlipFlopComponent &operator=(DualFlipFlopComponent const &to_copy) = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
