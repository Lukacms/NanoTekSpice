/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4081Component
*/

#pragma once

#include <nanotekspice/components/AGate.hh>

namespace nts
{
    class FourAndComponent : public AGate
    {
        public:
            FourAndComponent(const std::string &name);
            ~FourAndComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
    };
} // namespace nts
