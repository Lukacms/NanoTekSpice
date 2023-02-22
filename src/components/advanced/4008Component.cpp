/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** 4008Component
*/

#include <nanotekspice/components/advanced/4008Component.hh>

/* Constructor & Destructor */

nts::FourBitAdderComponent::FourBitAdderComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::FourBitAdderComponent::compute(std::size_t pin)
{
    if (pin == chip_pin10)
        return this->computeSpecificPin(chip_pin7, chip_pin6);
    if (pin == chip_pin11)
        return this->computeSpecificPin(chip_pin5, chip_pin4);
    if (pin == chip_pin12)
        return this->computeSpecificPin(chip_pin3, chip_pin2);
    if (pin == chip_pin13)
        return this->computeSpecificPin(chip_pin1, chip_pin15);
    if (pin == chip_pin14)
        return this->computeCarryOut(chip_pin7, chip_pin6);
    return nts::Tristate::False;
}

nts::Tristate nts::FourBitAdderComponent::computeSpecificPin(std::size_t pin1, std::size_t pin2)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    nts::Tristate input2 = nts::Tristate::Undefined;
    nts::Tristate input3 = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(pin1) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin1) != this->pin_to_component.end())
        input1 = this->pin_to_component.at(pin1).get().compute(this->pin_to_pin[pin1]);
    if (this->pin_to_pin.find(pin2) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin2) != this->pin_to_component.end())
        input2 = this->pin_to_component.at(pin2).get().compute(this->pin_to_pin[pin2]);
    if (this->pin_to_pin.find(chip_pin9) != this->pin_to_pin.end() &&
        this->pin_to_component.find(chip_pin9) != this->pin_to_component.end())
        input3 = this->pin_to_component.at(chip_pin9).get().compute(this->pin_to_pin[chip_pin9]);
    return nts::notFunction(static_cast<nts::Tristate>(input1 ^ input2 ^ input3));
}

nts::Tristate nts::FourBitAdderComponent::computeCarryOut(std::size_t a_pin, std::size_t b_pin)
{
    nts::Tristate input_a = nts::Tristate::Undefined;
    nts::Tristate input_b = nts::Tristate::Undefined;
    nts::Tristate input_c = nts::Tristate::Undefined;

    if (b_pin > chip_pin15)
        b_pin = chip_pin2;
    if (this->pin_to_pin.find(a_pin) != this->pin_to_pin.end() &&
        this->pin_to_component.find(a_pin) != this->pin_to_component.end())
        input_a = this->pin_to_component.at(a_pin).get().compute(this->pin_to_pin[a_pin]);
    if (this->pin_to_pin.find(b_pin) != this->pin_to_pin.end() &&
        this->pin_to_component.find(b_pin) != this->pin_to_component.end())
        input_b = this->pin_to_component.at(b_pin).get().compute(this->pin_to_pin[b_pin]);
    if (this->pin_to_pin.find(chip_pin9) != this->pin_to_pin.end() &&
        this->pin_to_component.find(chip_pin9) != this->pin_to_component.end())
        input_c = this->pin_to_component.at(chip_pin9).get().compute(this->pin_to_pin[chip_pin9]);
    if (a_pin == chip_pin7 && b_pin == chip_pin6)
        return static_cast<nts::Tristate>((input_a * input_b) + (input_c * (input_a ^ input_b)));
    return nts::notFunction(static_cast<nts::Tristate>(
        (input_a * input_b) + (this->computeCarryOut(a_pin + 2, b_pin + 2) * (input_a ^ input_b))));
}
