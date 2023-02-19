/*
** EPITECH PROJECT, 2023
** commands
** File description:
** display
*/

#include <functional>
#include <iostream>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/Simulator.hh>
#include <nanotekspice/components/IComponent.hh>
#include <vector>

static void display_state(nts::Tristate state)
{
    switch (state) {
        case nts::Tristate::False: std::cout << "0"; break;
        case nts::Tristate::True: std::cout << "1"; break;
        case nts::Tristate::Undefined: std::cout << "U";
    }
    std::cout << "\n";
}

int nts::display(nts::Circuit &circuit, std::string __attribute__((unused)) & line)
{
    std::vector<std::reference_wrapper<nts::IComponent>> inputs =
        circuit.getComponentsByType(nts::ComponentType::Input);
    std::vector<std::reference_wrapper<nts::IComponent>> outputs =
        circuit.getComponentsByType(nts::ComponentType::Output);

    std::cout << "tick: " << circuit.getTick() << "\n";
    std::cout << "input(s):\n";
    for (auto input = inputs.begin(); input != inputs.end(); input++) {
        std::cout << "  " << input->get().getName() << ": ";
        display_state(input->get().compute(UNUSED_PIN));
    }
    std::cout << "output(s):\n";
    for (auto output = outputs.begin(); output != outputs.end(); output++) {
        std::cout << "  " << output->get().getName() << ": ";
        display_state(output->get().compute(UNUSED_PIN));
    }
    return EPITECH_SUCCESS;
}
