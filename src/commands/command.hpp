#pragma once

// Command interface
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};