#include <iostream>
using namespace std;

class Point{
private:
    float hori, verti;
public:
    Point(float h = 0.0, float v = 0.0) : hori(h), verti(v) {}
    float getHori() { return hori; }
    float getVerti() { return verti; }
    void setHori(float h) { hori = h; }
    void setVerti(float v) { verti = v; }

    friend istream& operator >> (istream& in, Point &p){
        return in >> p.hori >> p.verti;
    }

    friend ostream& operator << (ostream& out, Point p){
        return out << p.hori << ", " << p.verti << endl;
    }

    void translation(float dx, float dy) {
        hori += dx;
        verti += dy;
    }
};

int main() {
    Point p1, p2;
    cin >> p1 >> p2;
    p1.translation(p2.getHori(), p2.getVerti());
    cout << p1 << endl;
    return 0;
}



