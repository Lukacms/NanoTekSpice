/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** AComponent
*/

#pragma once

#include <nanotekspice/components/AComponent.hh>
#include <nanotekspice/components/UElementaryComponent.hh>
#include <unordered_map>

namespace nts
{
    class AComponent : public IComponent
    {
        public:
            ~AComponent() override = default;

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin) override;
            void simulate(std::size_t tick) override;

        protected:
            std::string name;
            std::unordered_map<std::size_t, nts::IComponent *> pin_to_component;
            std::unordered_map<std::size_t, std::size_t> pin_to_pin;
    };
} // namespace nts
