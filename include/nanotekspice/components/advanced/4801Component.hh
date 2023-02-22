/*
** EPITECH PROJECT, 2023
** advanced
** File description:
** 4801Component
*/

#pragma once

#include "nanotekspice/components/AGate.hh"

namespace nts
{
    class RandomMemAccessComponent : public AGate
    {
        public:
            RandomMemAccessComponent(const std::string &pname);
            RandomMemAccessComponent(RandomMemAccessComponent const &to_copy) = default;
            RandomMemAccessComponent(RandomMemAccessComponent &&to_move) = default;

            ~RandomMemAccessComponent() override = default;

            RandomMemAccessComponent &operator=(RandomMemAccessComponent const &to_copy) = default;

            nts::Tristate compute(std::size_t pin) final;
            nts::Tristate computeSpecificPin(std::size_t first_input,
                                             std::size_t second_input) final;
            nts::Tristate computeCarryOut(std::size_t first_input, std::size_t second_input);

        private:
    };

} // namespace nts
