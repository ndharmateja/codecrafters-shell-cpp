#include <iostream>
#include <string>

int main()
{
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

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
            // Using string view instead of a substring to prevent reallocation
            std::string_view message(input.begin() + 5, input.end());

            // Echo message
            std::cout << message << std::endl;
            continue;
        }

        std::cout << input << ": command not found" << std::endl;
    }

    return 0;
}
