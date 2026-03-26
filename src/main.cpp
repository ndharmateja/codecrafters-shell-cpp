#include <iostream>
#include <string>
#include <unordered_set>

std::string_view get_args_string(std::string input)
{
    // Using string view instead of a substring to prevent reallocation
    return std::string_view(input.begin() + 5, input.end());
}

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

        // Implement exit
        if (input == "exit")
            break;

        // Implement echo
        if (input.starts_with("echo "))
        {
            // Echo message
            std::cout << get_args_string(input) << std::endl;
            continue;
        }

        // Implement type
        if (input.starts_with("type "))
        {
            std::string message{get_args_string(input)};
            if (valid_commands.find(message) != valid_commands.end())
                std::cout << message << " is a shell builtin" << std::endl;
            else
                std::cout << message << ": not found" << std::endl;
            continue;
        }

        std::cout << input << ": command not found" << std::endl;
    }

    return 0;
}
