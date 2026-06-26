#include <iostream>
#include "Random.h"
#include "game.h"
#include "player.h"

bool Encounter::Monster(Player& p) { //returns false if choice is not valid
    std::cout << "A monster has appeared!!" << '\n' << "Choose 1 to attempt to escape and 2 to fight (if you try to escape, 10 percent chances are that you fail and die)" << '\n';
    int choice {};
    std::cin >> choice;

    if (p.attack_points == 0) {
        std::cout << "Oh wait, you are out of attack points, guess you will have to try your luck with an escape" << '\n';
        choice = 1;
    }

    switch (choice) {
    case 1: {
        std::cout << "Trying to escape" << '\n';
        if (Random::next_bool(0.9)) {
            std::cout << "You have escaped successfully!" << '\n';
            return true;
        }
        else {
            std::cout << "The attempt was unsuccessful, YOU DIED" << '\n';
            return true;
        }
        break;
    }

    case 2: {
        std::cout << "You have " << p.attack_points << " attack points, enter how many you would like to use for this attack" << '\n';
        int player_attack{};
        std::cin >> player_attack;

        while (!p.attack(player_attack)) {}

        int monster_attack{Random::next_range(10, 80)};

        if (monster_attack < player_attack) {
            std::cout << "You WON!!! You have earnt 500 gold" << '\n';
            p.earn(500);
            return true;
        }
        else if (monster_attack == player_attack) {
            std::cout << "You have tied :( , you neither lose health nor win gold" << '\n';
            return true;
        }
        else {
            std::cout << "You lost" << '\n';
            p.damage(monster_attack);
            if (p.alive) {
                std::cout << "You now have " << p.health << " health points" << '\n';
                return true;
            }
            else {
                return true;;
            }
        }
        break;
    }

    default:
        std::cout << "You have entered a number other than 1 or 2, please re-enter your choice" << '\n';
        return false;
    }
    return true;
}

bool Encounter::Treasure (Player& p) {
    std::cout << "You have entered a treasure room!! You can either just leave or take an 80 percent chance and open the treasure,\n if it turns out to be a trap, you lose health, and if you are lucky, even then the amount earnt is random" << '\n';
    std::cout << "Enter 1 to leave and 2 to open the treasure box" << '\n';
    int choice{};
    std::cin >> choice;
    
    switch (choice)
    {
    case 1:
        std::cout << "You have chosen to leave" << '\n';
        return true;
    
    case 2:
        std::cout << "You have chosen to test your luck" << '\n';
        if(Random::next_bool(0.8)) {
            int win_amt = Random::next_range(50, 100);
            p.earn(win_amt);
            std::cout << "Congrats!! The treasure was not a trap, you have won " << win_amt << " gold coins" << '\n';
        }
        else {
            int dmg {Random::next_range(50, 80)};
            std::cout << "NOO It was a TRAP, you lose " << dmg << " health points" << '\n';
            p.damage(dmg);
        }
        return true;

    default:
        std::cout << "Please enter a valid choice" << '\n';
        return false;
    }
}

void Encounter::Trap (Player& p) {
    int dmg {Random::next_range(100, 200)};
    std::cout << "You have encountered a trap!!! You lose " << dmg << " no.of health points" << '\n';
    p.damage(dmg);
}

bool Shop(Player& p) {
    if (p.gold < 150) {
        std::cout << "You do not have enough gold coins to purchase anything here" << '\n';
        return true;
    }
    std::cout << "Welcome, you have entered the shop, available items are attack points potion, 100 attack points for 150 gold coins or health points potion, 100 health for 200 gold coins" << '\n';
    std::cout << "As of now you have " << p.gold << " gold coins. " << "Enter 1 to purchase an attack points potion and 2 to purchase a health points potion" << '\n';
    int choice{};
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (p.spend(150)) {
            p.attack_points += 100;
            std::cout << "Congratulations!! You have purchased an attack points potion, you now have " << p.gold << " gold coins and " << p.attack_points << " attack points" << '\n';
        }
        else {
            std::cout << "You do not have enough gold coins to purchase an attack potion" << '\n';
        }
        break;

    case 2:
        if (p.spend(200)) {
            p.heal(100);
            std::cout << "Congratulations, you have purchased a health potion, you now have " << p.health << " health points and " << p.gold << " gold coins" << '\n';
        break;
        } 
        else {
            std::cout << "You do not have enough gold coins to purchase a health potion\n";
        }   

    default:
        std::cout << "Please enter a valid choice " << '\n';
        return false;
    }
    return true;
}

void Display_stats(Player& p) {
    std::cout << "You have " << p.gold << " gold coins, " << p.attack_points << " attack points, and " << p.health << " health points" << '\n';
}



    