/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4071Component
*/

#pragma once

#include <nanotekspice/components/AGate.hh>

namespace nts
{
    class FourOrComponent : public AGate
    {
        public:
            FourOrComponent(const std::string &name);
            ~FourOrComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
    };
} // namespace nts
