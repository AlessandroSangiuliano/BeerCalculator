//
// Created by slex on 24/04/21.
//

#ifndef BEERCALCULATOR_RECIPE_H
#define BEERCALCULATOR_RECIPE_H

#include <string>
#include <iostream>

using namespace std;

class Recipe
{
private:
    int correctionFactor;
    double waterVolume;
    int density;
    int densityCorrection;
    string beerName;
    int referringDensity;
    int correctonFactor;
public:
    int getCorrectionFactor() const;

    void setCorrectionFactor(int correctionFactor);

    double getWaterVolume() const;

    void setWaterVolume(double waterVolume);

    int getDensityCorrection() const;

    void setDensityCorrection(int densityCorrection);

    const string &getBeerName() const;

    void setBeerName(const string &beerName);

    int getReferringDensity() const;

    int getCorrectonFactor() const;

    int getDensity() const;

    void setDensity(int density);

    explicit Recipe(const string &beerName);

    virtual ~Recipe();

    void description();

};


#endif //BEERCALCULATOR_RECIPE_H
