#include "swordsman.h"



Swordsman::Swordsman(const std::string& name, int hp, Weapon* weapon):Player{name, hp}, weapon{weapon}
{
}

void Swordsman::fight(Player* player){
	if (!is_reached(player)) {
		std::cout << *player << " is too far"<<"\n";
		return;
	}
	int damage = weapon->attack();
	player->take_damage(damage);
	std::cout << *player << " take "<< damage<<" damage" << "\n";
	if (player->is_dead()) {
		std::cout << *player << " is dead" << "\n";
	}
}
bool Swordsman::is_reached(Player* player) const {
	int distance = get_distance(x, y, player->get_x(), player->get_y());
		return (distance <= weapon->get_radius());
	 
}

std::string Swordsman::full_info() const {
	return Player::full_info();
}
