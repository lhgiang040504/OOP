#include <bits/stdc++.h>
using namespace std;
class Character : public Guild {
protected:
    static int countNhan_loai, countDevil;
    float ATK, DEF, HP;
    string name;
public:
    Character(string name = "Unknow", float atk = 0.0, float def = 0.0, float hp = 0.0) :
    name(name), ATK(atk), DEF(def), HP(hp) {}

    float getHP() { return HP;  }
    bool is_Dead() { return HP <= 0;}
    void attack(Character &enemy) {
        if (ATK - enemy.DEF > 0)
            enemy.HP -= ATK - enemy.DEF;
    }
    void print_Infor() {
        cout << name << " " << HP << endl;
    }

    virtual void bootStrength() {   return ;    };
    virtual void input() {
        cin >> name >> ATK >> DEF >> HP;
    }

    Character* init(int type) {
        switch (type) {
            case 1:
                return new Human;
            case 2:
                return new Elf;
            case 3:
                return new Orc;
            case 4:
                return new Golbin;
            case 5:
                return new Vampire;
            case 6:
                return new Devil;
            return new Character;
        }
    }
};
int Character::countNhan_loai = 0;
int Character::countDevil = 0;

class Nhan_loai : public Character {
private:
    string Job;
public:
    Nhan_loai(string name = "Unknow", float atk = 0.0, float def = 0.0, float hp = 0.0, string job = "Unknow") :
    Character(name, atk, def, hp), Job(job) {}

    void input() override {
        Character::input();
        cin >> Job;
        countNhan_loai ++;
    }
};
class Human : public Nhan_loai {};
class Elf : public Nhan_loai {
public:
    void bootStrength() override {
        DEF *= 1.5;
        return;
    }
};

class Ban_nhan : public Character {
private:
    string Racial;
public:
    Ban_nhan(string name = "Unknow", float atk = 0.0, float def = 0.0, float hp = 0.0, string racial = "Unknow") :
    Character(name, atk, def, hp), Racial(racial) {}
    
    void input() override {
        Character::input();
        cin >> Racial;
    }
};
class Orc : public Ban_nhan {
public:
    void bootStrength() override {
        HP *= 1.5;
        return;
    }
};
class Golbin : public Ban_nhan {
public:
    void bootStrength() override {
        ATK *= 1.1;
        return;
    }
};

class Di_hinh : public Character {};
class Vampire : public Di_hinh {
public:
    void bootStrength() override {
        HP *= 1.1 * countNhan_loai;
        return;
    }
};
class Devil : public Di_hinh {
public:
    void input() override {
        Character::input();
        countDevil ++;
    }
    void bootStrength() override {
        HP *= 1.1 * countDevil;
        return;
    }    
};

class Boss : public Character {};
class Guild {
private:
    Character* arr[50];
    int size = 0;
public:
    void Input() {
        cin >> size;
        for (int i = 0; i < size; i++) {
            int type;
            cin >> type;
            arr[i]->init(type);
            arr[i]->input();
        }
        for (int i = 0; i < size; i++) {    arr[i]->bootStrength();    }
    }
    void Print() {
        for (int i = 0; i < size; i++) {    arr[i]->print_Infor();    }
    }
    void Round(Character* enemy) {
        for (int i = 0; i < size; i++) {    arr[i]->attack(*enemy);    }

    }
    

};