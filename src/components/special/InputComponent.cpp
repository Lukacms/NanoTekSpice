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
    this->name = cname;
}

/* Methods */

nts::Tristate nts::InputComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    return this->currentState;
}

void nts::InputComponent::setCurrentState(nts::Tristate state)
{
    this->currentState = state;
}
