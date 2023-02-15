/*
** EPITECH PROJECT, 2023
** commands
** File description:
** simulate
*/

#include "nanotekspice/Circuit.hh"

int nts::simulate(nts::Circuit &circuit, std::string __attribute__((unused)) & line)
{
    circuit.addTick();
    return EPITECH_SUCCESS;
}
