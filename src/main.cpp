#include <iostream>
#include <string>
#include "commands/command_parser.hpp"

int main()
{
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // Loop the prompt and take input
    std::string cmd_str;
    while (true)
    {
        // Print the $ prompt and get the command string input
        std::cout << "$ ";
        std::getline(std::cin, cmd_str);

        // Parse the command and execute it
        std::unique_ptr<Command> cmd = CommandParser::parse_command(cmd_str);
        cmd->execute();
    }
}
