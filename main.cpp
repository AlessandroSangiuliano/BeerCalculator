#include <iostream>
#include "Console.h"
#include "Recipe.h"

using namespace std;

int main()
{
    Recipe *recipe;

    cout << "Welcome to Beer Calculator. Enjoy you beer!" << std::endl;

    Console *console = new Console();

    cout << "Insert commands" << endl;

    while (console->readCommand())
    {
        console->parseCommand();

        switch (console->getSelectedCommand())
        {
            case Commands::quit:
                delete console;
                cout << "Beer Calculator is quitting" << endl;
                exit(0);
                break;
            case Commands::help:
                console->help();
                break;
            case Commands::newRecipe:
                cout << "Building a new Recipe!" << endl;
                if (console->getParsedCommand().size() == 2)
                    recipe = new Recipe(console->getParsedCommand().at(1));

                if (console->getParsedCommand().size() == 2)
                {
                    vector<string> commandAndarguments = console->getParsedCommand();
                    string beerName = console->getParsedCommand().at(1);
                    double hopQuantity = stod(commandAndarguments.at(2));
                    double hopAlphaAcid = stod(commandAndarguments.at(3));
                    double utilization = stod(commandAndarguments.at(4));
                    int density = stod(commandAndarguments.at(5));
                    double waterVolume = stod(commandAndarguments.at(6));
                    recipe = new Recipe(beerName, hopQuantity, hopAlphaAcid, utilization, density, waterVolume);
                }
                recipe->description();
                break;
            default:
                break;

        }
    }

    delete console;

    return 0;
}
