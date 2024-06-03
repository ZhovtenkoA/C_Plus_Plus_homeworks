#include "weapon.h"

Weapon::Weapon(int damage, int durability, int radius) 
    : damage{ damage }, durability{ durability }, radius{radius} {}

int Weapon::get_radius() const
{
    return radius;
}

int Weapon::get_damage() const {
    return damage;
}
int Weapon::get_durability() const {
    return durability;
}

int Weapon::attack() {
    if (durability <= 0) return 0;

    durability--;
    return damage;
}

std::string Weapon::to_string() const
{
    std::stringstream ss;
    ss << get_damage() << " damage, " << get_durability() << " durability, " << get_radius() << " m";

    return ss.str();
}

std::ostream& operator<<(std::ostream& out, const Weapon& weapon)
{
    return out << weapon.to_string();
}
