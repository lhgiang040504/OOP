#include <bits/stdc++.h>
using namespace std;

class Friend {
protected: // private: ??
    string name;
    int age;
public:
    Friend(string name = "", int age = 0.0) : name(name), age(age) {}

    virtual float getTimeSpent() = 0; // ??

    // inheritate overload operator
    void displayInfo() {
        cout << "Ten: " << name << ", tuoi: " << age;
    }
};

// constraints ??

class BestFriend : public Friend {
private:
    string phone;
public:
    BestFriend(string name = "", int age = 0.0, string phone = "0") : Friend(name, age), phone(phone) {}

    float getTimeSpent() { return 5.0; }

    void displayInfo() {
        Friend::displayInfo();
        cout << ", so dien thoai: " << phone;
    }

};

class BoyFriend : public Friend {
private:
    float income;
public:
     BoyFriend(string name = "", int age = 0.0, float incom = 0.0) : Friend(name, age), income(income) {}

    float getTimeSpent() { return 5 * income / 10000000.0; }

    void displayInfo() {
        Friend::displayInfo();
        cout << ", thu nhap: " << income << "d";
    }

};

class OtherBoy : public Friend {
private:
    float attractiveness;
public:
    OtherBoy(string name = "", int age = 0.0, float attractiveness = 1.0) : Friend(name, age), attractiveness(attractiveness) {}

    // ??
    float getTimeSpent(int totalFriend) override {
        return attractiveness * 20 / totalFriend;
    }

    void displayInfo() {
        Friend::displayInfo();
        string attraction;
        if (attractiveness >= 0.7) attraction = "cao";
        else if (attractiveness < 0.4) attraction = "thap";
        else attraction = "trung binh";
        cout << ", do thu hut: " << attraction;
    }
};

int main() {
    int totalFriends;
    cin >> totalFriends;
    vector<pair<int, Friend>> manage(totalFriends);
    float bestFriendTime, boyFriendTime, otherBoyTime;
    bestFriendTime = boyFriendTime = otherBoyTime = 0.0;

    for (int i = 0; i < totalFriends; i++) {
        cin >> manage[i].first;
        if (manage[i].first) {
            string name;
            int age;
            string phone;
            cin >> name >> age >> phone;
            manage[i].second = BestFriend(name, age, phone);
            bestFriendTime += manage[i].second.getTimeSpent();
        }
        else if (manage[i].first) {
            string name;
            int age;
            float income;
            cin >> name >> age >> income;
            manage[i].second = BoyFriend(name, age, income);
            boyFriendTime += manage[i].second.getTimeSpent();
        }
        else {
            string name;
            int age;
            float attractiveness;
            cin >> name >> age >> attractiveness;
            manage[i].second = OtherBoy(name, age, attractiveness);
            otherBoyTime += manage[i].second.getTimeSpent(totalFriends);
        }
    }
    
    cout << "Thong ke:\n";
    cout << "- Thoi gian cho ban than: " << bestFriendTime << " h\n";
    cout << "- Thoi gian cho ban trai: " << boyFriendTime << " h\n";
    cout << "- Thoi gian cho ban trai khac: " << otherBoyTime << " h\n";


    cout << "Nguoi ban quan trong nhat:\n";
    
    sort(manage.begin(), manage.end(), greater<int>());
    Friend specialOne = manage[0].second;
    cout << specialOne;
    return 0;

}
