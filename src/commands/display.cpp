/*
** EPITECH PROJECT, 2023
** commands
** File description:
** display
*/

#include "nanotekspice/Circuit.hh"
#include "nanotekspice/components/IComponent.hh"
#include <functional>
#include <iostream>
#include <vector>

int nts::display(nts::Circuit &circuit, std::string __attribute__((unused)) & line)
{
    std::vector<std::reference_wrapper<nts::IComponent>> inputs =
        circuit.getComponentsByType(nts::ComponentType::Input);
    std::vector<std::reference_wrapper<nts::IComponent>> outputs =
        circuit.getComponentsByType(nts::ComponentType::Output);

    std::cout << "tick: " << circuit.getTick() << "\n";
    std::cout << "input(s):\n";
    for (auto input = inputs.begin(); input != inputs.end(); input++)
        std::cout << "\t" << input->get().getName() << ": " << input->get().compute(UNUSED_PIN)
                  << "\n";
    std::cout << "output(s):\n";
    for (auto output = outputs.begin(); output != outputs.end(); output++)
        std::cout << "\t" << output->get().getName() << ": " << output->get().compute(UNUSED_PIN)
                  << "\n";
    return EPITECH_SUCCESS;
}
