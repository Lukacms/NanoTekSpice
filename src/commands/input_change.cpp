/*
** EPITECH PROJECT, 2023
** commands
** File description:
** input_change
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/Simulator.hh>
#include <nanotekspice/components/IComponent.hh>
#include <nanotekspice/components/special/InputComponent.hh>
#include <sstream>
#include <string>
#include <vector>

static const std::map<std::string, nts::Tristate> NEW_VALUE = {
    {"1", nts::Tristate::True}, {"0", nts::Tristate::False}, {"U", nts::Tristate::Undefined}};

static nts::Tristate getInputNewValue(const std::string &line)
{
    if (NEW_VALUE.contains(line))
        return NEW_VALUE.find(line)->second;
    throw nts::LoopException(LOOP_WRONG_INPUT_VALUE);
}

int nts::input_change(nts::Circuit &circuit, std::string &line)
{
    std::vector<std::string> changes;
    std::stringstream stream;
    std::string tmp;

    std::replace(line.begin(), line.end(), '=', ' ');
    stream << line;
    while (!stream.eof()) {
        stream >> tmp;
        changes.push_back(tmp);
    }
    if (changes.size() != 2)
        throw nts::LoopException(LOOP_INPUT_WRONG_ARG_NB);
    try {
        circuit.changeValueOfComponent(changes[0], getInputNewValue(changes[1]));
    } catch (nts::Circuit::CircuitError &e) {
        std::cout << std::string{e.what()} << "\n";
    } catch (nts::LoopException &e) {
        std::cout << std::string{e.what()} << "\n";
    }
    return EPITECH_SUCCESS;
}
