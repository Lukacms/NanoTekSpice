/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** OutputComponent
*/

#include <nanotekspice/components/special/OutputComponent.hh>

/* Constructor & Destructor */

nts::OutputComponent::OutputComponent(std::string cname)
{
    this->name = cname;
    return;
}

nts::OutputComponent::~OutputComponent() {}

/* Methods */

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    this->currentState = this->pin_to_component[1].compute(this->pin_to_pin[1]);
    return;
}