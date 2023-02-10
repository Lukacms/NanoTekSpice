/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** TestsElementaryComponents
*/

#include <criterion/criterion.h>
#include <nanotekspice/components/elementary/AndComponent.hh>
#include <nanotekspice/components/elementary/NotComponent.hh>
#include <nanotekspice/components/elementary/OrComponent.hh>
#include <nanotekspice/components/elementary/XorComponent.hh>
#include <nanotekspice/components/special/InputComponent.hh>

Test(Testing_And_All_States, AndComponent)
{
    nts::InputComponent input_a{"A"};
    nts::InputComponent input_b{"B"};
    nts::AndComponent and_comp{"And"};

    and_comp.setLink(1, input_a, 1);
    and_comp.setLink(2, input_b, 1);
    cr_assert_eq(and_comp.compute(3), nts::Tristate::Undefined);
    input_a.setCurrentState(nts::Tristate::True);
    cr_assert_eq(and_comp.compute(3), nts::Tristate::Undefined);
    input_a.setCurrentState(nts::Tristate::False);
    cr_assert_eq(and_comp.compute(3), nts::Tristate::False);
    input_b.setCurrentState(nts::Tristate::False);
    cr_assert_eq(and_comp.compute(3), nts::Tristate::False);
    input_a.setCurrentState(nts::Tristate::True);
    cr_assert_eq(and_comp.compute(3), nts::Tristate::False);
    input_b.setCurrentState(nts::Tristate::True);
    cr_assert_eq(and_comp.compute(3), nts::Tristate::True);
}

Test(Testing_Or_All_States, OrComponent)
{
    nts::InputComponent input_a{"A"};
    nts::InputComponent input_b{"B"};
    nts::OrComponent or_comp{"Or"};

    or_comp.setLink(1, input_a, 1);
    or_comp.setLink(2, input_b, 1);
    cr_assert_eq(or_comp.compute(3), nts::Tristate::Undefined);
    input_a.setCurrentState(nts::Tristate::True);
    cr_assert_eq(or_comp.compute(3), nts::Tristate::True);
    input_a.setCurrentState(nts::Tristate::False);
    cr_assert_eq(or_comp.compute(3), nts::Tristate::Undefined);
    input_b.setCurrentState(nts::Tristate::False);
    cr_assert_eq(or_comp.compute(3), nts::Tristate::False);
    input_a.setCurrentState(nts::Tristate::True);
    cr_assert_eq(or_comp.compute(3), nts::Tristate::True);
    input_b.setCurrentState(nts::Tristate::True);
    cr_assert_eq(or_comp.compute(3), nts::Tristate::True);
}

Test(Testing_Xor_All_States, XorComponent)
{
    nts::InputComponent input_a{"A"};
    nts::InputComponent input_b{"B"};
    nts::XorComponent xor_comp{"Xor"};

    xor_comp.setLink(1, input_a, 1);
    xor_comp.setLink(2, input_b, 1);
    cr_assert_eq(xor_comp.compute(3), nts::Tristate::Undefined);
    input_a.setCurrentState(nts::Tristate::True);
    cr_assert_eq(xor_comp.compute(3), nts::Tristate::Undefined);
    input_a.setCurrentState(nts::Tristate::False);
    cr_assert_eq(xor_comp.compute(3), nts::Tristate::Undefined);
    input_b.setCurrentState(nts::Tristate::False);
    cr_assert_eq(xor_comp.compute(3), nts::Tristate::False);
    input_a.setCurrentState(nts::Tristate::True);
    cr_assert_eq(xor_comp.compute(3), nts::Tristate::True);
    input_b.setCurrentState(nts::Tristate::True);
    cr_assert_eq(xor_comp.compute(3), nts::Tristate::False);
}

Test(Testing_Not_All_States, NotComponent)
{
    nts::InputComponent input_a{"A"};
    nts::XorComponent not_comp{"Not"};

    not_comp.setLink(1, input_a, 1);
    cr_assert_eq(not_comp.compute(3), nts::Tristate::Undefined);
    input_a.setCurrentState(nts::Tristate::False);
    cr_assert_eq(not_comp.compute(3), nts::Tristate::True);
    input_a.setCurrentState(nts::Tristate::True);
    cr_assert_eq(not_comp.compute(3), nts::Tristate::False);
}
