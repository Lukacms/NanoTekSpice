/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** FalseComponent
*/

#include <nanotekspice/components/special/FalseComponent.hh>

/* Constructor */

nts::FalseComponent::FalseComponent(const std::string &cname)
{
    this->name = cname;
}

/* Methods */

nts::Tristate nts::FalseComponent::compute(std::size_t pin __attribute_maybe_unused__)
{
    return nts::Tristate::False;
}
