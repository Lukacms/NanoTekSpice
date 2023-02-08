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

namespace nts
{
    class Parser
    {
        public:
            // ctor / dtor
            Parser(std::ifstream &pfilestream);
            Parser(Parser const &to_copy) = default;
            Parser(Parser &&to_move) = default;
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
            static nts::Circuit parse(std::string &filename);

            // "main" parsing function
            nts::Circuit doParsing();

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
