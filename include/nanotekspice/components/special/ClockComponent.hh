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

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;

        private:
            nts::Tristate currentState = nts::Tristate::Undefined;
    };

} // namespace nts
