/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** main
*/

#include <iostream>
#include <memory>
#include <nanotekspice/components/elementary/NotComponent.hh>
#include <nanotekspice/components/gates/4071Component.hh>
#include <nanotekspice/components/special/FalseComponent.hh>
#include <nanotekspice/components/special/OutputComponent.hh>
#include <nanotekspice/components/special/TrueComponent.hh>

int main()
{
    std::unique_ptr<nts::IComponent> false_comp =
        std::make_unique<nts::FalseComponent>(std::string("false"));
    std::unique_ptr<nts::IComponent> true_comp =
        std::make_unique<nts::TrueComponent>(std::string("true"));
    std::unique_ptr<nts::IComponent> four_or_comp =
        std::make_unique<nts::FourOrComponent>(std::string("four_or"));
    std::unique_ptr<nts::IComponent> not_comp =
        std::make_unique<nts::NotComponent>(std::string("not"));
    std::unique_ptr<nts::IComponent> out_comp =
        std::make_unique<nts::OutputComponent>(std::string("output"));

    four_or_comp->setLink(1, *true_comp, 1);
    four_or_comp->setLink(2, *false_comp, 1);
    out_comp->setLink(1, *four_or_comp, 2);
    out_comp->compute(1);
    std::cout << "ACTUAL STATE : "
              << out_comp->compute(1);
    return 0;
}
