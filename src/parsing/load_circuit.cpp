/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** load_circuit
*/

#include <nanotekspice/Circuit.hh>
#include <nanotekspice/parsing/Parser.hh>

// file in which the parsing will be done

nts::Circuit &nts::Parser::doParsing()
{
    return this->circuit;
}
