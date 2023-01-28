// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT5L 
// Names: HONG YOONG SHEM | NURUL BALQIS BINTI RIDZUWAN | YONG QI XIANG
// IDs: 1201103427 | 1221303291 | 1221303302  
// Emails: 1201103427@student.mmu.edu.my | 1221303291@student.mmu.edu.my | 1221303302@student.mmu.edu.my 
// Phones: 012-5943639 |  011-60733438 | 011-10882869 
// ********************************************************* 

#include "pf/helper.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
using namespace std;

class Settings
{
    public:
    int numRows,  numColumn, numZombie;
    void displayOption(int numRows, int numColumn, int numZombie);
    void changeData(int &numRows, int &numColumn, int &numZombie);
    void CScreen();
}; 

class Gameboard
{
    private:
    vector< vector<char> > map_; 
 //   int dimR_, dimC_;  r = rows, c = column, 

    public:
    void init (int dimR, int dimC);
    void displayBoard(int dimR, int dimC) const;
    
};


void Settings::displayOption(int numRows, int numColumn, int numZombie) //display settings
{
    cout << "===================" << endl; 
    cout << "  Default Setting  " << endl;
    cout << "===================" << endl << endl;
    cout << "Board Setting " << endl;
    cout << "--------------------" << endl;
    cout << "Rows => " << numRows << endl;
    cout << "Column => " << numColumn << endl << endl;
    cout << "Zombie Setting" << endl;
    cout << "--------------------" << endl;
    cout << "Zombie => " << numZombie << endl << endl;
    cout << "Do you wish to change the option? (y/n)" << endl << endl;
}

void Settings::changeData(int &numRows, int &numColumn, int &numZombie) //change settings
{
    cout << "Accepted Values : - " << endl;
    cout << "Rows : 3 - 5" << "\t" << "Column : 3 - 19" << "\t" << "Zombie : 1 - 9" << endl << endl;
    cout << "====================" << endl;    
    cout << "Customize Setting"    << endl;
    cout << "====================" << endl << endl;
    cout << "Board Setting " << endl;
    cout << "--------------------" << endl;
    cout << "Please enter odd numbers only!" << endl ;
    cout << endl;
    cout << "New Rows => "; cin >> numRows;
    cout << "New Column => "; cin >> numColumn;
    cout << endl; 
    if (numRows % 2 == 0 || numColumn % 2 == 0) //odd numbers only
    {
        while (numRows % 2 == 0 || numColumn % 2 == 0)
        {
            cout  << "Invalid numbers. Please try again!" << endl;
            CScreen();
            cout << "Accepted Values : - " << endl;
            cout << "Rows : 3 - 5" << "\t" << "Column : 3 - 19" << "\t" << "Zombie : 1 - 9" << endl << endl;
            cout << "====================" << endl;    
            cout << "Customize Setting"    << endl;
            cout << "====================" << endl << endl;
            cout << "Board Setting " << endl;
            cout << "--------------------" << endl;
            cout << "Please enter odd numbers only!" << endl << endl;
            cout << "New Rows => "; cin >> numRows;
            cout << "New Column => "; cin >> numColumn;
            cout << endl; 
        }
    }
    cout << "Zombie Setting" << endl;
    cout << "--------------------" << endl;
    cout << "New num of Zombie => "; cin >> numZombie;
    cout << endl; 
    if (numRows < 3 || numRows > 5 || numColumn < 3 || numColumn > 19 || numZombie < 1 || numZombie > 9)//limits
    {
        while (numRows < 3 || numRows > 5 || numColumn < 3 || numColumn > 19 || numZombie < 1 || numZombie > 9)
        {
        CScreen();
        cout << "Values not accepted. Gameboard cannot generate. Please try again." << endl << endl;
        cout << "Accepted Values : - " << endl;
        cout << "Rows : 3 - 5" << "\t" << "Column : 3 - 19" << "\t" << "Zombie : 1 - 9" << endl << endl;
        cout << "====================" << endl;    
        cout << "Customize Setting"    << endl;
        cout << "====================" << endl << endl;
        cout << "Board Setting " << endl;
        cout << "--------------------" << endl;
        cout << "Please enter odd numbers only!" << endl << endl;
        cout << "New Rows => "; cin >> numRows;
        cout << "New Column => "; cin >> numColumn;
        cout << endl; 
        if (numRows % 2 == 0 || numColumn % 2 == 0) //odd numbers only
        {
            while (numRows % 2 == 0 || numColumn % 2 == 0)
            {
                cout  << "Invalid numbers. Please try again!" << endl;
                CScreen();
                cout << "Values not accepted. Gameboard cannot generate. Please try again." << endl << endl;
                cout << "Accepted Values : - " << endl;
                cout << "Rows : 3 - 5" << "\t" << "Column : 3 - 19" << "\t" << "Zombie : 1 - 9" << endl << endl;
                cout << "====================" << endl;    
                cout << "Customize Setting"    << endl;
                cout << "====================" << endl << endl;
                cout << "Board Setting " << endl;
                cout << "--------------------" << endl;
                cout << "Please enter odd numbers only!" << endl << endl;
                cout << "New Rows => "; cin >> numRows;
                cout << "New Column => "; cin >> numColumn;
                cout << endl; 
            }
        }
        cout << "Zombie Setting" << endl;
        cout << "--------------------" << endl;
        cout << "New num of Zombie => "; cin >> numZombie;
        cout << endl; 
        }
    }
    cout << "Settings updated!" << endl << endl;
}



