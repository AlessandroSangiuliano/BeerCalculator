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
                else if (console->getParsedCommand().size() == 4)
                {
                    int density = stoi(console->getParsedCommand().at(2));
                    int waterVolume = stoi(console->getParsedCommand().at(3));
                    recipe = new Recipe(console->getParsedCommand().at(1), density, waterVolume);
                }
                else
                {
                    cout << "Syntax error building a new recipe. Use 'help' command to see the syntax!" << endl;
                    continue;
                }

                recipe->description();
                break;
            case Commands::addHop:

                if (!recipe)
                {
                    cout << "You need to build a new Recipe before adding a Hop. Use the 'help' command to see how to do.";
                    continue;
                }

                if (console->getParsedCommand().size() != 6)
                {
                    cout << "Syntaz error. Use the 'help' command to see the syntax" << endl;
                    continue;
                }

                recipe->buildHopFromCommand(console->getParsedCommand());
                break;
            case Commands::calculateIbu:
                recipe->setIbu(0);
                recipe->calculateIBU();
                recipe->description();
                break;
            case Commands::removeHop:
                recipe->removeHop();
                break;
            case Commands::printHopsIbu:
                recipe->printHopsIbu();
                break;
            default:
                break;
        }
    }

    delete console;

    return 0;
}
