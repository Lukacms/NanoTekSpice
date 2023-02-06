/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** TrueComponent
*/

#include <nanotekspice/components/special/TrueComponent.hh>

/* Constructor */

nts::TrueComponent::TrueComponent(std::string cname)
{
    this->name = cname;
    return;
}

/* Methods */

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    return nts::Tristate::True;
}