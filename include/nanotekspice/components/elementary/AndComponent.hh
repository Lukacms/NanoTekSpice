/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** AndComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class AndComponent : public AComponent
    {
        public:
            AndComponent(const std::string &name);
            ~AndComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
    };
} // namespace nts
