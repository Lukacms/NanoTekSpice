/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Circuit
*/

#pragma once

#include <cstddef>
#include <exception>
#include <functional>
#include <memory>
#include <nanotekspice/components/IComponent.hh>
#include <string>
#include <vector>

#define EPITECH_SUCCESS 0
#define EPITECH_FAILURE 84

constexpr char const *HELP = "USAGE: ./nanotekspice [filepath]\n\
    [filepath] is the path to the .nts config file.";

constexpr char const *COMPONENT_NOT_FOUND = "component not found";

namespace nts
{
    class Circuit
    {
        public:
            Circuit() = default;
            Circuit(Circuit &);
            Circuit(Circuit &&) = delete;
            Circuit &operator=(Circuit &);
            Circuit &operator=(Circuit &&) = delete;
            ~Circuit();

            std::vector<std::unique_ptr<nts::IComponent>> &getComponentList();
            void addComponent(std::unique_ptr<nts::IComponent> new_component);
            std::reference_wrapper<nts::IComponent> getComponentByName(const std::string &name);

            // getters / setters
            std::size_t getTick() const;
            void addTick();

            class CircuitError : public std::exception
            {
                public:
                    CircuitError() = default;
                    CircuitError(const CircuitError &) = default;
                    ~CircuitError() override = default;

                    const char *what() const noexcept override { return COMPONENT_NOT_FOUND; }
            };

        private:
            std::vector<std::unique_ptr<nts::IComponent>> component_list;
            std::size_t ticks{0};
    };

    int main_loop(nts::Circuit &circuit);
    // functions to call during loop
    int simulate(nts::Circuit &circuit, std::string &line);
    int input_change(nts::Circuit &circuit, std::string &line);
    int display(nts::Circuit &circuit, std::string &line);
    int loop(nts::Circuit &circuit, std::string &line);
} // namespace nts
