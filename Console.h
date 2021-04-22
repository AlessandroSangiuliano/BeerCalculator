//
// Created by slex on 22/04/21.
//

#ifndef BEERCALCULATOR_CONSOLE_H
#define BEERCALCULATOR_CONSOLE_H

#include <string>
#include <map>

using namespace std;

enum Commands  {
        quit
};

class Console
{
private:
    /*int correctionFactor;
    double waterVolume;
    double alphaAcid;
    double utilization;
    int densityCorrection;*/

    string command;
    Commands commandList;
    map<const char *, Commands> commandMap;

public:
    const string &getCommand() const;

    void setCommand(const string &command);

public:
    Console();

    virtual ~Console();

    bool readCommand();

    void resetCommand();

    bool parseCommand();
};


#endif //BEERCALCULATOR_CONSOLE_H
