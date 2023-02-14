/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Circuit
*/

#pragma once

#include <exception>
#include <functional>
#include <memory>
#include <nanotekspice/components/IComponent.hh>
#include <vector>

#define EPITECH_SUCCESS 0
#define EPITECH_FAILURE 84

constexpr char const *COMPONENT_NOT_FOUND = "component not found";

namespace nts
{
    class Circuit
    {
        public:
            Circuit() = default;
            Circuit(const Circuit &);
            Circuit(Circuit &&) = delete;
            Circuit &operator=(Circuit &);
            Circuit &operator=(Circuit &&) = delete;
            ~Circuit();

            std::vector<std::unique_ptr<nts::IComponent>> &getComponentList();
            void addComponent(std::unique_ptr<nts::IComponent> new_component);
            std::reference_wrapper<nts::IComponent> getComponentByName(const std::string &name);

            class CircuitError : public std::exception
            {
                public:
                    CircuitError() = default;
                    ~CircuitError() override = default;

                    const char *what() const noexcept override { return COMPONENT_NOT_FOUND; }
            };

        private:
            std::vector<std::unique_ptr<nts::IComponent>> component_list;
    };
} // namespace nts
