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
            InputComponent(const std::string &name);
            ~InputComponent() override = default;

            void setNewState(nts::Tristate state) final;
            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;

        private:
            nts::Tristate current_state = nts::Tristate::Undefined;
            nts::Tristate new_state = nts::Tristate::Undefined;
    };
} // namespace nts
