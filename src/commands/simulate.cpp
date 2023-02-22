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
    std::vector<std::reference_wrapper<nts::IComponent>> inputs =
        circuit.getComponentsByType(nts::ComponentType::Input);
    std::vector<std::reference_wrapper<nts::IComponent>> outputs =
        circuit.getComponentsByType(nts::ComponentType::Output);
    std::vector<std::reference_wrapper<nts::IComponent>> others =
        circuit.getComponentsByType(nts::ComponentType::Other);
    std::vector<std::reference_wrapper<nts::IComponent>> clocks =
        circuit.getComponentsByType(nts::ComponentType::Clock);

    circuit.addTick();
    for (auto input = inputs.begin(); input != inputs.end(); input++)
        input->get().simulate(1);
    for (auto clock = clocks.begin(); clock != clocks.end(); clock++)
        clock->get().simulate(1);
    for (auto other = others.begin(); other != others.end(); other++)
        other->get().simulate(1);
    for (auto output = outputs.begin(); output != outputs.end(); output++)
        output->get().simulate(1);
    return EPITECH_SUCCESS;
}
