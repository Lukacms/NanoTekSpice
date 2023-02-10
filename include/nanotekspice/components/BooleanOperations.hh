/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** ElementaryComponent
*/

#pragma once

#include <nanotekspice/components/IComponent.hh>

namespace nts
{
    nts::Tristate xorFunction(nts::Tristate input1, nts::Tristate input2);
    nts::Tristate orFunction(nts::Tristate input1, nts::Tristate input2);
    nts::Tristate notFunction(nts::Tristate input);
    nts::Tristate andFunction(nts::Tristate input1, nts::Tristate input2);
} // namespace nts
