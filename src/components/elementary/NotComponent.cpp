/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** NotComponent
*/

#include <nanotekspice/components/elementary/NotComponent.hh>

/* Constructor & Destructor */

nts::NotComponent::NotComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::NotComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    nts::Tristate input = nts::Tristate::Undefined;

    if (this->pin_to_pin.find(1) != this->pin_to_pin.end() ||
        this->pin_to_component.find(1) != this->pin_to_component.end())
        input = this->pin_to_component[1]->compute(this->pin_to_pin[1]);
    if (input == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (input == nts::Tristate::True)
        return nts::Tristate::False;
    return nts::Tristate::True;
}
