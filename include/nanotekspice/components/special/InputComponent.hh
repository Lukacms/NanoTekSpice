/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** InputComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class InputComponent : public AComponent
    {
        public:
            InputComponent(std::string name);
            ~InputComponent() = default;

            void setCurrentState(nts::Tristate state);
            nts::Tristate compute(std::size_t pin) final;

        private:
            nts::Tristate currentState = nts::Tristate::Undefined;
    };
} // namespace nts
