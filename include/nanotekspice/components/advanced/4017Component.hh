/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4017Component
*/

#pragma once

#include "nanotekspice/components/AGate.hh"

namespace nts
{
    class TenBitJohnsonComponent : public AGate
    {
        public:
            TenBitJohnsonComponent(const std::string &name);
            TenBitJohnsonComponent(TenBitJohnsonComponent const &to_copy) = default;
            TenBitJohnsonComponent(TenBitJohnsonComponent &&to_move) = default;

            ~TenBitJohnsonComponent() override = default;

            TenBitJohnsonComponent &operator=(TenBitJohnsonComponent const &to_copy) = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
