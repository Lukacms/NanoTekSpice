/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** Lexer
*/

#include <fstream>
#include <ios>
#include <nanotekspice/parsing/Lexer.hh>
#include <string>

// ctor / dtor
nts::Lexer::Lexer(std::ifstream &pfilestream) : filestream{pfilestream} {}

// getter / setter

const std::ifstream &nts::Lexer::getFilestream() const
{
    return this->filestream;
}

std::vector<std::string> nts::Lexer::getContents() const
{
    return this->contents;
}

// methods

bool nts::Lexer::isOpen() const
{
    return this->filestream.is_open();
}

void nts::Lexer::loadLine()
{
    std::string line;

    if (this->filestream.eof())
        throw Lexer::LexerException(LEXER_EOF);
}
