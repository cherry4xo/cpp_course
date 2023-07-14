#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <vector>
#include <string>
#include <math.h>

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

    void use_ability() 
    {
        printf("Ability %s have been used!\nSpent %d mana\n%d damage dealt\n", this->name.c_str(), this->mana_cost, this->base_damage);
    }
};

class Entity
{
protected:
    u_int16_t health_points;
    u_int16_t mana_pool;
public:
    Entity(u_int16_t health_points, u_int16_t mana_pool):
        health_points(health_points), mana_pool(mana_pool) {}

    void increase_health_points(u_int16_t delta_health_points) { this->health_points += delta_health_points; }
    void increase_mana_pool(u_int16_t delta_mana_pool) { this->mana_pool += delta_mana_pool; }
    u_int16_t get_health_points() { return this->health_points; }
    u_int16_t get_mana_pool() { return this->mana_pool; }
    virtual void get_damage() = 0;
};

class Hero
{
protected:
    std::vector<Ability*> ability_list;
public:
    Hero(std::vector<Ability*> ability_list)
    {
        this->ability_list.assign(ability_list.begin(), ability_list.end());
    }
    virtual void use_ability_by_index(u_int8_t index) = 0;
};

class Player: public Entity, public Hero
{
private:
    const Class_type hero_class;
    float get_damage_class_multiplyer()
    {
        switch (hero_class)
        {
        case Class_type::melee:
            return 1.0f;
            break;
        case Class_type::mage:
            return 1.2f;
            break;
        case Class_type::range:
            return 1.25f;
            break;
        case Class_type::cast:
            return 1.4f;
            break;
        default:
            return 1.0f;
            break;
        }
    }
    bool check_required_mana_cost(u_int16_t mana_cost) { return this->mana_pool >= mana_cost; }
public:
    Player(u_int16_t health_points, u_int16_t mana_pool, std::vector<Ability*> ability_list, const Class_type hero_class):
        Entity(health_points, mana_pool), Hero(ability_list), hero_class(hero_class) {}
    void get_damage() override 
    {
        this->health_points -= floor(10 * get_damage_class_multiplyer());
    }
    void use_ability_by_index(u_int8_t index) override
    {
        u_int16_t ability_mana_cost = (this->ability_list)[index]->get_mana_cost();
        if (check_required_mana_cost(ability_mana_cost))
        {
            increase_mana_pool(-ability_mana_cost);
            (this->ability_list)[index]->use_ability();
        }
    }
};

int main(int argc, char** argv)
{


    return 0;
}