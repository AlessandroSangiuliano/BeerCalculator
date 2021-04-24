//
// Created by slex on 22/04/21.
//

#ifndef BEERCALCULATOR_CONSOLE_H
#define BEERCALCULATOR_CONSOLE_H

#include <string>
#include <map>
#include <vector>

using namespace std;

enum Commands  {
        none,
        quit,
        addHop,
        addGrain,
        help,
        newRecipe
};

class Console
{
private:
    string commandLine;
    string command;
    Commands selectedCommand;
    map<string, Commands> commandMap;
    vector<string> parsedCommand;

public:
    const string &getCommand() const;

    void setCommand(const string &command);

    Console();

    virtual ~Console();

    bool readCommand();

    void resetCommand();

    bool parseCommand();

    string stringProcess(string aString);

    void help();

    Commands getSelectedCommand() const;

    void setSelectedCommand(Commands selectedCommand);

    const vector<string> &getParsedCommand() const;

    void setParsedCommand(const vector<string> &parsedCommand);

    void descripion();
};


#endif //BEERCALCULATOR_CONSOLE_H
