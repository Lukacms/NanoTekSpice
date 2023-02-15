/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** AComponent
*/

#include <nanotekspice/components/AComponent.hh>

/* Destructor */

// nts::AComponent::~AComponent() {}

/* Methods */

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherpin)
{
    this->pin_to_component.emplace(pin, std::ref(other));
    this->pin_to_pin[pin] = otherpin;
}

void nts::AComponent::simulate(std::size_t tick __attribute_maybe_unused__) {}

void nts::AComponent::setNewState(nts::Tristate new_state __attribute_maybe_unused__) {}

std::string nts::AComponent::getName() const
{
    return this->name;
}
