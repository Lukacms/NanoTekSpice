/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Circuit
*/

#include <cstddef>
#include <iostream>
#include <memory>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/components/IComponent.hh>
#include <utility>
#include <vector>

std::vector<std::unique_ptr<nts::IComponent>> &nts::Circuit::getComponentList()
{
    return this->component_list;
}

void nts::Circuit::addComponent(std::unique_ptr<nts::IComponent> new_component)
{
    this->component_list.emplace_back(std::move(new_component));
}

// ctor by copy
nts::Circuit::Circuit(const nts::Circuit &to_copy)
{
    for (std::size_t i = 0; to_copy.component_list[i]; i++)
        this->component_list.emplace_back(std::move(to_copy.component_list[i].get()));
}

nts::Circuit &nts::Circuit::operator=(Circuit &to_copy)
{
    /* for (auto component : to_copy.getComponentList().begin())
        std::cout << component << "\n"; */
    return *this;
}
