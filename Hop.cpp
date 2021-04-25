//
// Created by slex on 24/04/21.
//

#include "Hop.h"
#include <cmath>

Hop::Hop()
{

}

Hop::Hop(const string &hopName, float quantity, float alphaAcid, float utilization, int boilTime)
{
    this->hopName = hopName;
    this->quantity = quantity;
    this->alphaAcid = alphaAcid;
    this->utilization = utilization;
    this->boilTime = boilTime;
    this->ibuContribution = -1;
    this->referringDensity = 1050;
}

Hop::Hop(Hop *pHop)
{
    this->hopName = pHop->hopName;
    this->quantity = pHop->quantity;
    this->alphaAcid = pHop->alphaAcid;
    this->utilization = pHop->utilization;
    this->boilTime = pHop->boilTime;
    this->ibuContribution = -1;
    this->referringDensity = 1050;
}

Hop::~Hop()
{

}

const string &Hop::getHopName() const
{
    return hopName;
}

void Hop::setHopName(const string &hopName)
{
    Hop::hopName = hopName;
}

float Hop::getQuantity() const
{
    return quantity;
}

void Hop::setQuantity(float quantity)
{
    Hop::quantity = quantity;
}

float Hop::getAlphaAcid() const
{
    return alphaAcid;
}

void Hop::setAlphaAcid(float alphaAcid)
{
    Hop::alphaAcid = alphaAcid;
}

int Hop::getBoilTime() const
{
    return boilTime;
}

void Hop::setBoilTime(int boilTime)
{
    Hop::boilTime = boilTime;
}

float Hop::getUtilization() const
{
    return utilization;
}

void Hop::setUtilization(float utilization)
{
    Hop::utilization = utilization;
}

void Hop::description()
{
    cout << "Hop name: " << this->hopName << endl;
    cout << "Hop quantity: " << this->quantity << endl;
    cout << "Hop alpha acid: " << this->alphaAcid << endl;
    cout << "Hop utilization: " << this->utilization << endl;
    cout << "Hop boil time: " << this->boilTime << endl;
}

float Hop::getIbuContribution() const
{
    return ibuContribution;
}

void Hop::setIbuContribution(float ibuContribution)
{
    Hop::ibuContribution = ibuContribution;
}

float Hop::calculateIbuContribution(int correctionFactor, int density, int waterVolume)
{
    float util = utilization / 100;
    float aa = alphaAcid / 100;
    float den = (float) density / 1000;
    float refDen = (float) referringDensity / 1000;
    ibuContribution = 0;
    float densityCorrection = den > refDen ? (1 + (den - refDen) / 0.2) : 1;

    float num = (float) (quantity * util * aa * correctionFactor);
    float dem = (float) (waterVolume * densityCorrection);

    ibuContribution = num / dem;

    return ibuContribution;
}

int Hop::getReferringDensity() const
{
    return referringDensity;
}

void Hop::setReferringDensity(int referringDensity)
{
    Hop::referringDensity = referringDensity;
}
