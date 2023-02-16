/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** Parser
*/

#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/parsing/Parser.hh>
#include <string>
#include <vector>

// static function
void nts::Parser::parse(std::string &filename, nts::Circuit &circuit)
{
    std::ifstream stream{filename};
    nts::Parser parser{stream};

    if (std::filesystem::is_directory(filename))
        throw nts::Parser::ParserException{std::string{PARSER_IS_DIRECTORY}};
    if (!parser.isOpen() || !stream.good())
        throw nts::Parser::ParserException{std::string{PARSER_FILE_NOT_OPEN}};
    try {
        return parser.doParsing(circuit);
    } catch (nts::Parser::ParserException &e) {
        throw e;
    }
}

// ctor / dtor
nts::Parser::Parser(std::ifstream &pfilestream) : filestream{pfilestream} {}

// getters / setters
const std::ifstream &nts::Parser::getFilestream() const
{
    return this->filestream;
}

std::vector<std::string> nts::Parser::getContents() const
{
    return this->contents;
}

bool nts::Parser::isOpen() const
{
    return this->filestream.is_open();
}

// methods

void nts::Parser::loadLine()
{
    std::string line;

    if (!this->isOpen())
        throw nts::Parser::ParserException(PARSER_FILE_NOT_OPEN);
    std::getline(this->filestream, line);
    if (!(line = nts::without_comment(line)).empty())
        this->contents.push_back(line);
}

void nts::Parser::loadFile()
{
    try {
        while (!this->filestream.eof())
            this->loadLine();
    } catch (const nts::Parser::ParserException &e) {
        if (std::string{e.what()} == PARSER_FILE_NOT_OPEN)
            throw e;
    }
}
