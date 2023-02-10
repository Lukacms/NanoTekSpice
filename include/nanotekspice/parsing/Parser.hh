/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** Parser
*/

#pragma once

#include <exception>
#include <fstream>
#include <istream>
#include <nanotekspice/Circuit.hh>
#include <string>
#include <vector>

#define PARSER_FILE_NOT_OPEN "Ifstream given not open."
#define PARSER_GETLINE_ERR "Error with getline."
#define PARSER_EOF "End of file."
#define PARSER_COMMENT_INDICATOR "#"

namespace nts
{
    class Parser
    {
        public:
            // ctor / dtor
            Parser(std::ifstream &pfilestream);
            Parser(Parser const &to_copy) = delete;
            Parser(Parser &&to_move) = delete;
            ~Parser() = default;
            // overload operator
            Parser &operator=(Parser const &to_copy) = delete;

            // exception class
            class ParserException : public std::exception
            {
                public:
                    ParserException(const std::string &perr_msg) : err_msg{perr_msg} {}
                    ParserException(ParserException const &to_copy) = default;
                    ParserException(ParserException &&to_move) = default;
                    ~ParserException() override = default;
                    ParserException &operator=(ParserException const &to_copy) = delete;

                    [[nodiscard]] const char *what() const noexcept override
                    {
                        return this->err_msg.c_str();
                    }

                private:
                    const std::string &err_msg;
            };

            // static function to parse
            // static nts::Circuit parse(std::string &filename);

            // "main" parsing function
            // nts::Circuit doParsing() { return this->circuit; }

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

        private:
            std::ifstream &filestream;
            std::vector<std::string> contents{};
            nts::Circuit circuit{};
    };

    // return src without comment (starting with '#' and ending with a newline).
    // can be an empty line.
    [[nodiscard]] std::string without_comment(const std::string &src);

} // namespace nts
