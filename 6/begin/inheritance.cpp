#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <sys/types.h>

class Entity
{
protected:
    int health_points;
    int attack_damage;
public:
    Entity(int health_points, int attack_damage): 
        health_points(health_points), 
        attack_damage(attack_damage) {}
    void increase_damage(size_t delta_damage) { attack_damage += delta_damage; }
    void increase_health(size_t delta_health) { health_points += delta_health; }
    int get_health_points() { return health_points; }
    int get_attack_damage() { return attack_damage; }
    virtual void get_damaged() = 0;
    virtual void attack() = 0;
    // ~Entity();
};

class Hero_mage: virtual public Entity
{
public:
    Hero_mage(int health_points, int attack_damage): 
        Entity (health_points, attack_damage) {}
    void get_damaged() { health_points -= 10; }
    void attack() { printf("Attacked by %d units\n", attack_damage * 2); }
};

class Hero_melee: virtual public Entity
{
public:
    Hero_melee(int health_points, int attack_damage): 
        Entity (health_points, attack_damage) {}
    void get_damaged() { health_points -= 5; }
    void attack() { printf("Attacked by %f units\n", attack_damage * 1.5f); }
};

int main(int argc, char** argv)
{
    Hero_mage* mage = new Hero_mage(100, 20);
    Hero_melee* melee = new Hero_melee(200, 20);
    printf("%d\n", mage->get_health_points());
    mage->get_damaged();
    printf("%d\n", mage->get_health_points());
    mage->attack();

    return 0;
}