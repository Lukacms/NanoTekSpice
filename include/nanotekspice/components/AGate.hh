/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** AGate
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

enum Pins {
    chip_pin1 = 1,
    chip_pin2 = 2,
    chip_pin3 = 3,
    chip_pin4 = 4,
    chip_pin5 = 5,
    chip_pin6 = 6,
    chip_pin7 = 7,
    chip_pin8 = 8,
    chip_pin9 = 9,
    chip_pin10 = 10,
    chip_pin11 = 11,
    chip_pin12 = 12,
    chip_pin13 = 13,
    chip_pin14 = 14,
    chip_pin15 = 15,
    chip_pin16 = 16,
};

namespace nts
{
    class AGate : public AComponent
    {
        public:
            ~AGate() override = default;

            virtual nts::Tristate computeSpecificPin(std::size_t first_input,
                                                     std::size_t second_input) = 0;
    };
} // namespace nts
