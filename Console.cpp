//
// Created by slex on 22/04/21.
//

#include "Console.h"
#include <iostream>

Console::Console()
{
    Console::resetCommand();
    commandMap.insert(make_pair("quit", Commands::quit));
    commandMap.insert(make_pair("addHop", Commands::addHop));
    commandMap.insert(make_pair("addGrain", Commands::addGrain));
    commandMap.insert(make_pair("help", Commands::help));

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
        if (commandMap.at(command) == Commands::quit)
        {
            selectedCommand = Commands::quit;
            isValid = true;
        }

        if (commandMap.at(command) == Commands::addGrain)
        {
            selectedCommand = Commands::addGrain;
            isValid = true;
        }

        if (commandMap.at(command) == Commands::addHop)
        {
            selectedCommand = Commands::addHop;
            isValid = true;
        }

        if (commandMap.at(command) == Commands::help)
        {
            selectedCommand = Commands::help;
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
    int last = 0;
    int next = 0;
    char delimiter = ' ';
    //string subString = aString.substr(0, pos);

    while ((next = aString.find(delimiter, last)) != string::npos)
    {
        //parsedCommand.insert(pos, aString.substr(last, next-last));
        parsedCommand.insert(parsedCommand.begin(),aString.substr(last, next-last));
        last = next + 1;
    }

    return subString;
}

void Console::help()
{
    cout << "***********************************" << endl;
    cout << "[THIS IS THE COMAND LIST]" << endl;
    cout << "addGrain - Add a grain to the recipe" << endl;
    cout << "addHop - Add a hop to the recipe" << endl;
    cout << "quit - Quit the program" << endl;
    cout << "***********************************" << endl;
}

Commands Console::getSelectedCommand() const
{
    return selectedCommand;
}

void Console::setSelectedCommand(Commands selectedCommand)
{
    Console::selectedCommand = selectedCommand;
}

const vector<string> &Console::getParsedCommand() const
{
    return parsedCommand;
}

void Console::setParsedCommand(const vector<string> &parsedCommand)
{
    Console::parsedCommand = parsedCommand;
}


