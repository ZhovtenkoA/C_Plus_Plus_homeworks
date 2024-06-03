#pragma once
#include <iostream>
#include "player.h"
#include "weapon.h"
#include "utilities.h"


class Swordsman:public Player
{
	Weapon* weapon;
public:
	Swordsman(const std::string& name, int hp, Weapon* weapon);

	void fight(Player* player)override;
	bool is_reached(Player* player) const override;
	std::string full_info() const override;


};

