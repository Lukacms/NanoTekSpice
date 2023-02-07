/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4008Component
*/

#pragma once

#include <nanotekspice/components/AGate.hh>

enum Pins {
    InA4 = 1,
    InB3 = 2,
    InA3 = 3,
    InB2 = 4,
    InA2 = 5,
    InB1 = 6,
    InA1 = 7,
    CarryIn = 9,
    Out0 = 10,
    Out1 = 11,
    Out2 = 12,
    Out3 = 13,
    CarryOut = 14,
    InB4 = 15
};

namespace nts
{
    class FourBitAdderComponent : public AGate
    {
        public:
            FourBitAdderComponent(const std::string &name);
            ~FourBitAdderComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);
    };
} // namespace nts
