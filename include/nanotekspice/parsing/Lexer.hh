/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** Lexer
*/

#pragma once

#define LEXER_EXCEP " not recognized."
#define LEXER_EOF "End of file reached"
#define LEXER_GETLINE_ERR "Error with getline."
#define COMMENT_CHAR "#"

#include <exception>
#include <fstream>
#include <istream>
#include <string>
#include <vector>

namespace nts
{
    class Lexer
    {
        public:
            // ctor / dtor
            Lexer(std::ifstream &pfilestream);
            Lexer(Lexer const &to_copy) = default;
            Lexer(Lexer &&to_move) = default;
            ~Lexer() = default;
            // overload operator
            Lexer &operator=(Lexer const &to_copy) = delete;

            // exception class
            class LexerException : public std::exception
            {
                public:
                    LexerException(const std::string &perr);
                    LexerException(LexerException const &to_copy) = default;
                    LexerException(LexerException &&to_move) = default;
                    ~LexerException() override = default;

                    [[nodiscard]] const char *what() const noexcept override;

                private:
                    const std::string &err_msg;
            };

            // getters / setters
            // [[nodiscard]] => compiler will warn if return of function is not used
            [[nodiscard]] const std::ifstream &getFilestream() const;
            [[nodiscard]] std::vector<std::string> getContents() const;

            // return whether or not the ifstream is open
            [[nodiscard]] bool isOpen() const;
            // load a line from the ifstream
            void loadLine();
            // load the entire file in a std::vector<std::string>
            void loadFile();
            // return src without comment (starting with '#' and ending with a newline).
            // can be an empty line.
            [[nodiscard]] static std::string without_comment(const std::string &src);

        private:
            std::ifstream &filestream;
            std::vector<std::string> contents{};
    };

} // namespace nts
