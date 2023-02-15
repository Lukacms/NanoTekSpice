/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4069Component
*/

#pragma once

#include <nanotekspice/components/AGate.hh>

namespace nts
{
    class SixNotComponent : public AGate
    {
        public:
            SixNotComponent(const std::string &name);
            ~SixNotComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input = 0) final;
    };
} // namespace nts
