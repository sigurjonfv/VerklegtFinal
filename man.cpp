#include "man.h"


Man::Man()
{
    //cout << "Man constructed." << endl;
    name = "";
    gender = 'n';
    birthyear = 0;
    deathyear = 0;
}
Man::Man(string na, char gen, int byear, int dyear)
{
    //cout << "Man constructed." << endl;
    name = na;
    gender = gen;
    birthyear = byear;
    deathyear = dyear;
}
bool Man::validate()
{
    if(deathyear - birthyear > 110 || birthyear > deathyear) return false;
    if(gender != 'M' && gender != 'F') return false;
    name[0] = toupper(name[0]);
    return true;
}

ofstream& operator << (ofstream& os, Man& m1)
{
    os  << m1.name << "*"
        << m1.gender    << " "
        << m1.birthyear << " "
        << m1.deathyear << endl;

    return os;
}
ifstream& operator >> (ifstream& is, Man& m1)
{
    char schar = '*';
    getline(is, m1.name, schar);
    is >> m1.gender;
    is >> m1.birthyear;
    is >> m1.deathyear;

    return is;
}
ostream& operator << (ostream& os, Man& m1)
{
    os  << setw(25) << left << m1.name
        << setw(8) << m1.gender
        << setw(6) << m1.birthyear
        << setw(6) << m1.deathyear << endl;

    return os;
}
istream& operator >> (istream& is, Man& m1)
{
    cout << "Name: ";
    cin.ignore(256, '\n');
    getline(is, m1.name);
    cout << "Gender(M/F): ";
    is >> m1.gender;
    cout << "Year of birth: ";
    is >> m1.birthyear;
    cout << "Year of death: ";
    is >> m1.deathyear;

    return is;
}
string Man::getName() const
{
    return name;
}
int Man::getBirthYear() const
{
    return birthyear;
}
int Man::getDeathYear() const
{
    return deathyear;
}

char Man::getGender() const
{
    return gender;
}
