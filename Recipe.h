//
// Created by slex on 24/04/21.
//

#ifndef BEERCALCULATOR_RECIPE_H
#define BEERCALCULATOR_RECIPE_H

#include <string>
#include <iostream>
#include <vector>
#include "Hop.h"

using namespace std;

class Recipe
{
private:
    int correctionFactor;
    double waterVolume;
    int density;
    string beerName;
    vector<Hop> hops;
    float ibu;
public:
    int getCorrectionFactor() const;

    void setCorrectionFactor(int correctionFactor);

    double getWaterVolume() const;

    void setWaterVolume(double waterVolume);

    const string &getBeerName() const;

    void setBeerName(const string &beerName);

    int getReferringDensity() const;

    int getDensity() const;

    void setDensity(int density);

    explicit Recipe(const string &beerName);

    explicit Recipe(const string &beerName, int aDensity, int aWaterVolume);

    virtual ~Recipe();

    void description();

    const vector<Hop> &getHops() const;

    void setHops(const vector<Hop> &hops);

    void buildHopFromCommand(vector<string> aParsedCommand);

    float calculateIBU();

    float getIbu() const;

    void setIbu(float ibu);

    void removeHop();

    void printHopsIbu();

};


#endif //BEERCALCULATOR_RECIPE_H
