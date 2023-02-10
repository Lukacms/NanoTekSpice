/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** XorComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class XorComponent : public AComponent
    {
        public:
            XorComponent(const std::string &name);
            ~XorComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;

    };
} // namespace nts
