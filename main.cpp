#include <iostream>
#include "Hero.cpp"
#include "Menu.cpp"
using namespace std;
int main(){
    Menu menu1;
    Hero hero1(menu1.character_prof);
    hero1.getStats();
    return 0;
}