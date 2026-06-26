#include <iostream>
#include "Random.h"
#include "game.h"
#include "player.h"

int main() {
    std::cout << "\n WELCOME to THE ANCIENT VAULT, this is a (mostly) luck based game where you will enter 10 rooms, which will either have a monster, treasure or a \n trap, you need to strategically spend your attack points and gold coins and survive till the 10th round" << '\n';
    Player player;
    std::cout << "Here are your current stats" << '\n';
    Display_stats(player);

    for (int i = 0; i < 10; i++) {
        checks:
            std::cout << "Enter 999 for stats, 111 for shop, 100 to contiue to room\n";
            int choice {};
            std::cin >> choice;

            switch (choice) {
            case 999:   
                Display_stats(player);
                goto checks;

            case 111:
                while(!Shop(player)) {};
                goto checks;

            case 100:
                goto round;
            
            default:
                std::cout << "Enter a valid choice\n";
                goto checks;
            }
        round:
            int room {Random::next_range(1,3)};
            switch (room) {
                case 1:
                    while (!Encounter::Monster(player)){}
                    break;
                case 2:
                    while (!Encounter::Treasure(player)){}
                    break;
                case 3:
                    Encounter::Trap(player);
                    break;
            }

            if (!player.alive)
                break;
    }
    std::cout << "Thank you for playing the game\n";

}

