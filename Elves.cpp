////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////

#include "Elves.h"
#include <iostream>
#include <string>
using namespace std;

Elves::Elves(string name,int number_of_units,int attack_point, int health_point,int unit_regeneration_number):Faction(name,number_of_units,attack_point,health_point,unit_regeneration_number)
{}

void Elves::PerformAttack(){
    if(first_enemy != NULL && second_enemy == NULL){ //only first enemy is exist
            first_enemy->ReceiveAttack("Elves",this->number_of_units,this->attack_point);
    }

    else if(first_enemy == NULL && second_enemy != NULL){  //only second enemy is exist
        second_enemy->ReceiveAttack("Elves",this->number_of_units,this->attack_point*1.5);
    }

    else{ //Both enemies are exist
        first_enemy->ReceiveAttack("Elves",this->number_of_units * 0.6,this->attack_point); //For orcs
        second_enemy->ReceiveAttack("Elves",this->number_of_units - this->number_of_units * 0.6,this->attack_point*1.5); //For dwarves
    }
}

void Elves::ReceiveAttack(string who, int units, int incoming_attack){
    if(who =="Orcs"){
        incoming_attack = incoming_attack *1.25;
    }
    else if (who == "Dwarves"){
        incoming_attack = incoming_attack *0.75;
    }
    int damage = units * incoming_attack;
    int reduce = damage/this->health_point;
    this->number_of_units -= reduce;
}

int Elves::PurchaseWeapons(int weapon_point){
    this->attack_point += weapon_point * 2;
    return 15*weapon_point; //gold value
}

int Elves::PurchaseArmors(int armor_point){
    this->health_point += armor_point *4;
    return 5*armor_point; //gold value
}

void Elves::Print(){
    cout << "\"You cannot reach our elegance.\"" << endl;
    Faction::Print();
}
        