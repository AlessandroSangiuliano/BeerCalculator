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

int Recipe::getDensityCorrection() const
{
    return densityCorrection;
}

void Recipe::setDensityCorrection(int densityCorrection)
{
    Recipe::densityCorrection = densityCorrection;
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
    this->referringDensity = 1050;
    this->correctionFactor = 1000;
}

Recipe::~Recipe()
{

}

void Recipe::description()
{
    cout << "Beer name: " << this->beerName << endl;
    /*cout << "Hop grams: " << this->hopQuantity << endl;
    cout << "Alpha acid: " << this->beerName << endl;*/
}

int Recipe::getReferringDensity() const
{
    return referringDensity;
}

int Recipe::getCorrectonFactor() const
{
    return correctonFactor;
}

int Recipe::getDensity() const
{
    return density;
}

void Recipe::setDensity(int density)
{
    Recipe::density = density;
}


