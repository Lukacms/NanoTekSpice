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
    if (pin == chip_pin2)
        return this->computeSpecificPin(chip_pin1);
    if (pin == chip_pin4)
        return this->computeSpecificPin(chip_pin3);
    if (pin == chip_pin6)
        return this->computeSpecificPin(chip_pin5);
    if (pin == chip_pin8)
        return this->computeSpecificPin(chip_pin9);
    if (pin == chip_pin10)
        return this->computeSpecificPin(chip_pin11);
    return this->computeSpecificPin(chip_pin13);
}

nts::Tristate nts::SixNotComponent::computeSpecificPin(std::size_t pin1, std::size_t pin2)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    (void)pin2;

    if (this->pin_to_pin.find(pin1) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin1) != this->pin_to_component.end())
        input1 = this->pin_to_component.at(pin1).get().compute(this->pin_to_pin[pin1]);
    return nts::notFunction(input1);
}
