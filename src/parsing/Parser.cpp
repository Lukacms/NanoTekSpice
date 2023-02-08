/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** Parser
*/

#include <fstream>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/parsing/Parser.hh>

// static function
nts::Circuit nts::Parser::parse(std::string &filename)
{
    std::ifstream stream{filename};
    nts::Parser parser{stream};

    return parser.doParsing();
}
