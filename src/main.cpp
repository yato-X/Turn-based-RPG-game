#include <iostream>
#include <string>
using namespace std;

// base class for all enemies, right now we only have goblin but this
// could be reused for more enemy types later
class Enemy {
private:
    string name;
    int health;
    int atkpower;

public:
    Enemy(string n, int hp, int atk) {
        name = n;
        health = hp;
        atkpower = atk;
    }

    int getHealth() { return health; }
    int getAtkPower() { return atkpower; }
    string getName() { return name; }

    bool isAlive() {
        return health > 0;
    }

    void damage(int dmg) {
        health -= dmg;
        if (health < 0)
            health = 0;
    }

    void stats() {
        cout << name << " | HP: " << health << " | ATK: " << atkpower << endl;
    }
};

// goblin just inherits everything from Enemy, nothing special about it
class Goblin : public Enemy {
public:
    Goblin() : Enemy("Goblin", 30, 5) {}
};

class Character {
private:
    string name;
    int health;
    int atkpower;

public:
    Character(string n, int hp, int atk) {
        name = n;
        health = hp;
        atkpower = atk;
    }

    int getHealth() { return health; }
    int getAtkPower() { return atkpower; }
    string getName() { return name; }

    bool isAlive() {
        return health > 0;
    }

    void damage(int dmg) {
        health -= dmg;
        if (health < 0)
            health = 0;
    }

    void stats() {
        cout << name << " | HP: " << health << " | ATK: " << atkpower << endl;
    }

    // didn't make this virtual since we only have one character type (warrior)
    // so there was no real reason to force overriding
    void attack(Enemy &enemy) {
        cout << name << " attacks " << enemy.getName() << " for " << atkpower << " damage!" << endl;
        enemy.damage(atkpower);
    }
};

// warrior inherits from Character, same idea as goblin/enemy
class Warrior : public Character {
public:
    Warrior() : Character("Warrior", 100, 20) {}
};

class Game {
private:
    Warrior player;
    Goblin enemy;

    void showmenu() {
        cout << "MENU" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose: ";
    }

    void battle() {
        cout << "Fight" << endl;

        while (player.isAlive() && enemy.isAlive()) {
            cout << endl;
            player.stats();
            enemy.stats();
            cout << "1. Attack" << endl;
            cout << "2. Check Stats" << endl;
            cout << "Choose: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                player.attack(enemy);

                if (!enemy.isAlive()) {
                    cout << enemy.getName() << " is defeated!" << endl;
                    break;
                }

                // goblin gets to hit back after we attack
                cout << enemy.getName() << " attacks " << player.getName() << " for " << enemy.getAtkPower() << " damage!" << endl;
                player.damage(enemy.getAtkPower());

                if (!player.isAlive()) {
                    cout << player.getName() << " has been defeated..." << endl;
                    break;
                }
            } else if (choice == 2) {
                player.stats();
                enemy.stats();
            }
        }
    }

    void checkWinner() {
        if (player.isAlive()) {
            cout << endl << "You survived. VICTORY!" << endl;
        } else {
            cout << endl << "GAME OVER." << endl;
        }
    }

public:
    void startGame() {
        battle();
        checkWinner();
    }
};

int main() {
    bool running = true;

    while (running) {
        cout << "MENU" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            Game vortex;
            vortex.startGame();
            running = false; // only lets you play once then closes
        } else if (choice == 2) {
            running = false;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}