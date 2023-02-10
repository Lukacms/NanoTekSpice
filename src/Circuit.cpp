/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Circuit
*/

#include <memory>
#include <memory>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/components/IComponent.hh>
#include <vector>

using std::make_unique;
#include <nanotekspice/components/IComponent.hh>
#include <vector>

std::vector<std::unique_ptr<nts::IComponent>> &nts::Circuit::getComponentList()
{
    return this->component_list;
}

void nts::Circuit::addComponent(std::unique_ptr<nts::IComponent> new_component)
{
    this->component_list.emplace_back(std::move(new_component));
}
