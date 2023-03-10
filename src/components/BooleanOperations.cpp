/*
** EPITECH PROJECT, 2023
** NanoTekSpice [WSL : Manjaro]
** File description:
** ElementaryComponent
*/

#include <nanotekspice/components/BooleanOperations.hh>

/* Methods */

nts::Tristate nts::orFunction(nts::Tristate in1, nts::Tristate in2)
{
    if ((in1 == nts::Tristate::False && in2 == nts::Tristate::False))
        return nts::Tristate::False;
    if ((in1 == nts::Tristate::True && in2 == nts::Tristate::False) ||
        (in1 == nts::Tristate::False && in2 == nts::Tristate::True) ||
        (in1 == nts::Tristate::True && in2 == nts::Tristate::True) ||
        (in1 == nts::Tristate::Undefined && in2 == nts::Tristate::True) ||
        (in1 == nts::Tristate::True && in2 == nts::Tristate::Undefined))
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::xorFunction(nts::Tristate in1, nts::Tristate in2)
{
    if ((in1 == nts::Tristate::False && in2 == nts::Tristate::False) ||
        (in1 == nts::Tristate::True && in2 == nts::Tristate::True))
        return nts::Tristate::False;
    if ((in1 == nts::Tristate::True && in2 == nts::Tristate::False) ||
        (in1 == nts::Tristate::False && in2 == nts::Tristate::True))
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::andFunction(nts::Tristate in1, nts::Tristate in2)
{
    if ((in1 == nts::Tristate::False && in2 == nts::Tristate::False) ||
        (in1 == nts::Tristate::False && in2 == nts::Tristate::True) ||
        (in1 == nts::Tristate::True && in2 == nts::Tristate::False) ||
        (in1 == nts::Tristate::False && in2 == nts::Tristate::Undefined) ||
        (in1 == nts::Tristate::Undefined && in2 == nts::Tristate::False))
        return nts::Tristate::False;
    if (in1 == nts::Tristate::True && in2 == nts::Tristate::True)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::notFunction(nts::Tristate input)
{
    if (input == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if (input == nts::Tristate::True)
        return nts::Tristate::False;
    return nts::Tristate::True;
}
