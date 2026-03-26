#include <iostream>
#include <string>

int main()
{
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // Print the prompt for the shell
    std::cout << "$ ";

    // Take the command input
    std::string input;
    std::getline(std::cin, input);
    std::cout << input << ": command not found" << std::endl;
}
