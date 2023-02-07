/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4069Component
*/

#include <nanotekspice/components/gates/4069Component.hh>

/* Constructor & Destructor */

nts::SixNotComponent::SixNotComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::SixNotComponent::compute(std::size_t pin)
{
    if (pin == 2)
        return this->computeSpecificPin(1);
    if (pin == 4)
        return this->computeSpecificPin(3);
    if (pin == 6)
        return this->computeSpecificPin(5);
    if (pin == 8)
        return this->computeSpecificPin(9);
    if (pin == 10)
        return this->computeSpecificPin(11);
    return this->computeSpecificPin(13);
}

nts::Tristate nts::SixNotComponent::computeSpecificPin(std::size_t pin1, std::size_t pin2)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    (void)pin2;

    if (this->pin_to_pin.find(pin1) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin1) != this->pin_to_component.end())
        input1 = this->pin_to_component[pin1]->compute(this->pin_to_pin[pin1]);
    if (input1 == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (input1 == nts::Tristate::True)
        return nts::Tristate::False;
    return nts::Tristate::True;
}
