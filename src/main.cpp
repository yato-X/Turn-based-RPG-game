#include <iostream>
using namespace std;

class Enemy{
    private:
        string name;
        int health;
        int atkpower;
    public:
        Enemy(string name, int hp, int atk){
        name = name;
        health = hp;
        atkpower = atk;
        }
    int getHealth(){
        return health;
    }
    int getatkPower(){
        return atkpower;
    }
    string getname(){
        return name;
    }
    bool isalive(){
        return health > 0;
    }
    void damage(int dmg){
        health = health - dmg;
        if(health<0){
            health = 0;
        }
    }
    void stats(){
        cout<<name<<"(hp:)"<<health<<endl;
        cout<<"Attack Power:"<<atkpower<<endl;
    }
};
class Goblin: public Enemy{
    public:
        Goblin(): Enemy("Goblin", 30, 5){}
};
class Character {
protected:                      // PROTECTED, not private:
    string name;                 // subclasses (Warrior/Mage/Assassin) need
    int health;                  // direct access to these in their own
    int attackPower;             // attack() implementations. Outside code
                                  // still cannot touch them directly.
public:
    Character(string n, int hp, int atk) {
        name = n;
        health = hp;
        attackPower = atk;
    }
 
    int getHealth() {
        return health;
    }
 
    string getName() {
        return name;
    }
 
    bool isAlive() {
        return health > 0;
    }
 
    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) {
            health = 0;
        }
    }
 
    void displayStats() {
        cout << name << " | HP: " << health
             << " | ATK: " << attackPower << endl;

class Character{
    private:
        string name;
        int health;
        int atkpower;

    public:
        Character(string n, int hp, int atkpower);
        

};
void showMenu(){
    cout<<"Menu"<<endl;
    cout<<"\n"<<endl;
    cout<<"1. Start Game"<<endl;
    cout<<"2. Exit"<<endl;
    cout<<"Choose an option: "; 
}

int main(){
    bool running(true);
    while(running){
        showMenu();
    

    int choice;
    cin>> choice;
    cout<<"you chose:"<<choice<<endl;
    
    switch(choice){
        case 1:
            //startgame();
            break;
        case 2:
            running = false;
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
    }

return 0;

}

}
