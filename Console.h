//
// Created by slex on 22/04/21.
//

#ifndef BEERCALCULATOR_CONSOLE_H
#define BEERCALCULATOR_CONSOLE_H

#include <string>
#include <map>

using namespace std;

enum Commands  {
        quit,
        addHop,
        addGrain
};

class Console
{
private:
    /*int correctionFactor;
    double waterVolume;
    double alphaAcid;
    double utilization;
    int densityCorrection;*/

    string commandLine;
    string command;
    Commands selectedCommand;
    map<string, Commands> commandMap;

public:
    const string &getCommand() const;

    void setCommand(const string &command);

public:
    Console();

    virtual ~Console();

    bool readCommand();

    void resetCommand();

    bool parseCommand();

    string stringProcess(string aString);

    void help();

    Commands getSelectedCommand() const;

    void setSelectedCommand(Commands selectedCommand);
};


#endif //BEERCALCULATOR_CONSOLE_H
