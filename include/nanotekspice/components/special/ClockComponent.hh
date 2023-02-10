/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** ClockComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class ClockComponent : public AComponent
    {
        public:
            ClockComponent(const std::string &name);
            ~ClockComponent() override = default;

            void setNewState(nts::Tristate state) final;
            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;

        private:
            nts::Tristate current_state = nts::Tristate::Undefined;
            nts::Tristate new_state = nts::Tristate::Undefined;
            bool is_new_state_exist = false;
    };

} // namespace nts
