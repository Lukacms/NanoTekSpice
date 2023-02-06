/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** FalseComponent
*/

#include <nanotekspice/components/FalseComponent.hh>

/* Constructor & Destructor */

nts::FalseComponent::~FalseComponent() {}

/* Methods */

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    return nts::Tristate::False;
}