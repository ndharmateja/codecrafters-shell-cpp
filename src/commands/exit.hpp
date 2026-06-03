#pragma once

#include <cstdlib>
#include "command.hpp"

class Exit : public Command
{

public:
    explicit Exit() {}

    // Exit command needs to just exit
    void execute() override { exit(EXIT_SUCCESS); }
};