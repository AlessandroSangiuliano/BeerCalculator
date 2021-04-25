//
// Created by slex on 24/04/21.
//

#include "Hop.h"

Hop::Hop(const string &hopName, double quantity, double alphaAcid, int boilTime, double utilization)
{}

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

double Hop::getQuantity() const
{
    return quantity;
}

void Hop::setQuantity(double quantity)
{
    Hop::quantity = quantity;
}

double Hop::getAlphaAcid() const
{
    return alphaAcid;
}

void Hop::setAlphaAcid(double alphaAcid)
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

double Hop::getUtilization() const
{
    return utilization;
}

void Hop::setUtilization(double utilization)
{
    Hop::utilization = utilization;
}
