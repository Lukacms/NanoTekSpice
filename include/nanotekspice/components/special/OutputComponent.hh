/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** OutputComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class OutputComponent : public AComponent
    {
        public:
            OutputComponent(std::string name);
            ~OutputComponent() = default;

            nts::Tristate compute(std::size_t tick);

        private:
            nts::Tristate currentState = nts::Tristate::Undefined;
    };
} // namespace nts
