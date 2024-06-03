#include "player.h"

Player::Player(const std::string& name, int hp): name{name}, hp{hp}{}

void Player::move(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Player::move_by(int delta_x, int delta_y)
{
    x += delta_x;
    y += delta_y;
}

void Player::take_damage(int damage)
{
    hp -= damage;
    if (hp < 0) hp = 0;
}

bool Player::is_dead() const
{
    return hp <= 0;
}

std::string Player::get_name() const
{
    return name;
}

int Player::get_hp() const
{
    return hp;
}

int Player::get_x() const
{
    return x;
}

int Player::get_y() const
{
    return y;
}

std::string Player::full_info() const
{
    return "Name: " + name + "\n" +
        "Coordinates: (" + std::to_string(x) + ", " + std::to_string(y) + ")\n" +
        "HP: " + std::to_string(hp);
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    return out << "Player " << player.get_name();
}
