#include <iostream>
#include "player.h"
#include "weapon.h"
#include "swordsman.h"


void round(Player* player, Player* enemy) {
    std::cout << *player << " goes now(type move, attack, fullinfo)\n";
    std::string command;
    std::cin >> command;
    if (command == "move") {
        std::cout << "Select side(left, right, up, down): ";
        std::string side;
        std::cin >> side;
        if (side == "left") player->move_by(-5, 0);
        else if (side == "right") player->move_by(5, 0);
        else if (side == "up") player->move_by(0, -5);
        else if (side == "down") player->move_by(0, 5);
        else {
            std::cout << "Incorrect side! " << *player<< " stays at same place!\n";
            return;
        }

        std::cout << *player << " goes to " << side << std::endl;
        std::cout << "New coordinates: (" << player->get_x() << ", "
            << player->get_y() <<")" << std::endl;

        return;
    }

    if (command == "attack") {
        player->fight(enemy);
        return;
    }

    if (command == "fullinfo") {
        std::cout << player->full_info() << std::endl;
        return;
    }

    std::cout << "Unknow commad.\n";
}

int main() {
    //move, attack
    srand(time(0));
    int width = 5, height = 5;
    std::cout << "Arena " << width << "x" << height << std::endl;

    Player* player1 = new Swordsman("Max", 100, new Weapon(20, 50, 5)), * player2 = new Swordsman("Iban", 75, new Weapon(50, 75, 10));

    std::cout << *player1 << " againsts " << *player2 << std::endl;

    player1->move(rand() % width, rand() % height);
    player2->move(rand() % width, rand() % height);

    while (true) {

        round(player1, player2);
        round(player2, player1);
    }

    return 0;
}