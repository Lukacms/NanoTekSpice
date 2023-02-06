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
            ClockComponent(std::string name);
            ~ClockComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);

        private:
            nts::Tristate currentState = nts::Tristate::Undefined;
    };

} // namespace nts
