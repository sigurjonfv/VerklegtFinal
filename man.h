#ifndef MAN_H
#define MAN_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
class Man{
private:
    string name;
    char gender;
    int birthyear;
    int deathyear;
public:
    Man();
    Man(string name, char gen, int byear, int dyear);
    bool validate();
    string getName() const;
    int getBirthYear() const;
    int getDeathYear() const;
    char getGender() const;
    friend ofstream& operator << (ofstream& os, Man& m1);
    friend ifstream& operator >> (ifstream& is, Man& m1);
    friend ostream& operator << (ostream& os, Man& m1);
    friend istream& operator >> (istream& is, Man& m1);
};

#endif // MAN_H
