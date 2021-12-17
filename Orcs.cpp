////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////


#include "Orcs.h"
#include <iostream>
#include <string>
using namespace std;

Orcs::Orcs(string name,int number_of_units,int attack_point, int health_point,int unit_regeneration_number) :Faction(name,number_of_units,attack_point,health_point,unit_regeneration_number)
{}

void Orcs::PerformAttack(){
    if(first_enemy != NULL && second_enemy == NULL){ //only first enemy is exist            
        first_enemy->ReceiveAttack("Orcs",this->number_of_units,this->attack_point);
    }

    else if(first_enemy == NULL && second_enemy != NULL){ //only second enemy is exist
        second_enemy->ReceiveAttack("Orcs",this->number_of_units,this->attack_point);
    }

    else{ //Both enemies are exist
        first_enemy->ReceiveAttack("Orcs",this->number_of_units * 0.7,this->attack_point);
        second_enemy->ReceiveAttack("Orcs",this->number_of_units - this->number_of_units * 0.7,this->attack_point); 
    }
}

void Orcs::ReceiveAttack(string who, int units,int incoming_attack){
    if(who =="Elves"){ // if attack comes from elves
        incoming_attack = incoming_attack *0.75;
    }

    else if (who == "Dwarves"){ // if attack comes from dwarves
        incoming_attack = incoming_attack *0.8;
    }

    int damage = units * incoming_attack; 
    int reduce = damage/this->health_point; //reduces number of units by total damage / health point
    this->number_of_units -= reduce;
}

int Orcs::PurchaseWeapons(int weapon_point){
    this->attack_point += weapon_point * 2;
    return 20*weapon_point; //returning gold value
}

int Orcs::PurchaseArmors(int armor_point){
    this->health_point += armor_point *3;
    return armor_point; //returning gold value
}

void Orcs::Print(){
    cout << "\"Stop running, you’ll only die tired!\"" << endl;
    Faction::Print();
}