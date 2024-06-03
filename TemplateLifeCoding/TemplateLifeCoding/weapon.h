#pragma once
#include <iostream>
#include <sstream>
#include "player.h"


class Weapon {
protected:
    int damage;
    int durability;
    int radius;
public:
    Weapon(int damage, int durability, int radius);

    virtual int get_radius() const;
    int get_damage() const;
    int get_durability() const;

    virtual int attack();

    virtual std::string to_string() const;
};

std::ostream& operator<<(std::ostream& out, const Weapon& weapon);

