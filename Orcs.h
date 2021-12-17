////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////

#ifndef ORCS_H
#define ORCS_H
#include "Faction.h"
#include <iostream>

class Orcs:public Faction{
    public:
        Orcs(string = "", int  = 0,int = 0,int = 0, int = 0);
        void PerformAttack();
        void ReceiveAttack(string,int,int);
        int PurchaseWeapons(int);
        int PurchaseArmors(int);
        void Print();
};

#endif