////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////

#ifndef MERCHANT_H
#define MERCHANT_H

#include "Faction.h"

class Merchant{
    private:
        Faction *firstfaction;
        Faction *secondfaction;
        Faction *thirdfaction;
        int starting_weapon_point;
        int starting_armor_point;
        int revenue;
        int weapon_point;
        int armor_point;
    public:
        Merchant(int = 0, int = 0);
        void AssignFactions(Faction*, Faction*, Faction*);
        bool SellWeapons(string, int);
        bool SellArmors(string, int);
        void EndTurn();
        int GetWeaponPoints() const {return this->weapon_point;}
        int GetArmorPoints() const {return this->armor_point;}
        int GetRevenue() const{return this->revenue;}
};

#endif