// Hero.cpp
#include<iostream>
#include "Hero.h"
using namespace std;
Hero::Hero(string name, int profession)
{
	heroName = name;
    if (profession == Hero::Warrior){
        cout << "You have chosen warrior."<< endl;
		setStats(100,100,10,1);
    }
    if (profession == Hero::Hunter){
        cout << "You have chosen hunter."<< endl;
		setStats(70,70,100,1.4);
    }
    if (profession == Hero::Mage){
        cout << "You have chosen mage."<< endl;
		setStats(50, 140,70,0.8);
    }
}
void Hero::setStats(int newHp, int newAD, int newRange, float newAS)
{
	hp=newHp;
    attack_damage=newAD;
    range = newRange;
    attack_speed = newAS;
}
void Hero::getStats()
{
    cout << "Your statistics are: "<< endl;
    cout << "HP: " << hp<<'\n';
    cout << "AD: " << attack_damage<<'\n';
    cout << "AS: " << attack_speed <<'\n';
    cout << "Range: " << range <<'\n';
}
