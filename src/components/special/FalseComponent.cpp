/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** FalseComponent
*/

#include <nanotekspice/components/special/FalseComponent.hh>

/* Constructor */

nts::FalseComponent::FalseComponent(std::string cname)
{
    this->name = cname;
    return;
}

/* Methods */

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    return nts::Tristate::False;
}