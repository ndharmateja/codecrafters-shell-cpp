#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <memory>

#include "command.hpp"
#include "echo.hpp"
#include "empty.hpp"
#include "exit.hpp"
#include "invalid.hpp"
#include "type.hpp"

class CommandParser
{
private:
    static void split_cmd_str(const std::string &cmd_str, std::vector<std::string> &parts)
    {
        // Parse the string character by character removing extra spaces
        // and accumulate the command parts in the vector
        unsigned char c;
        size_t i{0}, n{cmd_str.size()};

        // We can start processing the word
        bool processing_word{false};
        std::string buffer;
        while (i < n)
        {
            // Get the current character
            c = cmd_str[i++];

            // If the character is a whitespace char and we are not in the middle of
            // processing a word we can skip it
            if (!processing_word && std::isspace(c))
                continue;

            // At this point if we encounter a whitespace, as we must be in the
            // middle of the word, we need to add the current part to the resulting vector
            if (std::isspace(c))
            {
                parts.push_back(buffer);
                buffer.clear();
                processing_word = false;
                continue;
            }

            // It is a non-whitespace character at this point
            // If we are in the middle of processing a word, we add this character
            // to the buffer and proceed forward
            // if (processing_word)
            // ! {
            // !     buffer.push_back(c);
            // !     continue;
            // ! }
            // At this point we have a non-whitespace character and
            // we are not processing a word, so it means that this is the first
            // character of a new part
            // ! processing_word = true;
            // ! buffer.push_back(c);

            // ! We can optimize the above code
            buffer.push_back(c);
            if (!processing_word)
                processing_word = true;
        }

        // Parse the last part if necessary
        // If the last character is not a whitespace, then we would have been
        // in the middle of processing the last part
        // So we need to process that
        if (processing_word)
            parts.push_back(buffer);
    }

    /**
     * Converts the given string into lowercase
     * Assumes that there are no whitespace characters in the string
     */
    static void convert_to_lower_case(std::string &str)
    {
        for (char &c : str)
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

public:
    static std::unique_ptr<Command> parse_command(const std::string &cmd_str)
    {
        // Split the command string into parts removing the extra whitespaces
        std::vector<std::string> parts;
        split_cmd_str(cmd_str, parts);

        // If the parts vector is empty we can return the empty command
        if (parts.empty())
            return std::make_unique<Empty>();

        // Make the first element of the vector (the command itself) lowercase
        std::string &command{parts.front()};
        convert_to_lower_case(command);

        // Parse the appropriate command and return the command
        if (command == "echo")
            return std::make_unique<Echo>(parts);
        if (command == "exit")
            return std::make_unique<Exit>();
        if (command == "type")
            return std::make_unique<Type>(parts);

        return std::make_unique<Invalid>(parts);
    }
};
