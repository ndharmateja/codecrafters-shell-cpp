#include <string>
#include <unordered_set>

class Command
{
private:
    std::string command;
    std::string argument_string;
    static const std::unordered_set<std::string> valid_commands;

public:
    Command(const std::string &);
    bool execute();
};