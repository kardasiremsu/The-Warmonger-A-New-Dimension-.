////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////

#include "Dwarves.h"
#include <iostream>
#include <string>
using namespace std;


Dwarves::Dwarves(string name,int number_of_units,int attack_point, int health_point,int unit_regeneration_number):Faction(name,number_of_units,attack_point,health_point,unit_regeneration_number)
{}

void Dwarves::PerformAttack(){
    if(first_enemy != NULL && second_enemy == NULL){ //only first enemy is exist
        first_enemy->ReceiveAttack("Dwarves",this->number_of_units,this->attack_point);
    }

    else if(first_enemy == NULL && second_enemy != NULL){ //only second enemy is exist
        second_enemy->ReceiveAttack("Dwarves",this->number_of_units,this->attack_point);
    }

    else{ //Both enemies are exist
        first_enemy->ReceiveAttack("Dwarves",this->number_of_units * 0.5,this->attack_point);
        second_enemy->ReceiveAttack("Dwarves",this->number_of_units - this->number_of_units * 0.5,this->attack_point);
    }
}

void Dwarves::ReceiveAttack(string who, int units, int incoming_attack){
    int damage = units * incoming_attack;
    int reduce = damage / this->health_point;
    this->number_of_units -= reduce; //Reduces number of units by total damage/health point
}

int Dwarves::PurchaseWeapons(int weapon_point){
    this->attack_point += weapon_point;
    return 10*weapon_point; //gold value
}

int Dwarves::PurchaseArmors(int armor_point){
    this->health_point += armor_point *2;
    return 3*armor_point;  //gold value
}

void Dwarves::Print(){
    cout << "\"Taste the power of our axes!\"" << endl;
    Faction::Print();
}
        