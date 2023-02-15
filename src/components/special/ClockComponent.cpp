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
    return this->current_state;
}

void nts::ClockComponent::setNewState(nts::Tristate state)
{
    this->new_state = state;
    this->is_new_state_exist = true;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (tick == 0)
        return;
    for (std::size_t i = 0; i < tick; i += 1) {
        if (this->current_state == nts::Tristate::Undefined)
            break;
        if (this->current_state == nts::Tristate::True)
            this->current_state = nts::Tristate::False;
        else
            this->current_state = nts::Tristate::True;
    }
    if (this->is_new_state_exist) {
        this->current_state = this->new_state;
        this->is_new_state_exist = false;
    }
}
