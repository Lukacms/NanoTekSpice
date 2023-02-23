/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4801Component
*/

#include <nanotekspice/components/advanced/4801Component.hh>

// ctor / dtor

nts::RandomMemAccessComponent::RandomMemAccessComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::RandomMemAccessComponent::compute(std::size_t /* pin */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::RandomMemAccessComponent::computeSpecificPin(std::size_t /* first_input */,
                                                                std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::RandomMemAccessComponent::computeCarryOut(std::size_t /* first_input */,
                                                             std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}
