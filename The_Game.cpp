#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class player
{
    public:
    string name;
    int id;

//  initalising the player 
    player()
    {
        name = "";
        id = 0;
    }
    player(string name, int n)
    {
        this->name = name;
        id = n;
    }

//  display all the attributes 
    void display()
    {
        cout << "   Player attributes   ";
        cout << "Name: " << name<< endl;
        cout << "Player ID: " << id << endl;
    }
};
class character
{
    public: 
    string name;
    vector<int> pos;
// Initialising the character 
    character(string st, vector<int> pos)
    {
        string name = st;
        this->pos = pos;
    }

//  Display all the attributes
    void display()
    {
        cout << "   character attributes   ";
        cout << "Name: " << name;
        cout << "position (x,y): (" << pos[0] << "," << pos[1] << ")" << endl;
    }
};

class board
{
    public:
    vector<vector<int>> grid;
    vector<player> player_onboard;
    int row = 5;
    int column = 5;


//  Commands 
    enum cmd {
            L = -1,
            R = 1,
            F = 1,
            B = -1
            };
    void cmd_list()
    {
        cout<< "L : left" << endl;
        cout<< "R : right" << endl;
        cout<< "F : forward" << endl;
        cout<< "B : backward" << endl;
    }

// Initalising the board
    board()
    {
        for(int i =0; i<row; i++)
        {
            vector<int> temp;
            for(int j=0; j<column; j++)
            {
                temp.push_back(0);
            }
            grid.push_back(temp);
        } 
    }

    board(player p1, player p2)
    {
        player_onboard = {p1,p2};
        for(int i =0; i<row; i++)
        {
            vector<int> temp;
            for(int j=0; j<column; j++)
            {
                temp.push_back(0);
            }
            grid.push_back(temp);
        } 
    }

// Displaying the current state of the board
    void display()
    {
        for(int i = 0; i<row; i++)
        {
            for (int j=0; j<column ; j++)
            cout << grid[i][j] << "     ";
            cout << endl;
        }
    }
};

int main()
{
    player p1("A",1), p2("B",2);
    board b(p1,p2);
    b.display();
    return 0;
}