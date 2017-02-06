// Hero.cpp

#include "Hero.h"
using namespace std;
Hero::Hero(int profession)
{
    if (profession ==1){
        hp=100;
        attack_damage=100;
        range=10;
        attack_speed= 1;
    }
    if (profession==2){
        hp=70;
        attack_damage=70;
        range = 100;
        attack_speed = 1.4;
    }
    if (profession==3){
        hp=50;
        attack_damage=140;
        range = 70;
        attack_speed = 0.8;
    }
}

void Hero::getStats()
{
    cout << "Your statistics are: "<< endl;
    cout << "HP: " << attack_damage <<'\n';
    cout << "AD: " << hp <<'\n';
    cout << "AS: " << attack_speed <<'\n';
    cout << "Range: " << range <<'\n';
}