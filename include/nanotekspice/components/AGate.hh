/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** AGate
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class AGate : public AComponent
    {
        public:
            ~AGate() override;

            virtual nts::Tristate computeSpecificPin(std::size_t first_input,
                                                     std::size_t second_input);
    };
} // namespace nts
