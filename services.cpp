#include "services.h"

Services::Services()
{

}
Services::~Services()
{

}
void Services::start()
{
    d = Database();
    d.start();
}
void Services::end()
{
    d.end();
}

void Services::display()
{
    d.display();
}
void Services::add(Man m1)
{
    d.add(m1);
}
void Services::sort(char choice)
{
    switch(choice)
    {
        case '1': {d.sortName(); break;}
        case '2': {d.sortBirthYear(); break;}
        case '3': {d.sortDeathYear(); break;}
    }
}

vector<Man> Services::nameSearch(string name){

    vector<Man> resultsVector;
    resultsVector = d.searchName(name);
    return resultsVector;
}

vector<Man> Services::yearSearch(char choice, int year){

    vector<Man> resultsVector;
    switch(choice)
    {
        case '3': {resultsVector = d.searchBirth(year); break;}
        case '4': {resultsVector = d.searchDeath(year); break;}
    }
    return resultsVector;
}


