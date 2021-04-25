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
    double quantity;
    double alphaAcid;
    int boilTime;
    double utilization;
public:
    Hop(const string &hopName, double quantity, double alphaAcid, int boilTime, double utilization);

    virtual ~Hop();

    const string &getHopName() const;

    void setHopName(const string &hopName);

    double getQuantity() const;

    void setQuantity(double quantity);

    double getAlphaAcid() const;

    void setAlphaAcid(double alphaAcid);

    int getBoilTime() const;

    void setBoilTime(int boilTime);

    double getUtilization() const;

    void setUtilization(double utilization);
};


#endif //BEERCALCULATOR_HOP_H
