/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4094Component
*/

#include <nanotekspice/components/advanced/4094Component.hh>

// ctor / dtor

nts::EightBitShifterComponent::EightBitShifterComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::EightBitShifterComponent::compute(std::size_t pin)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::EightBitShifterComponent::computeSpecificPin(std::size_t first_input,
                                                                std::size_t second_input)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::EightBitShifterComponent::computeCarryOut(std::size_t first_input,
                                                             std::size_t second_input)
{
    return nts::Tristate::Undefined;
}
