/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** OutputComponent
*/

#include <iostream>
#include <nanotekspice/components/special/OutputComponent.hh>

/* Constructor & Destructor */

nts::OutputComponent::OutputComponent(const std::string &cname)
{
    this->type = nts::ComponentType::Output;
    this->name = cname;
}

/* Methods */

nts::Tristate nts::OutputComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    this->currentState = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(1) != this->pin_to_pin.end() &&
        this->pin_to_component.find(1) != this->pin_to_component.end())
        this->currentState = this->pin_to_component.at(1).get().compute(this->pin_to_pin[1]);
    return this->currentState;
}

nts::Tristate nts::OutputComponent::getLastState()
{
    return this->currentState;
}
