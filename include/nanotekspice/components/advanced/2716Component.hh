/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 2716Component
*/

#pragma once

#include "nanotekspice/components/AGate.hh"
#include "nanotekspice/components/IComponent.hh"

namespace nts
{
    class ReadOnlyComponent : public AGate
    {
        public:
            ReadOnlyComponent(const std::string &name);
            ReadOnlyComponent(ReadOnlyComponent const &to_copy) = default;
            ReadOnlyComponent(ReadOnlyComponent &&to_move) = default;

            ~ReadOnlyComponent() override = default;

            ReadOnlyComponent &operator=(ReadOnlyComponent const &to_copy) = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
