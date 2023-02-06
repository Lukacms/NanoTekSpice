/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** InputComponent
*/

#include <nanotekspice/components/special/InputComponent.hh>

/* Constructor & Destructor */

nts::InputComponent::InputComponent(std::string cname)
{
    this->name = cname;
    return;
}

/* Methods */

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    return this->currentState;
}

void nts::InputComponent::setCurrentState(nts::Tristate state)
{
    this->currentState = state;
    return;
}