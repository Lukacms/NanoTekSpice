/*
** EPITECH PROJECT, 2023
** commands
** File description:
** simulate
*/

#include <nanotekspice/Circuit.hh>
#include <nanotekspice/Simulator.hh>

int nts::simulate(nts::Circuit &circuit, std::string __attribute__((unused)) & line)
{
    circuit.addTick();
    for (auto component = circuit.getComponentList().begin();
         component != circuit.getComponentList().end(); component++)
        component->get()->simulate(circuit.getTick());
    return EPITECH_SUCCESS;
}
