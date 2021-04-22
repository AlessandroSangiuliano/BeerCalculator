#include <iostream>
#include "Console.h"

using namespace std;

int main()
{
    cout << "Welcome to Beer Calculator. Enjoy you beer!" << std::endl;

    Console *console = new Console();

    cout << "Insert commands" << endl;

    while (console->readCommand())
    {
        cout << "Command: " << console->getCommand() << endl;
    }

    delete console;

    return 0;
}
