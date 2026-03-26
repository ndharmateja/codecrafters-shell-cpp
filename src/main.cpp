#include <iostream>
#include <string>
#include <unordered_set>
#include "Command.hpp"

int main()
{
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // Valid commands
    std::unordered_set<std::string> valid_commands = {"echo", "exit", "type"};

    // input string to store the user input
    std::string input;

    // Loop to run REPL
    while (true)
    {
        // Print the prompt for the shell
        std::cout << "$ ";

        // Take the command input
        std::getline(std::cin, input);

        // Create command object and execute it
        Command command(input);
        if (command.execute())
            continue;
        else
            return;
    }

    return 0;
}
