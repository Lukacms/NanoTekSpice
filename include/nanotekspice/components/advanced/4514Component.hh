/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4514Component
*/

#pragma once

#include "nanotekspice/components/AGate.hh"

namespace nts
{
    class FourBitDecoderComponent : public AGate
    {
        public:
            FourBitDecoderComponent(const std::string &pname);
            FourBitDecoderComponent(FourBitDecoderComponent const &to_copy) = default;
            FourBitDecoderComponent(FourBitDecoderComponent &&to_move) = default;

            ~FourBitDecoderComponent() override = default;

            FourBitDecoderComponent &operator=(FourBitDecoderComponent const &to_copy) = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
