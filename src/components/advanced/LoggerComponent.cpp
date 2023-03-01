/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** LoggerComponent
*/

#include <nanotekspice/components/advanced/LoggerComponent.hh>

// ctor / dtor

nts::LoggerComponent::LoggerComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::LoggerComponent::compute(std::size_t /* pin */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::LoggerComponent::computeSpecificPin(std::size_t /* first_input */,
                                                       std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::LoggerComponent::computeCarryOut(std::size_t /* first_input */,
                                                    std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}
