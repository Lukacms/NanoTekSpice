/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4512Component
*/

#pragma once

#include "nanotekspice/components/AGate.hh"

namespace nts
{
    class EightChannelSelectorComponent : public AGate
    {
        public:
            EightChannelSelectorComponent(const std::string &pname);
            EightChannelSelectorComponent(EightChannelSelectorComponent const &to_copy) = default;
            EightChannelSelectorComponent(EightChannelSelectorComponent &&to_move) = default;

            ~EightChannelSelectorComponent() override = default;

            EightChannelSelectorComponent &
            operator=(EightChannelSelectorComponent const &to_copy) = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
