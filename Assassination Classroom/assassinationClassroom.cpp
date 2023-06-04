#include <bits/stdc++.h>
using namespace std;

class School {
private:
    string name;
public:
    School(string name = "") : name(name) {}

    virtual void displayInfo() {
        cout << "Ten: " << name;
    }
};

class Teacher : public School {
protected:
    int expYear;
public:
    Teacher(string name = "", int expYear = 0) : School(name), expYear(expYear) {}
    
    virtual int getSalary() = 0;
};

class Homeroom : public Teacher {
private:
    string homeroomName;
public:
    Homeroom(string name = "", int expYear = 0, string homeroomName = "") : Teacher(name, expYear), homeroomName(homeroomName) {}

    int getSalary() override { return expYear * 2000000 + 1000000;  }
};

class subjectTeacher : public Teacher {
private:
    string subjectName;
public:
    subjectTeacher(string name = "", int expYear = 0, string subjectName = "") : Teacher(name, expYear), subjectName(subjectName) {}

    int getSalary() override {  return expYear * 2000000;   }
};

class Student : public School {
protected:
    string nameClass;
    int math, physic, chemistry;
public:
    Student(string name = "", string nameClass = "", int math = 0, int physic = 0, int chemistry = 0) :
    School(name), nameClass(nameClass), math(math), physic(physic), chemistry(chemistry) {}

    virtual int getRestudyMoney() = 0;
};

class Normal : public Student {
public:
    Normal(string name = "", string nameClass = "", int math = 0, int physic = 0, int chemistry = 0) : 
    Student(name, nameClass, math, physic, chemistry) {}

    int getRestudyMoney() {
        int re_studyMoney = 0;
        if (math < 5)       re_studyMoney += 1000000;
        if (physic < 5)     re_studyMoney += 1000000;
        if (chemistry < 5)  re_studyMoney += 1000000;
        return re_studyMoney;
    }
};

class Special : public Student {
public:
    Special(string name = "", string nameClass = "", int math = 0, int physic = 0, int chemistry = 0) : 
    Student(name, nameClass, math, physic, chemistry) {}

    int getRestudyMoney() { return 0;   }
};

int main() {
    int m;
    cin >> m;
    vector<Teacher*> teacher(m);
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            string name, homeroomName;
            int expYear;
            cin >> name >> expYear >> homeroomName;
            teacher[i] = new Homeroom(name, expYear, homeroomName);
        }
        else {
            string name, subjectName;
            int expYear;
            cin >> name >> expYear >> subjectName;
            teacher[i] = new subjectTeacher(name, expYear, subjectName);
        }
    }

    int n;
    cin >> n;
    vector<Student*> student(n);
    for (int i = 0; i < n; i++) {
        string name, homeroomName, classroomName;
        int type, math, physic, chemistry;
        cin >> type >> name >> classroomName >> math >> physic >> chemistry;
        if (type == 1) 
            student[i] = new Normal(name, classroomName, math, physic, chemistry);
        else
            student[i] = new Special(name, classroomName, math, physic, chemistry);
    }

}


