////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////

#include "Merchant.h"
#include <iostream>
#include <string>
using namespace std;

Merchant::Merchant(int starting_weapon_point, int starting_armor_point){
    this->starting_weapon_point = starting_weapon_point;
    this->starting_armor_point = starting_armor_point;
    this->weapon_point = starting_weapon_point;
    this->armor_point = starting_armor_point;
    this->revenue = 0;
    this->firstfaction = NULL;
    this->secondfaction = NULL;
    this->thirdfaction = NULL;
}

void Merchant::AssignFactions(Faction *first, Faction *second, Faction* third){
    this->firstfaction = first;
    this->secondfaction = second;
    this->thirdfaction = third;
}

bool Merchant::SellWeapons(string faction, int weapon_point){
    bool isalive;
    Faction *who;
    //For finding which faction
    if(faction == firstfaction->getName()){
        isalive = firstfaction->IsAlive();
        who = firstfaction;
    }

    else if(faction == secondfaction->getName()){
        isalive = secondfaction->IsAlive();
        who = secondfaction;
    }
    
    else if(faction == thirdfaction->getName()){
        isalive = thirdfaction->IsAlive();
        who = thirdfaction;
    }
    
    if(!isalive){ //Faction is not alive
        cout << "The faction you want to sell weapons is dead!"  << endl;
        return false;
    }

    else if(weapon_point > this->weapon_point){ //Faction is alive but there is not enough weapons
        cout << "You try to sell more weapons than you have in possession." << endl;
        return false;
    }
    //Conditions are okey can sold
    cout << "Weapons sold!" << endl; 
    int profit = who->PurchaseWeapons(weapon_point);
    this->revenue += profit;
    this->weapon_point -= weapon_point;
    return true;
}

bool Merchant::SellArmors(string faction, int armor_point){
    bool isalive;
    Faction *who;
    //For finding which faction
    if(faction == firstfaction->getName()){
        isalive = firstfaction->IsAlive();
        who = firstfaction;
    }

    else if(faction == secondfaction->getName()){
        isalive = secondfaction->IsAlive();
        who = secondfaction;
    }
    
    else if(faction == thirdfaction->getName()){
        isalive = thirdfaction->IsAlive();
        who = thirdfaction;
    }

    if(!isalive){ //Faction is not alive
        cout << "The faction you want to sell armors is dead!"  << endl;
        return false;
    }

    else if(armor_point > this->armor_point){ //Faction is alive but there is not enough armors
        cout << "You try to sell more armors than you have in possession." << endl;
        return false;
    }
    //Conditions are okey can sold
    cout << "Armors sold!" << endl;
    int profit = who->PurchaseArmors(armor_point);
    this->revenue += profit;
    this->armor_point -= armor_point;
    return true;
}

void Merchant::EndTurn(){ // New turn
    this->weapon_point = this->starting_weapon_point;
    this->armor_point = this->starting_armor_point;
}