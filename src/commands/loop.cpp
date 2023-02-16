/*
** EPITECH PROJECT, 2023
** commands
** File description:
** loop
*/

#include <csignal>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/Simulator.hh>

static bool HAS_BEEN_CALLED = false;

static void handle_signal(int __attribute__((unused)) sig)
{
    HAS_BEEN_CALLED = true;
}

int nts::loop(nts::Circuit &circuit, std::string &line)
{
    HAS_BEEN_CALLED = false;
    signal(SIGINT, handle_signal);
    while (!HAS_BEEN_CALLED) {
        nts::simulate(circuit, line);
        nts::display(circuit, line);
    }
    return EPITECH_SUCCESS;
}
