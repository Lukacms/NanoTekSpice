/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Circuit
*/

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <memory>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/components/IComponent.hh>
#include <utility>
#include <vector>

// methods

std::vector<std::unique_ptr<nts::IComponent>> &nts::Circuit::getComponentList()
{
    return this->component_list;
}

void nts::Circuit::addComponent(std::unique_ptr<nts::IComponent> new_component)
{
    this->component_list.emplace_back(std::move(new_component));
}

std::reference_wrapper<nts::IComponent> nts::Circuit::getComponentByName(const std::string &name)
{
    for (auto &component : this->component_list) {
        if (component->getName() == name)
            return std::ref(*component);
    }
    throw nts::Circuit::CircuitError();
}

// ctor by copy
nts::Circuit::Circuit(nts::Circuit &to_copy)
{
    for (auto component = to_copy.component_list.begin(); component < to_copy.component_list.end();
         component++)
        this->component_list.emplace_back(std::move(*component));
}

nts::Circuit &nts::Circuit::operator=(Circuit &to_copy)
{
    for (auto component = to_copy.component_list.begin(); component < to_copy.component_list.end();
         component++)
        this->component_list.emplace_back(std::move(*component));
    return *this;
}

// dtor

nts::Circuit::~Circuit() {}

// getters / setters
std::size_t nts::Circuit::getTick() const
{
    return this->ticks;
}

void nts::Circuit::addTick()
{
    this->ticks++;
}
