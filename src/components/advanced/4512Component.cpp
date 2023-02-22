/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4512Component
*/

#include <nanotekspice/components/advanced/4512Component.hh>

// ctor / dtor

nts::EightChannelSelectorComponent::EightChannelSelectorComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::EightChannelSelectorComponent::compute(std::size_t pin)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::EightChannelSelectorComponent::computeSpecificPin(std::size_t first_input,
                                                                     std::size_t second_input)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::EightChannelSelectorComponent::computeCarryOut(std::size_t first_input,
                                                                  std::size_t second_input)
{
    return nts::Tristate::Undefined;
}
