#include <iostream>
#include "Random.h"
#include "player.h"

void Player::heal(int amount) {
    if ((health + amount) > 100) {
        while (health <= 100) {
            health++;
        }
    }
    else {
        health += amount;
    }
}

void Player::damage(int amount) {
    health -= amount;

    if (health <= 0) {
        alive = false;
        std::cout << "YOU DIED" << '\n';
    }
}

bool Player::spend(int amount) {    
    if(gold < amount)
        return false;

    gold -= amount;
    return true;
}

void Player::earn(int amount) {
    gold += amount;
}

bool Player::attack(int amount) {
    if (attack_points < amount) {
        std::cout << "You have insufficient attack points, please re-enter the number of attack points you would like to use" << '\n';
        return false;
    }
    else {
        attack_points -= amount;
        return true;
    }
}