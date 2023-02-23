/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4514Component
*/

#include <nanotekspice/components/advanced/4514Component.hh>

// ctor / dtor

nts::FourBitDecoderComponent::FourBitDecoderComponent(const std::string &pname)
{
    this->name = pname;
}

nts::Tristate nts::FourBitDecoderComponent::compute(std::size_t /* pin */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::FourBitDecoderComponent::computeSpecificPin(std::size_t /* first_input */,
                                                               std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}

nts::Tristate nts::FourBitDecoderComponent::computeCarryOut(std::size_t /* first_input */,
                                                            std::size_t /* second_input */)
{
    return nts::Tristate::Undefined;
}
