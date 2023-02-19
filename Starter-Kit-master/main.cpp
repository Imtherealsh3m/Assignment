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
#include <map>
#include <fstream>
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
    void init (int dimR, int dimC, int z);
    void displayBoard(int dimR, int dimC);
    void locateAlien(int &dimR, int &dimC, int &row, int &col);
    void changeTrail(int &dimR, int &dimC);
    void moveUp(int &dimR, int &dimC);
    void moveDown(int &dimR, int &dimC);
    void moveRight(int &dimR, int &dimC);
    void moveLeft(int &dimR, int &dimC);
    
};

struct Zombie {
    int health ;
    int damage ;
    int range;
    int x;
    int y;
    int number;
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

void Gameboard::init(int dimC, int dimR, int z)
{
  vector<pair<int, int>> occupiedCells;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'r', 'p', 'h', '^', '>', '<', 'v'};
    int noOfObjects = 14; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimR); // create empty rows

    for (int i = 0; i < dimR ; ++i)
    {
        map_[i].resize(dimC); // resize each row
    }

    int centerX = dimC/2;
    int centerY = dimR/2;
    map_[centerY][centerX] = 'A';
    // put random characters into the vector array
    for (int i = 0; i < dimR; ++i)
    {
        for (int j = 0; j < dimC; ++j)
        {
          if (i == centerY && j == centerX) {
            continue; // skip 'A' cell
        }
          int objNo = rand() % noOfObjects;
          map_[i][j] = objects[objNo];
        }
    }

    //Zombie zombies[zombieIndex]; // Select zombie from th array of zombie
    Zombie zombies[z];

    for (int i = 0; i < z; i++) { //Assign Zombie position
    int x = rand() % dimC;
    int y = rand() % dimR;
    zombies[i].x = x;
    zombies[i].y = y;

    // check if new random position is already occupied
    bool isOccupied = false;
    for (auto coord : occupiedCells) {
        if ((coord.first == x && coord.second == y) || (centerY == y && centerX == x)) {
            isOccupied = true;
            break;
        }
    }
    // if new random position is already occupied, generate a new random position
    while (isOccupied) {
        x = rand() % dimC;
        y = rand() % dimR;

        isOccupied = false;
        for (auto coord : occupiedCells) {
            if (coord.first == x && coord.second == y) {
                isOccupied = true;
                break;
            }
        }
    }
    // add new occupied cell coordinates to vector
    occupiedCells.push_back({x, y});
    zombies[i].number = i + 1;
    map_[y][x] = '0' + zombies[i].number;
}
}

void Gameboard::displayBoard(int dimR, int dimC) //to display board
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

void Gameboard::locateAlien(int &dimR, int &dimC, int &row, int &col)
{
  for (int i = 0; i < dimR; i++) {
    for (int j = 0; j < dimC; j++) {
      if (map_[i][j] == 'A') {
        row = i;
        col = j;
        return;
      }
    }
  }
}

void Gameboard::changeTrail(int &dimR, int &dimC) {
    char objects[] = {' ', ' ', ' ', 'r', 'p', 'h', '^', '>', '<', 'v'};
    int noOfObjects = sizeof(objects) / sizeof(objects[0]);

    // Find and change all the trails left by the alien
    while (true) {
        int trailRow = -1, trailCol = -1;

        // Find the location of the next trail ('.') left by the alien
        for (int i = 0; i < dimR; i++) {
            for (int j = 0; j < dimC; j++) {
                if (map_[i][j] == '.') {
                    trailRow = i;
                    trailCol = j;
                    break;
                }
            }
            if (trailRow != -1 && trailCol != -1) {
                break;
            }
        }

        // If no more trail is found, break the loop
        if (trailRow == -1 || trailCol == -1) {
            break;
        }

        // Change the trail to a random object from the objects array
        int objNo = rand() % noOfObjects;
        map_[trailRow][trailCol] = objects[objNo];
    }
}

void Gameboard::moveUp(int &dimR, int &dimC)
{
  Settings sett;
  int row, col;
  locateAlien(dimR, dimC, row, col);

  while (row > 0) {
    map_[row][col] = '.';
    row--;
    map_[row][col] = 'A';
    displayBoard(dimR, dimC);
    sett.CScreen();
  }
  changeTrail(dimR, dimC);
}

void Gameboard::moveDown(int &dimR, int &dimC)
{
  Settings sett;
  int row, col;
  locateAlien(dimR, dimC, row, col);

    while (row + 1 < dimR){
    map_[row][col] = '.';
    row++;
    map_[row][col] = 'A';
    displayBoard(dimR, dimC);
    sett.CScreen();
    }
    changeTrail(dimR, dimC);
}

