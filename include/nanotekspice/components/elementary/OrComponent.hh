/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** OrComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>

namespace nts
{
    class OrComponent : public AComponent
    {
        public:
            OrComponent(const std::string &name);
            ~OrComponent() override = default;

            nts::Tristate compute(std::size_t pin) final;

        protected:
        private:
    };
} // namespace nts


