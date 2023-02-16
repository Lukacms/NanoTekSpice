/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** main
*/

#include <iostream>
#include <memory>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/Simulator.hh>
#include <nanotekspice/components/elementary/NotComponent.hh>
#include <nanotekspice/components/gates/4071Component.hh>
#include <nanotekspice/components/special/FalseComponent.hh>
#include <nanotekspice/components/special/OutputComponent.hh>
#include <nanotekspice/components/special/TrueComponent.hh>
#include <nanotekspice/parsing/Parser.hh>
#include <string>

static int display_help()
{
    std::cout << HELP << "\n";
    return EPITECH_FAILURE;
}

int main(int argc, char *const argv[])
{
    std::string filename;
    nts::Circuit circuit;

    if (argc != 2)
        return display_help();
    filename = std::string{argv[1]};
    try {
        // when doing that, destructor segfault
        // circuit = nts::Parser::parse(filename);
        // circuit = std::move(nts::Parser::parse(filename));
        nts::Parser::parse(filename, circuit);
    } catch (nts::Parser::ParserException &e) {
        std::cout << "Exception while parsing: " << e.what() << "\n";
        return EPITECH_FAILURE;
    }
    return nts::main_loop(circuit);
}
