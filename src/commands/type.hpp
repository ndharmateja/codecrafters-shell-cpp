#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "command.hpp"

class Type : public Command
{
private:
    std::vector<std::string> parts;

public:
    explicit Type(const std::vector<std::string> &parts) : parts{std::move(parts)} {}

    // Type command needs to print the type of the given argument
    void execute() override
    {
        // If there is only part, then we can exit
        if (parts.size() == 1)
        {
            std::cout << "Usage: type <command>" << std::endl;
            return;
        }

        // Print the type information of the given command
        const std::string &arg{parts[1]};
        if (arg == "type" || arg == "echo" || arg == "exit")
            std::cout << arg << " is a shell builtin" << std::endl;
        else
            std::cout << arg << ": not found" << std::endl;
    }
};