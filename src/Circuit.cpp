/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** Circuit
*/

#include <nanotekspice/Circuit.hh>

/* Constructor & Destructor */

nts::Circuit::Circuit() {}

nts::Circuit::~Circuit() {}

/* Methods */

std::vector<nts::IComponent> nts::Circuit::getComponentList()
{
    return this->component_list;
}