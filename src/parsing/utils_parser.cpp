/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** utils_parser
*/

#include "nanotekspice/Circuit.hh"
#include "nanotekspice/components/AComponent.hh"
#include <nanotekspice/parsing/Parser.hh>
#include <string>

// outside of class

std::string nts::without_comment(const std::string &src)
{
    std::string dest = src.substr(0, src.find(PARSER_COMMENT_INDICATOR));

    return dest;
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
