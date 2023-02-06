/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** Circuit
*/

#pragma once

#include <nanotekspice/components/IComponent.hh>
#include <vector>

namespace nts
{
    class Circuit
    {
        public:
            Circuit();
            ~Circuit();

            std::vector<nts::IComponent> getComponentList();
            void addComponent(IComponent &);

        private:
            std::vector<nts::IComponent> component_list;
    };
} // namespace nts
