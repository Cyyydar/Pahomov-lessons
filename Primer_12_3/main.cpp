#include <iostream>

using namespace std;

class Student{
    string FIO;
    string group;
    int birthYear;

    public:
        void setFIO(string s) { FIO = s;}
        void setGroup(string s) {group = s;}
        void setBirthYear(int a) {birthYear = a;}
        string getFIO() {return FIO;}
        string getGruop() {return group;}
        int getBirthYear() {return birthYear;}
};

int main()
{
    Student st1;
    st1.setFIO("Ivanov I.I.");
    st1.setGroup("205B-21");
    st1.setBirthYear(648);

    cout << st1.getFIO() << endl;
    cout << st1.getGruop() << endl;
    cout << st1.getBirthYear() << endl;
    return 0;
}
