/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** Parser
*/

#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <istream>
#include <memory>
#include <nanotekspice/Circuit.hh>
#include <nanotekspice/components/IComponent.hh>
#include <string>
#include <vector>

constexpr char const *PARSER_COMMENT_INDICATOR = "#";

constexpr char const *PARSER_FILE_NOT_OPEN = "Ifstream given not open.";
constexpr char const *PARSER_IS_DIRECTORY = "Ifstream given is a directory.";
constexpr char const *PARSER_GETLINE_ERR = "Error with getline.";
constexpr char const *PARSER_EOF = "End of file.";
constexpr char const *CHIPSET_IND = ".chipsets:";
constexpr char const *UNKNOWN_CHIPSET = "Chipset unknown: ";
constexpr char const *LINKS_IND = ".links:";
constexpr char const *PARSER_NO_LINKS = "No links given between chipset.";
constexpr char const *PARSER_NO_CHIPSET = "No chipset given to make links.";
constexpr char const *PARSER_LINK_UNKNOWN = "Can't make a link with a nonexistant chipset.";
constexpr char const *PARSER_INVALID_CHIPSET = "Chipset is invalid";
constexpr char const *PIN_OUT_OF_BOND = "Chipset's pin is out of bond.";
constexpr char const *PARSER_INVALID_LINK_FORMAT = "invalid link format: ";

constexpr int LINKS_ARGS_SIZE = 4;

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

                    const char *what() const noexcept override { return this->err_msg.c_str(); }

                private:
                    std::string err_msg;
            };

            // static function to parse
            static void parse(std::string &filename, nts::Circuit &circuit);

            // "main" parsing function
            void doParsing(nts::Circuit &circuit);

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
            // create a new component
            // function is generic
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type,
                                                             nts::Circuit &circuit);

        private:
            std::ifstream &filestream;
            std::vector<std::string> contents{};

            // private methods
            void createComponents(nts::Circuit &circuit);
            void analyseLine(std::string &line, nts::Circuit &circuit);
            // TODO
            void setComponentLinks(nts::Circuit &circuit);
            void setLinkLine(std::string &line, nts::Circuit &circuit);
    };

    // return src without comment (starting with '#' and ending with a newline).
    // can be an empty line.
    [[nodiscard]] std::string without_comment(const std::string &src);
    bool hasChipset(const std::string &name, nts::Circuit &circuit);
    std::unique_ptr<nts::IComponent> createNamedComponent(std::string &name,
                                                          const std::string &type);

} // namespace nts
