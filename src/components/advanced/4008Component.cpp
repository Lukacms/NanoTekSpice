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
    if (pin == Out0)
        return this->computeSpecificPin(InA1, InB1);
    if (pin == Out1)
        return this->computeSpecificPin(InA2, InB2);
    if (pin == Out2)
        return this->computeSpecificPin(InA3, InB3);
    if (pin == Out3)
        return this->computeSpecificPin(InA4, InB4);
    if (pin == CarryOut)
        return this->computeCarryOut(InA1, InB1);
    return nts::Tristate::False;
}

nts::Tristate nts::FourBitAdderComponent::computeSpecificPin(std::size_t pin1, std::size_t pin2)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    nts::Tristate input2 = nts::Tristate::Undefined;
    nts::Tristate input3 = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(pin1) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin1) != this->pin_to_component.end())
        input1 = this->pin_to_component[pin1]->compute(this->pin_to_pin[pin1]);
    if (this->pin_to_pin.find(pin2) != this->pin_to_pin.end() &&
        this->pin_to_component.find(pin2) != this->pin_to_component.end())
        input2 = this->pin_to_component[pin2]->compute(this->pin_to_pin[pin2]);
    if (this->pin_to_pin.find(CarryIn) != this->pin_to_pin.end() &&
        this->pin_to_component.find(CarryIn) != this->pin_to_component.end())
        input3 = this->pin_to_component[CarryIn]->compute(this->pin_to_pin[CarryIn]);
    return static_cast<nts::Tristate>(input1 ^ input2 ^ input3);
}

nts::Tristate nts::FourBitAdderComponent::computeCarryOut(std::size_t a_pin, std::size_t b_pin)
{
    nts::Tristate input_a = nts::Tristate::Undefined;
    nts::Tristate input_b = nts::Tristate::Undefined;
    nts::Tristate input_c = nts::Tristate::Undefined;

    if (b_pin == 0)
        b_pin = InB4;
    if (this->pin_to_pin.find(a_pin) != this->pin_to_pin.end() &&
        this->pin_to_component.find(a_pin) != this->pin_to_component.end())
        input_a = this->pin_to_component[a_pin]->compute(this->pin_to_pin[a_pin]);
    if (this->pin_to_pin.find(b_pin) != this->pin_to_pin.end() &&
        this->pin_to_component.find(b_pin) != this->pin_to_component.end())
        input_b = this->pin_to_component[b_pin]->compute(this->pin_to_pin[b_pin]);
    if (this->pin_to_pin.find(CarryIn) != this->pin_to_pin.end() &&
        this->pin_to_component.find(CarryIn) != this->pin_to_component.end())
        input_c = this->pin_to_component[CarryIn]->compute(this->pin_to_pin[CarryIn]);
    if (a_pin == InA1 && b_pin == InB1)
        return static_cast<nts::Tristate>((input_a * input_b) + (input_c * (input_a ^ input_b)));
    return static_cast<nts::Tristate>(
        (input_a * input_b) + (this->computeCarryOut(a_pin - 2, b_pin - 2) * (input_a ^ input_b)));
}
