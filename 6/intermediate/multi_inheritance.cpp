#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <vector>
#include <string>

enum class Class_type
{
    melee,
    mage,
    range,
    cast
};

class Ability
{
private:
    const Class_type ability_class;
    u_int8_t ability_level;
    u_int16_t base_damage;
    u_int16_t mana_cost;
public:
    const std::string name;

    Ability(std::string name, u_int8_t ability_level, Class_type* ability_class, u_int16_t base_damage, u_int16_t mana_cost):
    name(name), ability_level(ability_level), ability_class(*ability_class), base_damage(base_damage), mana_cost(mana_cost) { }

    void increase_level() { ++ability_level; }
    void change_base_damage(u_int16_t delta_base_damage) { this->base_damage += delta_base_damage; }
    void change_mana_cost(u_int16_t delta_mana_cost) { this->mana_cost += delta_mana_cost; }

    u_int8_t get_ability_level() { return this->ability_level; }
    u_int16_t get_base_damage() { return this->base_damage; }
    u_int16_t get_mana_cost() { return this->mana_cost; }

    

};

class Entity
{

};

class Hero
{

};

int main(int argc, char** argv)
{


    return 0;
}