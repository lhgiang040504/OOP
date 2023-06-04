#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int HP, ATK, DEF;
public:
    Character(string name = "", int HP = 0, int ATk = 0, int DEF = 0) :
    name(name), HP(HP), ATK(ATk), DEF(DEF) {}


};

class Guild : public Character {
private:
    int type;
public:
    Guild(string name = "", int HP = 0, int ATK = 0, int DEF = 0, int type = 0) : 
    Character(name,HP,ATK, DEF), type(type) {}

    void boot_stength() {
        
    }
}