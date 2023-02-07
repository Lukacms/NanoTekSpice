/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Circuit
*/

#pragma once

#define EPITECH_SUCCESS 0
#define EPITECH_FAILURE 84

#include <memory>
#include <nanotekspice/components/IComponent.hh>
#include <vector>

namespace nts
{
    class Circuit
    {
        public:
            Circuit() = default;
            Circuit(const Circuit &) = default;
            Circuit(Circuit &&) = delete;
            Circuit &operator=(const Circuit &) = default;
            Circuit &operator=(Circuit &&) = delete;
            ~Circuit() = default;

            std::vector<std::unique_ptr<nts::IComponent>> &getComponentList();
            void addComponent(std::unique_ptr<nts::IComponent> new_component);

        private:
            std::vector<std::unique_ptr<nts::IComponent>> component_list;
    };
} // namespace nts
