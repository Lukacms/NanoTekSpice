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
            OutputComponent(const std::string &name);
            ~OutputComponent() override = default;

            nts::Tristate compute(std::size_t tick) final;
            nts::Tristate getLastState();

        private:
            nts::Tristate currentState = nts::Tristate::Undefined;
    };
} // namespace nts
