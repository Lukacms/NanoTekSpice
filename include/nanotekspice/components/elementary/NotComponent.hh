/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** NotComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class NotComponent : public AComponent
    {
        public:
            NotComponent(const std::string &name);
            ~NotComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
    };
} // namespace nts
