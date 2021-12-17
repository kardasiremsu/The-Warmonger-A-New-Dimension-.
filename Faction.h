////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////

#ifndef FACTION_H
#define FACTION_H

#include <iostream>
using namespace std;

class Faction{
    protected:
        string name;
        int number_of_units;
        int attack_point;
        int health_point;
        int unit_regeneration_number;
        int total_health; //Multiplication of number of units and health point
        bool isalive; //flag controlling if the faction is alive
        Faction *first_enemy;
        Faction *second_enemy;
    public:
        Faction(string = "", int  = 0,int = 0,int = 0, int = 0);
        void AssignEnemies(Faction * , Faction *);
        virtual void PerformAttack() = 0 ;
        virtual void ReceiveAttack(string,int,int) = 0;
        virtual int PurchaseWeapons(int) = 0;
        virtual int PurchaseArmors(int) = 0;
        virtual void Print();
        void EndTurn();
        string getName()const{return this->name;}
        bool IsAlive() const {return this->isalive;}
};


#endif