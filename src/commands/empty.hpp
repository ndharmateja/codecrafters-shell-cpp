#pragma once

#include <iostream>
#include "command.hpp"

class Empty : public Command
{
public:
    explicit Empty() {}

    // Empty command doesn't need to do anything
    void execute() override { return; }
};