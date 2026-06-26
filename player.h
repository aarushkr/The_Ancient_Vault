#ifndef PLAYER
#define PLAYER

struct Player {
    int health{600};
    int gold{0};
    int attack_points{500};
    bool alive{true};

    void heal(int amount);
    void damage(int amount);
    bool spend(int amount);
    void earn(int amount);
    bool attack(int amount);
};
#endif