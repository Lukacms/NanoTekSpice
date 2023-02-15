/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** TrueComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class TrueComponent : public AComponent
    {
        public:
            TrueComponent(const std::string &name);
            ~TrueComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
    };
} // namespace nts
