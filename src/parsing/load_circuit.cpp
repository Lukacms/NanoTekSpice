/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** load_circuit
*/

#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/components/IComponent.hh>
#include <nanotekspice/components/advanced/4008Component.hh>
#include <nanotekspice/components/elementary/AndComponent.hh>
#include <nanotekspice/components/elementary/NotComponent.hh>
#include <nanotekspice/components/elementary/OrComponent.hh>
#include <nanotekspice/components/elementary/XorComponent.hh>
#include <nanotekspice/components/gates/4001Component.hh>
#include <nanotekspice/components/gates/4011Component.hh>
#include <nanotekspice/components/gates/4030Component.hh>
#include <nanotekspice/components/gates/4069Component.hh>
#include <nanotekspice/components/gates/4071Component.hh>
#include <nanotekspice/components/gates/4081Component.hh>
#include <nanotekspice/components/special/ClockComponent.hh>
#include <nanotekspice/components/special/FalseComponent.hh>
#include <nanotekspice/components/special/InputComponent.hh>
#include <nanotekspice/components/special/OutputComponent.hh>
#include <nanotekspice/components/special/TrueComponent.hh>
#include <nanotekspice/parsing/Parser.hh>
#include <string>

// file in which the parsing will be done

static const std::map<const std::string,
                      std::function<std::unique_ptr<nts::IComponent>(const std::string &)>>
    COMPONENTS_MAP{
        {"input",
         [](const std::string &name) -> std::unique_ptr<nts::IComponent> {
             return std::make_unique<nts::InputComponent>(name);
         }},
        {"output",
         [](const std::string &name) {
             return std::make_unique<nts::OutputComponent>(name);
         }},
        {"true",
         [](const std::string &name) {
             return std::make_unique<nts::TrueComponent>(name);
         }},
        {"false",
         [](const std::string &name) {
             return std::make_unique<nts::FalseComponent>(name);
         }},
        {"clock",
         [](const std::string &name) {
             return std::make_unique<nts::ClockComponent>(name);
         }},
        {"and",
         [](const std::string &name) {
             return std::make_unique<nts::AndComponent>(name);
         }},
        {"or",
         [](const std::string &name) {
             return std::make_unique<nts::OrComponent>(name);
         }},
        {"xor",
         [](const std::string &name) {
             return std::make_unique<nts::XorComponent>(name);
         }},
        {"not",
         [](const std::string &name) {
             return std::make_unique<nts::NotComponent>(name);
         }},
        {"4001",
         [](const std::string &name) {
             return std::make_unique<nts::FourNorComponent>(name);
         }},
        {"4011",
         [](const std::string &name) {
             return std::make_unique<nts::FourNandComponent>(name);
         }},
        {"4030",
         [](const std::string &name) {
             return std::make_unique<nts::FourXorComponent>(name);
         }},
        {"4069",
         [](const std::string &name) {
             return std::make_unique<nts::SixNotComponent>(name);
         }},
        {"4071",
         [](const std::string &name) {
             return std::make_unique<nts::FourOrComponent>(name);
         }},
        {"4081",
         [](const std::string &name) {
             return std::make_unique<nts::FourAndComponent>(name);
         }},
        {"4008",
         [](const std::string &name) {
             return std::make_unique<nts::FourBitAdderComponent>(name);
         }},
        // thoses components are not created in the branch, need to pull
        /* {"4013", [](const std::string &name){return std::make_unique<nts::>(name);}},
        {"4017", [](const std::string &name){return std::make_unique<nts::>(name);}},
        {"4040", [](const std::string &name){return std::make_unique<nts::>(name);}},
        {"4094", [](const std::string &name){return std::make_unique<nts::>(name);}},
        {"4512", [](const std::string &name){return std::make_unique<nts::>(name);}},
        {"4514", [](const std::string &name){return std::make_unique<nts::>(name);}},
        {"4801", [](const std::string &name){return std::make_unique<nts::>(name);}},
        {"2716", [](const std::string &name){return std::make_unique<nts::>(name);}}, */
    };

// method to go with above map
std::unique_ptr<nts::IComponent> nts::createNamedComponent(std::string &name,
                                                           const std::string &type)
{
    for (auto elem : COMPONENTS_MAP) {
        if (type == elem.first)
            return elem.second(name);
    }
    throw nts::Parser::ParserException(UNKNOWN_CHIPSET + type);
}

// main method to parse file
nts::Circuit &nts::Parser::doParsing()
{
    try {
        this->loadFile();
    } catch (nts::Parser::ParserException &e) {
        if (std::string{e.what()} == PARSER_FILE_NOT_OPEN)
            throw &e;
    }
    try {
        this->createComponents();
        this->setComponentLinks();
    } catch (nts::Parser::ParserException &) {
    }
    return this->circuit;
}

// private methods called by doParsing
void nts::Parser::analyseLine(std::string &line) {}

void nts::Parser::createComponents()
{
    auto line = this->contents.begin();

    while (line != this->contents.end() && *line != std::string{CHIPSET_IND})
        line++;
    if (line == this->contents.end())
        throw nts::Parser::ParserException(std::string{PARSER_NO_CHIPSET});
}

void nts::Parser::setComponentLinks() {}
