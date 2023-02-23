/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4090Component
*/

#include <nanotekspice/components/advanced/4040Component.hh>

// ctor / dtor

nts::TwelveBitCounterComponent::TwelveBitCounterComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::TwelveBitCounterComponent::compute(std::size_t /* pin */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::TwelveBitCounterComponent::computeSpecificPin(std::size_t /* first_input */,
                                                                 std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::TwelveBitCounterComponent::computeCarryOut(std::size_t /* first_input */,
                                                              std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}
