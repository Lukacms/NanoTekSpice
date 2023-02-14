/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** main
*/

#include "nanotekspice/parsing/Parser.hh"
#include <iostream>
#include <memory>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/components/elementary/NotComponent.hh>
#include <nanotekspice/components/gates/4071Component.hh>
#include <nanotekspice/components/special/FalseComponent.hh>
#include <nanotekspice/components/special/OutputComponent.hh>
#include <nanotekspice/components/special/TrueComponent.hh>
#include <string>

int main(int argc, char *const argv[])
{
    std::string filename{argv[1]};
    try {
        nts::Parser::parse(filename);
    } catch (nts::Parser::ParserException &e) {
        std::cout << "Exception while parsing: " << e.what() << "\n";
        return EPITECH_FAILURE;
    }
    return EPITECH_SUCCESS;
}
