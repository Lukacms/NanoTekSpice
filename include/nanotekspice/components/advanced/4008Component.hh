/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4008Component
*/

#pragma once

#include <nanotekspice/components/AGate.hh>

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
