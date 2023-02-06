/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** Circuit
*/

#include <nanotekspice/Circuit.hh>

/* Methods */

std::vector<nts::IComponent *> nts::Circuit::getComponentList()
{
    return this->component_list;
}

void nts::Circuit::addComponent(nts::IComponent &new_component)
{
    this->component_list.push_back(&new_component);
}
