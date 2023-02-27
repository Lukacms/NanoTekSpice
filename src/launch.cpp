/*
** EPITECH PROJECT, 2023
** src
** File description:
** launch
*/

#include <exception>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/Simulator.hh>
#include <string>

static const std::map<const std::string, std::function<int(nts::Circuit &, std::string &)>>
    COMMANDS_MAP = {{"display", &nts::display},
                    {"loop", &nts::loop},
                    {"simulate", &nts::simulate},
                    {"", &nts::input_change}};

static int analyse_input(std::string &line, nts::Circuit &circuit)
{
    if (COMMANDS_MAP.contains(line))
        return COMMANDS_MAP.find(line)->second(circuit, line);
    return nts::input_change(circuit, line);
}

int nts::main_loop(nts::Circuit &circuit)
{
    std::string line;

    if (circuit.getComponentList().empty()) {
        std::cout << "Loop does not have any component to work with.\n";
        return EPITECH_FAILURE;
    }
    while (line != "exit") {
        std::cout << "> ";
        if (std::getline(std::cin, line).eof())
            break;
        try {
            analyse_input(line, circuit);
        } catch (std::exception &) {
            continue;
        }
    }
    return EPITECH_SUCCESS;
}
