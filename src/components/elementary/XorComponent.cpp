/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** XorComponent
*/

#include <nanotekspice/components/elementary/XorComponent.hh>

/* Constructor & Destructor */

nts::XorComponent::XorComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::XorComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    nts::Tristate input2 = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(1) != this->pin_to_pin.end() ||
        this->pin_to_component.find(1) != this->pin_to_component.end())
        input1 = this->pin_to_component.at(1).get().compute(this->pin_to_pin[1]);
    if (this->pin_to_pin.find(2) != this->pin_to_pin.end() ||
        this->pin_to_component.find(2) != this->pin_to_component.end())
        input2 = this->pin_to_component.at(2).get().compute(this->pin_to_pin[2]);
    return nts::xorFunction(input1, input2);
}
