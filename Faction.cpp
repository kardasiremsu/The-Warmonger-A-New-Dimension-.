////////////////////////////////////
/*       Date: 09.05.2021
         Author: <İREMSU KARDAŞ>         
         ID: <150180081>           */
///////////////////////////////////


#include "Faction.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor with take attributes optionally
Faction::Faction(string name,int number_of_units,int attack_point, int health_point,int unit_regeneration_number){
    this->name = name;
    this->number_of_units = number_of_units;
    this->attack_point = attack_point;
    this->health_point = health_point;
    this->unit_regeneration_number = unit_regeneration_number;
    this->total_health = number_of_units * health_point;
    this->isalive = true;
    this->first_enemy = NULL;
    this->second_enemy = NULL;
}

void  Faction::AssignEnemies(Faction * one, Faction * two){
    this->first_enemy = one;
    this->second_enemy = two;
}


void Faction::Print(){
    cout << "Faction Name:         " << this->name << endl;
    string status;
    if(this->isalive){
        status = "Alive";
        cout << "Status:               " << status << endl;
    }

    else{
        status = "Defeated";
        cout << "Status:               " << status << endl;
    }

    cout << "Number of Units:      " << this->number_of_units << endl;
    cout << "Attack Point:         " << this->attack_point << endl;
    cout << "Health Point:         " << this->health_point << endl;
    cout << "Unit Regen Number:    " << this->unit_regeneration_number << endl;
    cout << "Total Faction Health: " << this->total_health << endl;
} 

void  Faction::EndTurn(){
    this->number_of_units += this->unit_regeneration_number;
    this->total_health = this->number_of_units * this->health_point;
    if(this->number_of_units <= 0){
        this->number_of_units = 0;
        this->total_health = 0;
        this->isalive = false;       
    }
}