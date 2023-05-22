#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Birth {
private:
    int day, month, year;
public:
    Birth(int d = 1, int m = 1, int y = 1) : day(d), month(m), year(y) {}
    
    friend istream& operator >> (istream &in, Birth &b) {
        return in >> b.day >> b.month >> b.year;
    }
    friend ostream& operator << (ostream &out, Birth b) {
        out << setfill('0');
        out << setw(20) << b.day << " / " << setw(2) << b.month << " / " << b.year;
        return out;
    }
};
class Score {
private:
    float math, liter, english;
public:
    Score(float m = 0, float l = 0, float e = 0) : math(m), liter(l), english(e) {}

    friend istream& operator >> (istream &in, Score &s) {
        return in >> s.math >> s.liter >> s.english;
    }
    friend ostream& operator << (ostream &out, Score s) {
        out << s.math << " - " << s.liter << " - " << s.english;
        return out;
    }
};

class Candidate {
private:
    char id[10];
    char name[20];  
    Birth birth;
    Score score;
public:
    Candidate(char id1[] = ".", char name1[] = ".", Birth b1 = Birth(), Score s1 = Score()) : id(id1), name(name1), birth(b1), score(s1) {}

    friend istream& operator >> (istream &in, Candidate &candi) {
        in.getline(candi.id, 10);
        in.getline(candi.name, 20, "\n");
        in >> candi.birth >> candi.score;
        return in;
    }
    friend ostream& operator << (ostream &out, Candidate candi) {
        out << setw(10) << candi.id << setw(20) << candi.name << setw(15) << candi.birth << setw(15) candi.score;
        return out;
    }
};

int main() {
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    cin.ignore();  // clear input buffer
    
    Candidate candidates[n];
    
    for (int i = 0; i < n; i++)
        cin >> candidates[i]

    for (int i = 0; i < n; i++)
        cout << candidates[i];

    return 0;
}