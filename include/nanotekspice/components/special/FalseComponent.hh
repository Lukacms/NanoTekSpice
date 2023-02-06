/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** FalseComponent
*/

#pragma once

#include "AComponent.hh"

namespace nts
{
    class FalseComponent : public AComponent
    {
        public:
            FalseComponent(std::string name);
            ~FalseComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;
    };
} // namespace nts
