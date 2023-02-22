/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 2716Component
*/

#include "nanotekspice/components/IComponent.hh"
#include <nanotekspice/components/advanced/2716Component.hh>
#include <string>

// ctor / dtor

nts::ReadOnlyComponent::ReadOnlyComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::ReadOnlyComponent::compute(std::size_t pin)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::ReadOnlyComponent::computeSpecificPin(std::size_t first_input,
                                                         std::size_t second_input)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::ReadOnlyComponent::computeCarryOut(std::size_t first_input,
                                                      std::size_t second_input)
{
    return nts::Tristate::Undefined;
}
