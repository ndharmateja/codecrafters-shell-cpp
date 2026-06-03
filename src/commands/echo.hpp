#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "command.hpp"

class Echo : public Command
{
private:
    std::vector<std::string> parts;

public:
    explicit Echo(const std::vector<std::string> &parts) : parts{std::move(parts)} {}

    // Echo command needs to print all the remaining parts of the command
    // except the command itself
    void execute() override
    {
        size_t num_parts{parts.size()}, i{1};
        while (i < num_parts)
        {
            // Print the part and a space if it is not the last part
            std::cout << parts[i];
            if (i++ < num_parts - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
};