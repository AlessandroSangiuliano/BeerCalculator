//
// Created by slex on 24/04/21.
//

#ifndef BEERCALCULATOR_HOP_H
#define BEERCALCULATOR_HOP_H

#include <string>
#include <iostream>

using namespace std;

class Hop
{
private:
    string hopName;
    float quantity;
    float alphaAcid;
    int boilTime;
    float utilization;
    float ibuContribution;
    int referringDensity;
public:
    Hop();

    Hop(const string &hopName, float quantity, float alphaAcid, float utilization, int boilTime);

    Hop(Hop *pHop);

    virtual ~Hop();

    const string &getHopName() const;

    void setHopName(const string &hopName);

    float getQuantity() const;

    void setQuantity(float quantity);

    float getAlphaAcid() const;

    void setAlphaAcid(float alphaAcid);

    int getBoilTime() const;

    void setBoilTime(int boilTime);

    float getUtilization() const;

    void setUtilization(float utilization);

    void description();

    float getIbuContribution() const;

    void setIbuContribution(float ibuContribution);

    float calculateIbuContribution(int correctionFactor, int density, int waterVolume);

    int getReferringDensity() const;

    void setReferringDensity(int referringDensity);
};


#endif //BEERCALCULATOR_HOP_H
