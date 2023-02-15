/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** InputComponent
*/

#include <nanotekspice/components/special/InputComponent.hh>

/* Constructor & Destructor */

nts::InputComponent::InputComponent(const std::string &cname)
{
    this->type = nts::ComponentType::Input;
    this->name = cname;
}

/* Methods */

nts::Tristate nts::InputComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    return this->current_state;
}

void nts::InputComponent::setNewState(nts::Tristate state)
{
    this->new_state = state;
}

void nts::InputComponent::simulate(std::size_t tick)
{
    if (tick == 0)
        return;
    this->current_state = this->new_state;
}
