#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "man.h"

class Database
{
    public:
        Database();
        ~Database();
        void start();
        void end();
        void display();
        void add(Man m1);
        vector<Man> getData();
        void setData(vector<Man> v);
        void sortName();
        void sortBirthYear();
        void sortDeathYear();
        vector<Man> searchName(string name);
        vector<Man> searchBirth(int year);
        vector<Man> searchDeath(int year);
        vector<Man> searchGender(char gender);
    private:
        vector<Man> data;
};
bool sortByName(const Man& m1, const Man& m2);
bool sortByBirthYear(const Man& m1, const Man& m2);
bool sortByDeathYear(const Man& m1, const Man& m2);
ostream& operator << (ostream& os, vector<Man> vm1);
#endif // DATABASE_H
