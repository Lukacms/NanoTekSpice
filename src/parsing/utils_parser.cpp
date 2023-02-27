/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** utils_parser
*/

#include "nanotekspice/Circuit.hh"
#include "nanotekspice/components/AComponent.hh"
#include "nanotekspice/components/IComponent.hh"
#include <functional>
#include <iostream>
#include <nanotekspice/parsing/Parser.hh>
#include <string>
#include <vector>

// outside of class

std::string nts::without_comment(const std::string &src)
{
    std::string dest = src.substr(0, src.find(PARSER_COMMENT_INDICATOR));
    auto idest = dest.end();

    while (idest != dest.begin()) {
        if (*idest != ' ' && *idest != '\0' && *idest != '\t') {
            idest++;
            break;
        }
        idest--;
    }
    dest.erase(idest, dest.end());
    return dest;
}

bool nts::checkInfinLoop(nts::Circuit &circuit)
{
    std::vector<std::reference_wrapper<nts::IComponent>> outputs =
        circuit.getComponentsByType(nts::ComponentType::Output);

    for (auto output = outputs.begin(); output < outputs.end(); output++) {
        if (output->get().getNumberOfComponents() > 1)
            return false;
    }
    return true;
}

// in Parser class

bool nts::hasChipset(const std::string &name, nts::Circuit &circuit)
{
    for (auto component = circuit.getComponentList().begin();
         component != circuit.getComponentList().end(); component++) {
        if (component->get()->getName() == name)
            return true;
    }
    return false;
}
