/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** Parser
*/

#include <fstream>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/parsing/Parser.hh>
#include <string>
#include <vector>

// static function
nts::Circuit nts::Parser::parse(std::string &filename)
{
    std::ifstream stream{filename};
    nts::Parser parser{stream};

    if (!parser.isOpen())
        throw nts::Parser::ParserException(PARSER_FILE_NOT_OPEN);
    return parser.doParsing();
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
    if (line.empty())
        throw nts::Parser::ParserException(PARSER_EOF);
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
