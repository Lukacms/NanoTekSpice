/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4013Component
*/

// ctor / dtor

#include "nanotekspice/components/advanced/4013Component.hh"

nts::DualFlipFlopComponent::DualFlipFlopComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::DualFlipFlopComponent::compute(std::size_t pin)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::DualFlipFlopComponent::computeSpecificPin(std::size_t first_input,
                                                             std::size_t second_input)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::DualFlipFlopComponent::computeCarryOut(std::size_t first_input,
                                                          std::size_t second_input)
{
    return nts::Tristate::Undefined;
}
