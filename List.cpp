#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void storeinfo();
void printinfo();

int main()
{
    cout << "Welcome to the basic task list: " << endl << endl;
    int option;

    cout << "Enter option 1 to look at the list and option 2 for setting a new task, Press 0 to end task!" << endl;
system("cls");

    do
    {
        cout << "Enter option: " << endl;
        cin >> option;

        if (option == 1)
        {
            printinfo();
        }
        else if (option == 2)
        {
            storeinfo();
        }
        else if (option != 0)
        {
            cout << "The input was wrong, enter the correct number!" << endl;
        }
    } while (option != 0);

    return 0;
}

void storeinfo(){
    ofstream file("read.txt", ios::app);
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }

    string entry;
    cout << "Enter the task: " << endl;
    cin.ignore();
    getline(cin, entry);

    file << entry << endl;
    file.close();
}

void printinfo(){
    ifstream ffile("read.txt");
    if (!ffile.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }

    string output;
    int i = 1;
    while (getline(ffile, output))
    {
        cout << i << ") " << output << endl;
        i++;
    }

    ffile.close();
}
