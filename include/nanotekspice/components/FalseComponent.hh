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
            FalseComponent() = default;
            ~FalseComponent() override;

            nts::Tristate compute(std::size_t pin) override;
    };
} // namespace nts
