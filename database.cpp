#include "database.h"

Database::Database()
{

}

Database::~Database()
{

}
vector<Man> Database::getData()
{
    return data;
}
void Database::start()
{
    ifstream datafile;
    datafile.open("data.txt");
    string name;
    char tgen;
    int tbyear;
    int tdyear;
    while(!datafile.eof())
    {
        // inputs
        char schar = '*';
        if(!getline(datafile, name, schar)) break;
        datafile >> tgen;
        datafile >> tbyear;
        datafile >> tdyear;
        datafile.ignore(1);
        Man temp = Man(name,tgen,tbyear,tdyear);
        data.push_back(temp);
    }
    datafile.close();
}
void Database::end()
{
    ofstream datafile;
    datafile.open("data.txt");
    for(unsigned int i = 0; i < data.size(); i++)
    {
        datafile << data[i];
    }
    datafile.close();
}

void Database::setData(vector<Man> v)
{
    data = v;
}
void Database::display()
{
    cout << data;
}
void Database::add(Man m1)
{
    data.push_back(m1);
}
void Database::sortName()
{
    sort(data.begin(), data.end(), sortByName);
}
void Database::sortBirthYear()
{
    sort(data.begin(), data.end(), sortByBirthYear);
}
void Database::sortDeathYear()
{
    sort(data.begin(), data.end(), sortByDeathYear);
}
bool sortByName(const Man& m1, const Man& m2)
{
    return m1.getName() < m2.getName();
}
bool sortByBirthYear(const Man& m1, const Man& m2)
{
    return m1.getBirthYear() < m2.getBirthYear();
}
bool sortByDeathYear(const Man& m1, const Man& m2)
{
    return m1.getBirthYear() < m2.getBirthYear();
}

ostream& operator << (ostream& os, vector<Man> vm1)
{
    os << left << setw(25) << "Name" << setw(8) << "Gender" << setw(6) << "Born"
         << "Dead" << endl;
    for(int i = 0; i < 43; i++)
    {
        os << "-";
    }
    cout << endl;
    for(unsigned int i = 0; i < vm1.size(); i++)
    {
        os << vm1[i];
    }
    os << endl;
    return os;
}

vector<Man> Database::searchName(string name){

    vector<Man> nameVector;

        for(unsigned int i = 0; i < data.size(); i++){
            if( data[i].getName().find(name) != string::npos)
            {
                nameVector.push_back(data[i]);
            }

        }
    return nameVector;
}

vector<Man> Database::searchBirth(int year){

    vector<Man> yearVector;
        for(unsigned int i = 0; i < data.size(); i++){
            if(data[i].getBirthYear() == year){
                yearVector.push_back(data[i]);
            }

        }
    return yearVector;
}

vector<Man> Database::searchDeath(int year){

    vector<Man> yearVector;
    for(unsigned int i = 0; i < data.size(); i++){
        if(data[i].getDeathYear() == year){
            yearVector.push_back(data[i]);
        }
    }
    return yearVector;
}

vector<Man> Database::searchGender(char gender){

    vector<Man> genderVector;
        for(unsigned int i = 0; i < data.size(); i++){
            if(data[i].getGender() == gender){
                genderVector.push_back(data[i]);
            }

        }
    return genderVector;
}
