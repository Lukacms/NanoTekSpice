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
    class UElementaryComponent
    {
        public:
            UElementaryComponent() = default;
            ~UElementaryComponent() = default;

            static nts::Tristate xorFunction(nts::Tristate input1, nts::Tristate input2);
            static nts::Tristate orFunction(nts::Tristate input1, nts::Tristate input2);
            static nts::Tristate notFunction(nts::Tristate input);
            static nts::Tristate andFunction(nts::Tristate input1, nts::Tristate input2);
    };

} // namespace nts
