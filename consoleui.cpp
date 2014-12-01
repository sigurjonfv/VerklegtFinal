#include "consoleui.h"

ConsoleUI::ConsoleUI()
{

}
void ConsoleUI::start()
{
    s = Services();
    s.start();
    int cont = 1;
    do{
        cont = SwitchMainMenu();
    }while(cont != 0);
}
void ConsoleUI::end()
{
    s.end();
}

void ConsoleUI::ShowMainMenu()
{
    system("CLS");
    //  Write from a file to cout
    ifstream menu ("MainMenu.h22");
    cout << menu.rdbuf() << endl << "\t: ";
    menu.close();
}
int ConsoleUI::SwitchMainMenu()
{
    ShowMainMenu();
    char option;
    cin >> option;
    switch (option)
    {
        case '1':{
            Man tempMan;
            cin >> tempMan;
            if(tempMan.validate())
            {
                cout << tempMan.getName() << " was successfully added to the database." << endl;
                s.add(tempMan);
            }
            else
                cout << "Your input was not correct" << endl;
            break;
        }
        case '2':{
            s.display();
            break;
        }
        case '3':{
            SwitchSearchMenu();
            break;
        }
        case '0':{
            cout << "Have a nice day!" << endl;
            return 0;
        }
        default:{
             cout << "Invalid input\n";
             break;
        }
    }
    system("pause");
    return 1;
}
void ConsoleUI::ShowSearchMenu ()
{
    system("CLS");
    //  Write from a file to cout
    ifstream menu ("Search.h22");
    cout << menu.rdbuf() << endl << "\t: ";
}
void ConsoleUI::SwitchSearchMenu()
{
    ShowSearchMenu();

    char option;
    cin >> option;

    string name;
    char gen;
    int year;
    vector<Man> results;

    switch(option){
        case '1':
            cout << "Name: ";
            cin >> name;
            results = s.nameSearch(name);
            break;
        case '2':
            cout << "Gender(M/F): ";
            cin >> gen;
            //results = s.genderSearch(gen);
            break;
        case '3':
            cout << "Year of birth: ";
            cin >> year;
            results = s.yearSearch(3, year);
            break;
        case '4':
            cout << "Year of death: ";
            cin >> year;
            results = s.yearSearch(4, year);
            break;
        case '0':
            return;
        default:
            cout << "Invalid input\n";
            break;
    }
    if(results.size() > 0)
        cout << results;
    else
        cout << endl << "No results." << endl;
}


