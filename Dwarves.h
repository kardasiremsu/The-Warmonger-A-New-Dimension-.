////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////

#ifndef DWARVES_H
#define DWARVES_H

#include "Faction.h"

class Dwarves:public Faction{
    public:
        Dwarves(string = "", int  = 0,int = 0,int = 0, int = 0);
        void PerformAttack();
        void ReceiveAttack(string,int,int);
        int PurchaseWeapons(int);
        int PurchaseArmors(int);
        void Print();
};

#endif

