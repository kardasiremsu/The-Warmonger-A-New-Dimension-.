////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////

#ifndef ELVES_H
#define ELVES_H

#include "Faction.h"

class Elves:public Faction{
    public:
        Elves(string = "", int  = 0,int = 0,int = 0, int = 0);
        void PerformAttack();
        void ReceiveAttack(string,int,int);
        int PurchaseWeapons(int);
        int PurchaseArmors(int);
        void Print();
};


#endif