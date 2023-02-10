/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** testSpecialComponents
*/

#include <criterion/criterion.h>
#include <nanotekspice/components/special/FalseComponent.hh>
#include <nanotekspice/components/special/TrueComponent.hh>
#include <nanotekspice/components/special/ClockComponent.hh>
#include <nanotekspice/components/special/OutputComponent.hh>

Test(Testing_False, FalseComponent)
{
    nts::FalseComponent false_comp{"False"};
    nts::OutputComponent output_comp{"Output"};

    output_comp.setLink(1, false_comp, 1);
    cr_assert_eq(output_comp.compute(1), nts::Tristate::True);
}

Test(Testing_True, TrueComponent)
{
    nts::TrueComponent true_comp{"True"};
    nts::OutputComponent output_comp{"Output"};

    output_comp.setLink(1, true_comp, 1);
    cr_assert_eq(output_comp.compute(1), nts::Tristate::True);
}

Test(Testing_Clock, ClockComponent)
{
    nts::ClockComponent clock_comp{"Clock"};
    nts::OutputComponent output_comp{"Output"};

    output_comp.setLink(1, clock_comp, 1);
    cr_assert_eq(output_comp.compute(1), nts::Tristate::Undefined);
    clock_comp.setCurrentState(nts::Tristate::True);
    cr_assert_eq(output_comp.compute(1), nts::Tristate::True);
    clock_comp.simulate(1);
    cr_assert_eq(output_comp.compute(1), nts::Tristate::False);
    clock_comp.simulate(3);
    cr_assert_eq(output_comp.compute(1), nts::Tristate::False);
}
