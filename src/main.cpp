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

        // Exit if the command is exit
        if (input == "exit")
            break;

        std::cout << input << ": command not found" << std::endl;
    }

    return 0;
}
