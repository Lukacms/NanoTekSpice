/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** FalseComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class FalseComponent : public AComponent
    {
        public:
            FalseComponent(const std::string &name = "");
            ~FalseComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
    };
} // namespace nts
