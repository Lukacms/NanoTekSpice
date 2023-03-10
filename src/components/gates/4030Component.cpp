/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4030Component
*/

#include <nanotekspice/components/gates/4030Component.hh>

/* Constructor & Destructor */

nts::FourXorComponent::FourXorComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::FourXorComponent::compute(std::size_t pin)
{
    if (pin == chip_pin3)
        return this->computeSpecificPin(chip_pin1, chip_pin2);
    if (pin == chip_pin4)
        return this->computeSpecificPin(chip_pin5, chip_pin6);
    if (pin == chip_pin10)
        return this->computeSpecificPin(chip_pin8, chip_pin9);
    return this->computeSpecificPin(chip_pin12, chip_pin13);
}

nts::Tristate nts::FourXorComponent::computeSpecificPin(std::size_t pin1, std::size_t pin2)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    nts::Tristate input2 = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(pin1) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin1) != this->pin_to_component.end())
        input1 = this->pin_to_component.at(pin1).get().compute(this->pin_to_pin[pin1]);
    if (this->pin_to_pin.find(pin2) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin2) != this->pin_to_component.end())
        input2 = this->pin_to_component.at(pin2).get().compute(this->pin_to_pin[pin2]);
    return nts::xorFunction(input1, input2);
}
