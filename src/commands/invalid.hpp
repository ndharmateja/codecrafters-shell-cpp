#pragma once

#include <iostream>
#include "command.hpp"

class Invalid : public Command
{
private:
    std::string command;

public:
    explicit Invalid(std::vector<std::string> &parts) : command{std::move(parts.front())} {}

    // Invalid command needs to print the invalid command message
    void execute() override
    {
        std::cout << command << ": command not found" << std::endl;
    }
};