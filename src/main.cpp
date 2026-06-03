#include <iostream>
#include <string>

int main()
{
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // Loop the prompt and take input
    std::string command;
    while (true)
    {
        // Print the $ prompt
        std::cout << "$ ";

        // Get the command input and print invalid commands
        std::getline(std::cin, command);

        // Handle exit command
        if (command == "exit")
            break;

        // Handle echo command
        if (command.starts_with("echo"))
            std::cout << command.substr(5) << std::endl;

        else
            std::cout << command << ": command not found" << std::endl;
    }
}
