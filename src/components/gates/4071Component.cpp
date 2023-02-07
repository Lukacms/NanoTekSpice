/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4071Component
*/

#include <nanotekspice/components/gates/4071Component.hh>

/* Constructor & Destructor */

nts::FourOrComponent::FourOrComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::FourOrComponent::compute(std::size_t pin)
{
    if (pin == 3)
        return this->computeSpecificPin(1, 2);
    if (pin == 4)
        return this->computeSpecificPin(5, 6);
    if (pin == 10)
        return this->computeSpecificPin(8, 9);
    return this->computeSpecificPin(12, 13);
}

nts::Tristate nts::FourOrComponent::computeSpecificPin(std::size_t pin1, std::size_t pin2)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    nts::Tristate input2 = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(pin1) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin1) != this->pin_to_component.end())
        input1 = this->pin_to_component[pin1]->compute(this->pin_to_pin[pin1]);
    if (this->pin_to_pin.find(pin2) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin2) != this->pin_to_component.end())
        input2 = this->pin_to_component[pin2]->compute(this->pin_to_pin[pin2]);
    if ((input1 == nts::Tristate::False && input2 == nts::Tristate::False))
        return nts::Tristate::False;
    if ((input1 == nts::Tristate::True && input2 == nts::Tristate::False) ||
        (input1 == nts::Tristate::False && input2 == nts::Tristate::True) ||
        (input1 == nts::Tristate::True && input2 == nts::Tristate::True) ||
        (input1 == nts::Tristate::Undefined && input2 == nts::Tristate::True) ||
        (input1 == nts::Tristate::True && input2 == nts::Tristate::Undefined))
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}
