/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** ClockComponent
*/

#include <nanotekspice/components/special/ClockComponent.hh>

/* Constructor & Destructor */

nts::ClockComponent::ClockComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::ClockComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    return this->currentState;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    for (std::size_t i = 0; i < tick; i += 1) {
        if (this->currentState == nts::Tristate::Undefined)
            break;
        if (this->currentState == nts::Tristate::True)
            this->currentState = nts::Tristate::False;
        else
            this->currentState = nts::Tristate::True;
    }
}
