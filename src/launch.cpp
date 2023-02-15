/*
** EPITECH PROJECT, 2023
** src
** File description:
** launch
*/

#include "nanotekspice/Circuit.hh"
#include <iostream>
#include <istream>
#include <string>

int nts::main_loop(nts::Circuit &circuit)
{
    std::string line;

    if (circuit.getComponentList().empty())
        return EPITECH_FAILURE;
    std::cout << "> ";
    while (!std::getline(std::cin, line).eof() && line != "exit") {
        std::cout << "> ";
    }
    return EPITECH_SUCCESS;
}
