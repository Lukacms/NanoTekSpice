/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** AndComponent
*/

#include <nanotekspice/components/elementary/AndComponent.hh>

/* Constructor & Destructor */

nts::AndComponent::AndComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::AndComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    nts::Tristate input2 = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(1) != this->pin_to_pin.end() ||
        this->pin_to_component.find(1) != this->pin_to_component.end())
        input1 = this->pin_to_component[1]->compute(this->pin_to_pin[1]);
    if (this->pin_to_pin.find(2) != this->pin_to_pin.end() ||
        this->pin_to_component.find(2) != this->pin_to_component.end())
        input2 = this->pin_to_component[2]->compute(this->pin_to_pin[2]);
    if ((input1 == nts::Tristate::False && input2 == nts::Tristate::False) ||
        (input1 == nts::Tristate::False && input2 == nts::Tristate::True) ||
        (input1 == nts::Tristate::True && input2 == nts::Tristate::False) ||
        (input1 == nts::Tristate::False && input2 == nts::Tristate::Undefined) ||
        (input1 == nts::Tristate::Undefined && input2 == nts::Tristate::False))
        return nts::Tristate::False;
    if (input1 == nts::Tristate::True && input2 == nts::Tristate::True)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}