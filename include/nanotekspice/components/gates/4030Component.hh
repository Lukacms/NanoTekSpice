/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4030Component
*/

#pragma once

#include <nanotekspice/components/AGate.hh>

namespace nts
{
    class FourXorComponent : public AGate
    {
        public:
            FourXorComponent(const std::string &name);
            ~FourXorComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
    };
} // namespace nts
