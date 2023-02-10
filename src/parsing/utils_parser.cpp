/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** utils_parser
*/

#include <nanotekspice/parsing/Parser.hh>

std::string nts::without_comment(const std::string &src)
{
    std::string dest = src.substr(0, src.find(PARSER_COMMENT_INDICATOR));

    return dest;
}
