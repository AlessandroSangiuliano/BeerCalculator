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
        console->parseCommand();

        switch (console->getSelectedCommand())
        {
            case quit:
                delete console;
                cout << "Beer Calculator is quitting" << endl;
                exit(0);
        }
    }

    delete console;

    return 0;
}
