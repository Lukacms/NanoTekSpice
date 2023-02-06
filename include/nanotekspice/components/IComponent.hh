/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** IComponent
*/

#pragma once

#include <string>

namespace nts
{
    enum Tristate { Undefined = (-true), True = true, False = false };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std ::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin) = 0;
    };
} // namespace nts
