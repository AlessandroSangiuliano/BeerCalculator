//
// Created by slex on 22/04/21.
//

#include "Console.h"
#include <iostream>

Console::Console()
{
    Console::resetCommand();
    Console::commandMap("quit", );
}

Console::~Console()
{

}

const string &Console::getCommand() const
{
    return command;
}

void Console::setCommand(const string &command)
{
    Console::command = command;
}

bool Console::readCommand()
{
    bool didRead = false;

    if (command.compare("none") != 0)
        Console::resetCommand();

    cout << "#: ";

    getline(cin, command);

    if (command.compare("none") != 0) {
        didRead = true;
    }

    return didRead;
}

bool Console::parseCommand()
{
    bool isValid = false;


}

void Console::resetCommand()
{
    command.clear();
    command = "none";
}


