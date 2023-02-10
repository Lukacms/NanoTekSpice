/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** main
*/

#include <iostream>
#include <memory>
#include <nanotekspice/components/elementary/NotComponent.hh>
#include <nanotekspice/components/special/FalseComponent.hh>
#include <nanotekspice/components/special/OutputComponent.hh>
#include <nanotekspice/components/special/TrueComponent.hh>
#include <nanotekspice/components/gates/4071Component.hh>

int main()
{
    nts::FalseComponent false_component{std::string("false")};
    nts::FalseComponent true_component{std::string("true")};
    nts::FourOrComponent four_or_component{std::string("four_or")};
    nts::NotComponent not_component{std::string("not")};
    nts::OutputComponent output_component{std::string("output")};

    four_or_component.setLink(1, true_component, 1);
    four_or_component.setLink(2, false_component, 1);
    not_component.setLink(1, four_or_component, 3);
    output_component.setLink(1, not_component, 2);
    output_component.compute(1);
    std::cout << "ACTUAL STATE : "
              << (output_component.getLastState() == nts::Tristate::True ? "True" : "False");
    return 0;
}
