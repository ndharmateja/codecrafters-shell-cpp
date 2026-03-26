#include "Command.hpp"
#include <iostream>

const std::unordered_set<std::string> Command::valid_commands = {"echo", "exit", "type"};

Command::Command(const std::string &input)
{
    // Find the first non-white-space char
    size_t input_start_index = input.find_first_not_of(" \t");

    // If the whole string is just white space, exit
    if (input_start_index == input.npos)
        return;

    // At this point, we know that the input isn't just white spaces
    // Find the ending of command
    size_t input_end_index = input.find_last_not_of(" \t");

    // Create a string view of the trimmed string
    std::string_view trimmed_input(input.begin() + input_start_index, input.begin() + input_end_index + 1);

    // Command starts at 0
    // Find command end index
    size_t command_end_index = trimmed_input.find_first_of(" \t");

    // If no white spaces, it means that there are no args
    if (command_end_index == trimmed_input.npos)
    {
        this->command.assign(trimmed_input);
        std::cout << "command: '" << this->command << "'" << std::endl;
        return;
    }

    // If white spaces, the command is from indices [0, command_end_index-1]
    this->command.assign(trimmed_input.substr(0, command_end_index));

    // At this point we know arg string is not empty
    size_t arg_start_index = trimmed_input.find_first_not_of(" \t", command_end_index);
    this->argument_string.assign(trimmed_input.substr(arg_start_index));
}

bool Command::execute()
{
    // Implement exit
    if (this->command == "exit")
        return false;

    // Implement echo
    if (this->command == "echo")
    {
        // Echo message
        std::cout << this->argument_string << std::endl;
        return true;
    }

    // Implement type
    if (this->command.starts_with("type "))
    {
        if (valid_commands.contains(this->argument_string))
            std::cout << this->argument_string << " is a shell builtin" << std::endl;
        else
            std::cout << this->argument_string << ": not found" << std::endl;
        return true;
    }

    // Every other command
    std::cout << this->command << ": command not found" << std::endl;
    return true;
}