void Settings::CScreen()//clear screen
{
    pf::Pause();
    pf::ClearScreen();
    cout << endl;
}

void Gameboard::init(int dimC, int dimR)
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'r', 'p', 'h', '^', '>', '<', 'v'};
    int noOfObjects = 14; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimR); // create empty rows

    for (int i = 0; i < dimR ; ++i)
    {
        map_[i].resize(dimC); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimR; ++i)
    {
        for (int j = 0; j < dimC; ++j)
        {
            int objNo = rand() % noOfObjects;
            int centerX = dimC/2;
            int centerY = dimR/2;

            map_[centerY][centerX] = 'A';
            map_[i][j] = objects[objNo];
        }
    }
}
void Gameboard::displayBoard(int dimR, int dimC) const//to display board
{
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " =       Alien Vs Zombie       =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    cout << endl;

    for (int i = 0; i < dimR; ++i)      // for each row  
    {
        cout << " ";                       // display upper border of the row
        for (int j = 0; j < dimC; ++j)  
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(0) << (dimR - i);  // display row number
       for (int j = 0; j < dimC; ++j)  // display cell content and border of each column
        {
            cout << "|" << map_[i][j];  
        }
        cout << "|" << endl;
    }

  
    cout << " ";                        // display lower border of the last row
    for (int j = 0; j < dimC ; ++j)
    {
        cout << "+-";
    }
    
    cout << "+" << endl;
    cout << " ";                       // display column number
    for (int j = 0; j < dimC; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    
    cout << endl;
    cout << " ";
    for (int j = 0; j < dimC; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl << endl;
}

int test()
{
    Settings settings;
    Gameboard gameboard;
    cout << endl;
    cout << "      Alien VS Zombies" << endl;
    cout << "'Protect urself from zombies!'" << endl;
    cout << endl;
    settings.CScreen();

    char choice;
    bool done = false;
    string zombiesName[] = {"Zombie1", "Zombie2", "Zombie3", "Zombie4", "Zombie5", "Zombie6", "Zombie7", "Zombie8", "Zombie9"};
    int alienhp = 100;   // Alien Hp
    int aliendamage = 0; // Alien Damage
    int numRows = 5, numColumn = 9 , numZombie = 1 ;
    do
    {
        settings.displayOption(numRows, numColumn, numZombie);
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
        
        settings.CScreen();

        switch (choice)
        {
            case 'Y':
            settings.changeData(numRows, numColumn, numZombie);
            settings.CScreen();
            break;

            case 'N':
            done = true;
            break;

            default:
            cout << "Invalid selection, try again!" << endl;
            cout << endl;
            break;
        }
    }   
    while (!done);
        cout << endl;
    cout << "Game Loading..." << endl;
    cout << endl;
    settings.CScreen();
    srand(time(NULL));
    gameboard.init(numColumn,numRows);
    gameboard.displayBoard(numRows, numColumn);
    cout << endl;  
    cout << "Alien Hp =" << alienhp << "\t"<< "Player Damage =" << aliendamage << endl;
    for (int i = 0; i < numZombie ; i++)
    {
    int zombieshp = 100 + (rand() % 50);
    int zombiedamage = 10 + (rand() % 20);
    int zombiesattackrange = 1 + (rand() % 3);
    cout << zombiesName[i]<<endl;
    cout << "Zombie Hp =" << zombieshp << "\t"<< "Zombie Damage =" <<zombiedamage << "\t"<< "Zombie Attack Range =" << zombiesattackrange<<endl;
    }
    return 0;

}


int main()
{
    //Main Menu
    int choice;
    

    do
    {
        cout << "-----------------------" << endl;
        cout << "==> Alien VS Zombie <==" << endl;
        cout << "-----------------------" << endl; 
        cout << endl;

        cout << "[1] New Game " << endl;
        cout << "[2] Load Game " << endl;
        cout << "[3] Quit " << endl;
        cout << endl;

        cout << "Please enter a number: ";
        cin >> choice; 
        

        switch(choice)
        {
            case 1:
                test();   
                return 0;

            case 2:
                cout <<"test"<< endl;
                cout << endl;
                break;

            case 3:
                cout << "See u next time! " << endl;
                break;
            
            default:
                cout << "Oops! Please enter the available number!" << endl;
                cout << endl; 
                break;
        }
    }
    while(choice !=3);
}

