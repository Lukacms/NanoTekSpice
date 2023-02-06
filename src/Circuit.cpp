/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Circuit
*/

#include "nanotekspice/components/IComponent.hh"
#include <memory>
#include <nanotekspice/Circuit.hh>
#include <vector>

using std::make_unique;

std::vector<nts::IComponent *> nts::Circuit::getComponentList()
{
    return this->component_list;
}

void nts::Circuit::addComponent(nts::IComponent &new_component)
{
    this->component_list.emplace_back(&new_component);
}
