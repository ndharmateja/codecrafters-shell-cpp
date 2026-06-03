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

        // Handle type command
        if (command.starts_with("type"))
        {
            std::string_view arg_string = std::string_view(command).substr(5);
            if (arg_string == "type" || arg_string == "echo" || arg_string == "exit")
                std::cout << arg_string << " is a shell builtin" << std::endl;
            else
                std::cout << arg_string << ": not found" << std::endl;
        }

        else
            std::cout << command << ": command not found" << std::endl;
    }
}
