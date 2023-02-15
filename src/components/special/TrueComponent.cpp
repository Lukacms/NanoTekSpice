/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** TrueComponent
*/

#include <nanotekspice/components/special/TrueComponent.hh>

/* Constructor */

nts::TrueComponent::TrueComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::TrueComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    return nts::Tristate::True;
}
