/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4017Component
*/

#include <nanotekspice/components/advanced/4017Component.hh>

// ctor / dtor

nts::TenBitJohnsonComponent::TenBitJohnsonComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::TenBitJohnsonComponent::compute(std::size_t /* pin */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::TenBitJohnsonComponent::computeSpecificPin(std::size_t /* first_input */,
                                                              std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::TenBitJohnsonComponent::computeCarryOut(std::size_t /* first_input */,
                                                           std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}