void Gameboard::moveRight(int &dimR, int &dimC)
{
  Settings sett;
    int row, col;
    locateAlien(dimR, dimC, row, col);

    while (col + 1 < dimC){
    map_[row][col] = '.';
    col++;
    map_[row ][col] = 'A';
    displayBoard(dimR, dimC);
    sett.CScreen();
    }
    changeTrail(dimR, dimC);
}

void Gameboard::moveLeft(int &dimR, int &dimC)
{
    Settings sett;
    int row, col;
    locateAlien(dimR, dimC, row, col);

    while (col > 0){
    map_[row][col] = '.';
    col--;
    map_[row ][col] = 'A';
    displayBoard(dimR, dimC);
    sett.CScreen();
    }
    changeTrail(dimR, dimC);
}

void displayZombieAttributes(Zombie zombies[], int numZombies) {
    for (int i = 0; i < numZombies; i++) {
        std::cout << "Zombie " << i+1 << " :- " << "  Health: " << zombies[i].health << "  Damage: " << zombies[i].damage  << "  Range: " << zombies[i].range << std::endl;
        std::cout << std::endl;
    }
}
void move(int numRows, int numColumn)
{
    char choice;
    Settings settings;
    Gameboard gameboard;
		bool fin = false;

    do
    {
    cout << "Enter w , a , s, d to move: ";
    cin >> choice;
    settings.CScreen();
        switch (choice)
        {
            case 'w':
            gameboard.moveUp(numRows,numColumn);
            gameboard.displayBoard(numRows, numColumn);
            break;

            case 's':
            gameboard.moveDown(numRows, numColumn);
            gameboard.displayBoard(numRows, numColumn);
            break;

            case 'd':
            gameboard.moveRight(numRows, numColumn);
            gameboard.displayBoard(numRows, numColumn);
            break;

            case 'a':
            gameboard.moveLeft(numRows, numColumn);
            gameboard.displayBoard(numRows, numColumn);
            break;

            /*case 'c':
            gameboard.change(numRows, numColumn);
            break;*/

            case 'q':
            fin = true;
            break;
        }
    }
    while(!fin);
}


int test()
{
    Settings settings;
    Gameboard gameboard;
    bool fin= false;
    cout << endl;
    cout << "      Alien VS Zombies" << endl;
    cout << "'Protect urself from zombies!'" << endl;
    cout << endl;
    settings.CScreen();

    char choice;
    bool done = false;
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
    Zombie zombies[numZombie];
    for (int i = 0; i < numZombie; i++) {
    zombies[i].health = (20 + (rand() % 11)) / 5 * 5 * 10;
    zombies[i].damage = (2 + (rand() % 4)) / 2 * 5;
    zombies[i].range = 1 + (rand() % 3);
    }
    gameboard.init(numColumn,numRows, numZombie);
    gameboard.displayBoard(numRows, numColumn);
    cout << endl;
    cout << "Alien :-  HP =" << alienhp << "\t"<< "Damage =" << aliendamage << endl;
    displayZombieAttributes(zombies, numZombie);
    bool playerTurn = true;
    do
    {
   if (playerTurn){
    cout << "-->Please type 'h' for more available commands<--" << endl;
    cout << "Type w , a , s , d to move"<< endl;
    cout << "Command> ";
    cin >> choice;
    settings.CScreen();
      switch (choice)
      {
          case 'w':
          gameboard.moveUp(numRows,numColumn);
          break;

          case 's':
          gameboard.moveDown(numRows, numColumn);
          break;

          case 'd':
          gameboard.moveRight(numRows, numColumn);
          break;

          case 'a':
          gameboard.moveLeft(numRows, numColumn);
          break;

          case 'h':
          

          case 'q':
          fin = true;
          break;
      }
      gameboard.displayBoard(numRows, numColumn);
      cout << "Alien :-  HP =" << alienhp << "\t"<< "Damage =" << aliendamage << endl;
      displayZombieAttributes(zombies, numZombie);
      playerTurn = false;
      }
      else
      {
        cout << "Zombies turn!" << endl;
        settings.CScreen();
        gameboard.displayBoard(numRows, numColumn);
        cout << "Alien :-  HP =" << alienhp << "\t"<< "Damage =" << aliendamage << endl;
        displayZombieAttributes(zombies, numZombie);
        playerTurn = true;
      }
    } while (!fin);
      cout << endl;
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
