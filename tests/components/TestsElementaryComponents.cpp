/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** TestsElementaryComponents
*/

#include <gtest/gtest.h>
#include <nanotekspice/components/elementary/AndComponent.hh>
#include <nanotekspice/components/elementary/NotComponent.hh>
#include <nanotekspice/components/elementary/OrComponent.hh>
#include <nanotekspice/components/elementary/XorComponent.hh>
#include <nanotekspice/components/special/InputComponent.hh>

TEST(Testing_And_All_States, AndComponent)
{
    std::unique_ptr<nts::IComponent> input_a = std::make_unique<nts::InputComponent>("A");
    std::unique_ptr<nts::IComponent> input_b = std::make_unique<nts::InputComponent>("B");
    std::unique_ptr<nts::IComponent> and_comp = std::make_unique<nts::AndComponent>("And");

    and_comp->setLink(1, *input_a, 1);
    and_comp->setLink(2, *input_b, 1);
    EXPECT_EQ(and_comp->compute(3), nts::Tristate::Undefined);
    input_a->setNewState(nts::Tristate::True);
    input_a->simulate(1);
    EXPECT_EQ(and_comp->compute(3), nts::Tristate::Undefined);
    input_a->setNewState(nts::Tristate::False);
    input_a->simulate(1);
    EXPECT_EQ(and_comp->compute(3), nts::Tristate::False);
    input_b->setNewState(nts::Tristate::False);
    input_b->simulate(1);
    EXPECT_EQ(and_comp->compute(3), nts::Tristate::False);
    input_a->setNewState(nts::Tristate::True);
    input_a->simulate(1);
    EXPECT_EQ(and_comp->compute(3), nts::Tristate::False);
    input_b->setNewState(nts::Tristate::True);
    input_b->simulate(1);
    EXPECT_EQ(and_comp->compute(3), nts::Tristate::True);
}

TEST(Testing_Or_All_States, OrComponent)
{
    nts::InputComponent input_a{"A"};
    nts::InputComponent input_b{"B"};
    nts::OrComponent or_comp{"Or"};

    or_comp.setLink(1, input_a, 1);
    or_comp.setLink(2, input_b, 1);
    EXPECT_EQ(or_comp.compute(3), nts::Tristate::Undefined);
    input_a.setNewState(nts::Tristate::True);
    EXPECT_EQ(or_comp.compute(3), nts::Tristate::True);
    input_a.setNewState(nts::Tristate::False);
    EXPECT_EQ(or_comp.compute(3), nts::Tristate::Undefined);
    input_b.setNewState(nts::Tristate::False);
    EXPECT_EQ(or_comp.compute(3), nts::Tristate::False);
    input_a.setNewState(nts::Tristate::True);
    EXPECT_EQ(or_comp.compute(3), nts::Tristate::True);
    input_b.setNewState(nts::Tristate::True);
    EXPECT_EQ(or_comp.compute(3), nts::Tristate::True);
}

TEST(Testing_Xor_All_States, XorComponent)
{
    nts::InputComponent input_a{"A"};
    nts::InputComponent input_b{"B"};
    nts::XorComponent xor_comp{"Xor"};

    xor_comp.setLink(1, input_a, 1);
    xor_comp.setLink(2, input_b, 1);
    EXPECT_EQ(xor_comp.compute(3), nts::Tristate::Undefined);
    input_a.setNewState(nts::Tristate::True);
    EXPECT_EQ(xor_comp.compute(3), nts::Tristate::Undefined);
    input_a.setNewState(nts::Tristate::False);
    EXPECT_EQ(xor_comp.compute(3), nts::Tristate::Undefined);
    input_b.setNewState(nts::Tristate::False);
    EXPECT_EQ(xor_comp.compute(3), nts::Tristate::False);
    input_a.setNewState(nts::Tristate::True);
    EXPECT_EQ(xor_comp.compute(3), nts::Tristate::True);
    input_b.setNewState(nts::Tristate::True);
    EXPECT_EQ(xor_comp.compute(3), nts::Tristate::False);
}

TEST(Testing_Not_All_States, NotComponent)
{
    nts::InputComponent input_a{"A"};
    nts::XorComponent not_comp{"Not"};

    not_comp.setLink(1, input_a, 1);
    EXPECT_EQ(not_comp.compute(3), nts::Tristate::Undefined);
    input_a.setNewState(nts::Tristate::False);
    EXPECT_EQ(not_comp.compute(3), nts::Tristate::True);
    input_a.setNewState(nts::Tristate::True);
    EXPECT_EQ(not_comp.compute(3), nts::Tristate::False);
}
