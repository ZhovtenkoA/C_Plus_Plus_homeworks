#pragma once
#include <iostream>
#include <string>

class Player {
protected:
    std::string name;
    int hp;

    int x=0, y=0;
public:
    Player(const std::string& name, int hp);
    
    void move(int x, int y);
    void move_by(int delta_x, int delta_y);
    void take_damage(int damage);

    bool is_dead() const;

    std::string get_name() const;
    int get_hp() const;
    int get_x() const;
    int get_y() const;

    virtual void fight(Player* player) = 0;
    virtual bool is_reached(Player* player) const = 0;

    virtual std::string full_info() const;
};

std::ostream& operator<<(std::ostream& out, const Player& player);