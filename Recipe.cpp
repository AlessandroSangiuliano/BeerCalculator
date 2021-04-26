//
// Created by slex on 24/04/21.
//

#include "Recipe.h"

int Recipe::getCorrectionFactor() const
{
    return correctionFactor;
}

void Recipe::setCorrectionFactor(int correctionFactor)
{
    Recipe::correctionFactor = correctionFactor;
}

double Recipe::getWaterVolume() const
{
    return waterVolume;
}

void Recipe::setWaterVolume(double waterVolume)
{
    Recipe::waterVolume = waterVolume;
}

const string &Recipe::getBeerName() const
{
    return beerName;
}

void Recipe::setBeerName(const string &beerName)
{
    Recipe::beerName = beerName;
}

Recipe::Recipe(const string &beerName)
{
    this->beerName = beerName;
    this->correctionFactor = 1000;
}

Recipe::Recipe(const string &beerName, int aDensity, int aWaterVolume)
{
    this->beerName = beerName;
    this->waterVolume = aWaterVolume;
    this->density = aDensity;
    this->correctionFactor = 1000;
}


Recipe::~Recipe()
{

}

void Recipe::description()
{
    if (ibu == 0)
        cout << "Beer name: " << this->beerName << "; Volume: " << waterVolume << "; Density: " << density << "; IBU: not calculated" << endl;
    else
        cout << "Beer name: " << this->beerName << "; Volume: " << waterVolume << "; Density: " << density << "; IBU: " << ibu << endl;

}

int Recipe::getDensity() const
{
    return density;
}

void Recipe::setDensity(int density)
{
    Recipe::density = density;
}

const vector<Hop> &Recipe::getHops() const
{
    return hops;
}

void Recipe::setHops(const vector<Hop> &hops)
{
    Recipe::hops = hops;
}

void Recipe::buildHopFromCommand(vector<string> aParsedCommand)
{
    string name = aParsedCommand.at(1);
    float quantity = stod(aParsedCommand.at(2));
    float alphaAcid = stod(aParsedCommand.at(3));
    float utilization = stod(aParsedCommand.at(4));
    int boilTime = stoi(aParsedCommand.at(5));

    Hop *hop = new Hop(name, quantity, alphaAcid, utilization, boilTime);

    hops.push_back(hop);

    cout << "New hop added..." << endl;
    hops.at(hops.size() - 1).description();
}

float Recipe::calculateIBU()
{
    int size = hops.size();

    for (int i = 0; i < size; ++i)
    {
        ibu += hops.at(i).calculateIbuContribution(correctionFactor, density, waterVolume);
    }

    return ibu;
}

float Recipe::getIbu() const
{
    return ibu;
}

void Recipe::setIbu(float ibu)
{
    Recipe::ibu = ibu;
}

void Recipe::removeHop()
{
    cout << "Removing Hop: " << hops.at(hops.size() - 1).getHopName() << endl;
    hops.pop_back();
}

void Recipe::printHopsIbu()
{
    int size = hops.size();

    cout << "Hops IBU..." << endl;

    for (int i = 0; i < size; ++i)
    {
        cout << "Name: " << hops.at(i).getHopName() <<
        "; Quantity: " << hops.at(i).getQuantity() <<
        "; IBU: " << hops.at(i).getIbuContribution() <<
        "; Boil Time: " << hops.at(i).getBoilTime() << endl;
    }
}

