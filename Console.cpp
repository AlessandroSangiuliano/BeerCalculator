//
// Created by slex on 22/04/21.
//

#include "Console.h"
#include <iostream>

Console::Console()
{
    Console::resetCommand();
    commandMap.insert(make_pair("quit", quit));
    commandMap.insert(make_pair("addHop", addHop));
    commandMap.insert(make_pair("addGrain", addGrain));

    cout << "Insert 'help' command for the list of possible commands." << endl;
}

Console::~Console()
{

}

const string &Console::getCommand() const
{
    return commandLine;
}

void Console::setCommand(const string &command)
{
    Console::commandLine = command;
}

bool Console::readCommand()
{
    bool didRead = false;

    if (commandLine.compare("none") != 0)
        Console::resetCommand();

    cout << "#: ";

    getline(cin, commandLine);

    if (commandLine.compare("none") != 0) {
        didRead = true;
    }

    return didRead;
}

bool Console::parseCommand()
{
    bool isValid = false;

    command = Console::stringProcess(commandLine);

    try
    {
        if (commandMap.at(command) == quit)
        {
            selectedCommand = quit;
            isValid = true;
        }

        if (commandMap.at(command) == addGrain)
        {
            selectedCommand = addGrain;
            isValid = true;
        }

        if (commandMap.at(command) == addHop)
        {
            selectedCommand = addHop;
            isValid = true;
        }
    }
    catch (const std::out_of_range& oor)
    {
        cout << "Command '" << command << "' doesn't exist!" << endl;
    }

    return isValid;
}

void Console::resetCommand()
{
    commandLine.clear();
    commandLine = "none";
}

string Console::stringProcess(string aString)
{
    int pos = aString.find(' ');
    string subString = aString.substr(0, pos);

    return subString;
}

void Console::help()
{
    cout << "Command list:" << endl;
    cout << "addGrain - Add a grain to the recipe" << endl;
    cout << "addHop - Add a hop to the recipe" << endl;
    cout << "quit - Quit the program" << endl;
}

Commands Console::getSelectedCommand() const
{
    return selectedCommand;
}

void Console::setSelectedCommand(Commands selectedCommand)
{
    Console::selectedCommand = selectedCommand;
}


