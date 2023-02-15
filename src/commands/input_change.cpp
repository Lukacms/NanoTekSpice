/*
** EPITECH PROJECT, 2023
** commands
** File description:
** input_change
*/

#include "nanotekspice/Circuit.hh"
#include <algorithm>

int nts::input_change(nts::Circuit &circuit, std::string &line)
{
    std::replace(line.begin(), line.end(), '=', ' ');
    return EPITECH_SUCCESS;
}
