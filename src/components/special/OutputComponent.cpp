/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** OutputComponent
*/

#include <nanotekspice/components/special/OutputComponent.hh>
#include <iostream>


/* Constructor & Destructor */

nts::OutputComponent::OutputComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::OutputComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    this->currentState = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(1) != this->pin_to_pin.end() &&
        this->pin_to_component.find(1) != this->pin_to_component.end()) {
        std::cout << "Here\n";
        this->currentState = this->pin_to_component[1]->compute(this->pin_to_pin[1]);
    }
    return this->currentState;
}

nts::Tristate nts::OutputComponent::getLastState()
{
    return this->currentState;
}
