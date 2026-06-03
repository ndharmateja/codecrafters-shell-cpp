#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include "command.h"

class CommandParser
{
private:
    static std::vector<std::string> split_cmd_str(const std::string &cmd_str, std::vector<std::string> &parts)
    {
        // Parse the string character by character removing extra spaces
        // and accumulate the command parts in the vector
        unsigned char c;
        size_t i{0}, n{cmd_str.size()};

        // Skip the initial whitespace characters
        while (i < n && std::isspace(cmd_str[i]))
            i++;

        // We can start processing the word
        bool processing_word{true};
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

        // Return the result
        return parts;
    }

    /**
     * Converts the given string into lowercase
     * Assumes that there are no whitespace characters in the string
     */
    static void convert_to_lower_case(std::string &str)
    {
        size_t i{0}, n{str.size()};
        unsigned char c;
        while (i < n)
            str[i++] = std::tolower(str[i]);
    }

public:
    static std::vector<std::string> parse_command(const std::string &cmd_str)
    {
        // Split the command string into parts removing the extra whitespaces
        std::vector<std::string> parts;
        split_cmd_str(cmd_str, parts);

        // If the parts vector is empty we can return the empty vector
        if (parts.empty())
            return parts;

        // Make the first element of the vector (the command itself) lowercase
        convert_to_lower_case(parts.front());

        // At this point it is an invalid command
        return parts;
    }
};
