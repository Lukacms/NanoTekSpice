/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** IComponent
*/

#pragma once

#include <memory>
#include <string>

namespace nts
{
    enum Tristate { Undefined = (-true), True = true, False = false };

    enum ComponentType { Input, Output, Clock, Other };

    class IComponent
    {
        public:
            IComponent() = default;
            IComponent(IComponent const &to_copy) = default;
            IComponent(IComponent &&to_move) = default;

            virtual ~IComponent() = default;

            IComponent &operator=(IComponent const &to_copy) = default;

            virtual void setNewState(nts::Tristate new_state) = 0;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std ::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin) = 0;
            virtual std::string getName() const = 0;
            virtual ComponentType getType() const = 0;
            virtual std::size_t getNumberOfComponents() const = 0;
    };
} // namespace nts
