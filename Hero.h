// Hero.h

#ifndef Hero_H
#define Hero_H
class Hero
{
    int hp, attack_damage, range, inventory_size, inventory_space, invetory_taken;
    float attack_speed;
    float crit_chance = 0.0;
    float crit_multiplier = 1.0;
    
    public:
    Hero(int hero_profession);
    void getStats();
};
#endif
